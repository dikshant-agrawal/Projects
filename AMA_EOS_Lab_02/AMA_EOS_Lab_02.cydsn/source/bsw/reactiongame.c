/**
* \file <filename>
* \author <author-name>
* \date <date>
*
* \brief <Symbolic File name>
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

#include "reactiongame.h"

#include "stdio.h"
#include "stdlib.h"
#include "led.h"
#include "seven.h"

#define LED_COUNT       3           ///< Total number of leds
#define MAX_BRIGHTNESS  255         ///< maximum pwm value
#define PHASE_SHIFT     255         ///< makes LEDs overlap at 128/128
#define STEP_SIZE       50          ///< Speed Control Multiplier



/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/**
* @brief typedef struct to define the variables required for the entire reaction game.
*/
typedef struct{
    uint8_t roundCounter;           ///< Total number of rounds played
    uint8_t correctPress;           ///< Total number of correct button presses in a game of 10 rounds
    uint8_t expectedButton;         ///< Value 1 or 2 which will be displayed on 7-segment and to check the correct button press logic
    uint8_t elementCountGlowTable;  ///< Total number of elements in the glow table

    TickType startTimer;            ///< Start value of systick counter for reaction time
    TickType currentTick;           ///< Current value of systick counter value for reaction time
    TickType reactionTime;          ///< Reaction time of one round i.e currentTick - startTimer.
    TickType totalReactionTime;     ///< Accumulated Reaction time of each correct rounds. 
    TickType averageReactionTime;   ///< Average reaction time of correct rounds in a game of 10 rounds
    
    RG_State_t state;               ///< States for the finite state machine.
    
} RG_t;

/**
* @brief typedef struct to define the values for const table
*/
typedef struct{
    uint8_t red;        ///< Variable to store the first value from the element of const table
    uint8_t green;      ///< Variable to store the second value from the element of const table
    uint8_t blue;       ///< Variable to store the third value from the element of const table
    uint16_t time;      ///< Variable to store the fourth value from the element of const table

} RG_Glow_t;

/**
* @brief Const RG_glowtable_1[] to store the values for RG_Glow_t
* \ for the glower functionality of arcadian light
* \ Declaration Style : {red, green, blue, time}
*/
const RG_Glow_t RG_glowtable_1[] = {
    {255, 0,   0,   500},
    {0,   255, 0,   500},
    {0,   0,   255, 500},
    {0,   0,   0,   100},
    {255, 255, 255, 100},
    {0,   0,   0,   100},
    {255, 255, 255, 100},
    {0,   0,   0,   100},
    {255, 255, 255, 100}
};

/*****************************************************************************/
/* Local variable definitions ('')                                     */
/*****************************************************************************/

static RG_Glow_t glow;      ///< Const table for glower          
static RG_t game;           ///< Variables for reaction game
static int32_t pos = 0;     ///< Current position for rising and falling edge (arcadian)
static int8_t dir = 1;      ///< +1 = Red->Yellow->Green and -1 = Green->Yellow->Red

/*****************************************************************************/
/* Local function prototypes ('')                                      */
/*****************************************************************************/
/**
 * Starts a random timer between minTime and maxTime using rand();
 * @param uint32_t minTime  : Starting point of random timer (in our case 1000ms)
 * @param uint32_t maxTime  :Ending point of random timer (in our case 3000ms)
 */
static inline void RG_startRandTimer(uint32_t minTime, uint32_t maxTime);

/**
 * Sets the sevent segment display with randomly generated value (1 or 2)
 */
static inline void RG_setSevenDisplay();

/**
 * Helper function to store the current systick counter value in to a static variable.
 * @return TickType game.currentTick    : To be used for reaction timing calculation
 */
static inline TickType CurrentSysTick();

/**
 * Helper function to calculate and print the reaction time of one particular round
 */
static inline void RG_CalculateReactionTime(void);

/**
 * Helper function to calculate and print the average reaction time and total number of correct button pressed;
 */
static inline void RG_printFinalScore(void);

/**
 * Helper Function to convert the tick type to string, in order to avoid sprintf (blocking function)
 * @param TickType value : Value to be converted to string
 * @param char *buf      : buffer in which the converted value will be stored
 */
static inline void tick_to_string(TickType value, char *buf);

/**
 * Helper Function to convert the uint8_t to string, in order to avoid sprintf (blocking function)
 * @param uint8_t value  : Value to be converted to string
 * @param char *buf      : buffer in which the converted value will be stored
 */
static inline void u8_to_string(uint8_t value, char *buf);

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('')          */
/*****************************************************************************/

/**
 * Initialises the pheripherals
 * @return RC_OK if function was executed as exepected, other error code in case of error
 */
RC_t RG_Init(){
    
    RGB_PWM_blue_Start();
    RGB_PWM_green_Start();
    RGB_PWM_red_Start();
    PWM_yellow_Start();
    PWM_green_Start();
    PWM_red_Start();
    SEVEN_Init();
    UART_LOG_Start();

    
    LED_RGB_Set(0,0,0);
    LED_Red_Set(0);
    LED_Yellow_Set(0);
    LED_Green_Set(0);    
    
    game.roundCounter = 1;
    
    return RC_SUCCESS;
}

/**
 * Print function Executed at the start of Task
 */
void RG_ShowWelcome(){
    srand(CurrentSysTick());
    UART_LOG_PutString("Reaction test program round ");
    char buf[4];
    u8_to_string(game.roundCounter, buf);
    UART_LOG_PutString(buf);

    UART_LOG_PutString("\nPress one of the two buttons to start... \n");

    game.state = S_RG_isWaitingStart;
}

/**
 * Main function for all the event handlers 
 * @param EventMaskType ev : Passing the event type to the function
 */
void RG_ProcessEvent(EventMaskType ev){
      
    switch(game.state){
        
        case S_RG_isWaitingStart:
            if(ev & (ev_leftButton | ev_rightButton)){
                //UART_LOG_PutString("S_RG_isWaitingStart \n"); 
                
                RG_startRandTimer(1000, 3000);          ///< Start the random timer as delay for the next state
                game.state = S_RG_isWaitingRandOver;    ///< Set the state to S_RG_isWaitingRandOver
            }
            break;
            
        case S_RG_isWaitingRandOver:
            if(ev & ev_waitOver){
                //UART_LOG_PutString("S_RG_isWaitingRandOver \n"); 
                
                RG_setSevenDisplay();                   ///< Set the seven segment display to print number
                CancelAlarm(alrm_slow);                 ///< Cancle alarm if already set
                SetRelAlarm(alrm_slow, 1000, 0);        ///< Set the alarm for 1000ms to trigger ev_slow
                
                game.startTimer = CurrentSysTick();     ///< Store the current time to game.startTimer            
                game.state = S_RG_isWaitingPlayer;      ///< Set the state to S_RG_isWaitingPlayer
            }
            break;
            
        case S_RG_isWaitingPlayer:
            if(ev & (ev_leftButton | ev_rightButton | ev_slow)){
                //UART_LOG_PutString("S_RG_isWaitingPlayer \n");
                
                switch(ev){
                    
                    case ev_leftButton:                 ///< If in player state left button is pressed 
                        if(game.expectedButton == 1){
                            game.correctPress++;
                            RG_CalculateReactionTime();
                        }
                        else{
                            UART_LOG_PutString("Oopsss - wrong button pressed \n");
                        }
                        
                        break;
                    
                    case ev_rightButton:                ///< If in player state right button is pressed 
                        if(game.expectedButton == 2){
                            game.correctPress++;
                            RG_CalculateReactionTime();

                        }
                        else{
                            UART_LOG_PutString("Oopsss - wrong button pressed \n");
                        }
                        break;
                    
                    case ev_slow:                       ///< If in player presses the button after 1000ms
                        UART_LOG_PutString("Oopsss - Too SLOW \n");
                        
                        break;
                
                }
                CancelAlarm(alrm_reset);                ///< cancel reset event caller alarm
                SetRelAlarm(alrm_reset, 300, 0);        ///< Reset event caller alarm
                game.roundCounter++;                    ///< Incremenet the game counter
                game.state = S_RG_isReset;              ///< State transition to S_RG_isReset
            }
            break;
            
        case S_RG_isReset:                              ///< State to handle the game after user button press
            if(ev & ev_reset){
                //UART_LOG_PutString("S_RG_isReset \n"); 
                SEVEN_Init();                           ///< Clear the seven segment display
                RG_ShowWelcome();                       ///< Print the welcome msg again
                if(game.roundCounter == 11){            ///< When the game counter reaches 10 rounds game ends and final score is printed
                    RG_printFinalScore();
                }
                
                game.state = S_RG_isWaitingStart;       ///< State transition to S_RG_isWaitingStart
            }
            break;
    }
    
}

/**
 * Function to implement the glower function for RGB light
 */
void RG_RGB_Set(){
    glow = RG_glowtable_1[game.elementCountGlowTable];
    LED_RGB_Set(glow.red, glow.green, glow.blue);
    CancelAlarm(alrm_glower);
    SetRelAlarm(alrm_glower,glow.time, 0);
    game.elementCountGlowTable++;
    if( game.elementCountGlowTable >=9){
        game.elementCountGlowTable = 0;
    }
}


/**
 * Function to implement the knight rider arcadian function for RGB light
 */
void RG_Arcadian(){
    
    pos += dir * STEP_SIZE;

    const int32_t maxPos = (LED_COUNT - 1) * PHASE_SHIFT;

    // bounce at ends
    if (pos >= maxPos) { pos = maxPos; dir = -1; }
    else if (pos <= 0) { pos = 0; dir = +1; }

    uint8_t pwm[LED_COUNT];

    for (int i = 0; i < LED_COUNT; i++)
    {
        int32_t center = i * PHASE_SHIFT;
        int32_t dist = abs(pos - center);

        int32_t value = MAX_BRIGHTNESS - dist;
        if (value < 0) value = 0;

        pwm[i] = (uint8_t)value;
    }

    LED_Red_Set(pwm[0]);
    LED_Yellow_Set(pwm[1]);
    LED_Green_Set(pwm[2]);
}

/**
 * Starts a random timer between minTime and maxTime using rand();
 * @param uint32_t minTime  : Starting point of random timer (in our case 1000ms)
 * @param uint32_t maxTime  :Ending point of random timer (in our case 3000ms)
 */
static inline void RG_startRandTimer(uint32_t minTime, uint32_t maxTime){
    
    CancelAlarm(alrm_randomTime);
    uint32 randTime = (rand() % (maxTime - minTime +1)) + minTime;
    SetRelAlarm(alrm_randomTime, randTime, 0);

}

/**
 * Sets the sevent segment display with randomly generated value (1 or 2)
 */
static inline void RG_setSevenDisplay(){
    game.expectedButton = (rand() % 2) + 1;
    SEVEN_Set(0,game.expectedButton);
    SEVEN_Set(1,game.expectedButton);

}

/**
 * Helper function to store the current systick counter value in to a static variable.
 * @return TickType game.currentTick    : To be used for reaction timing calculation
 */
static inline TickType CurrentSysTick(void){
    GetCounterValue(cnt_systick, &game.currentTick);
    return game.currentTick;
}   

/**
 * Helper function to calculate and print the reaction time of one particular round
 */
static inline void RG_CalculateReactionTime(void){
    char buf[16];
    
    game.reactionTime = CurrentSysTick() - game.startTimer;
    game.totalReactionTime += game.reactionTime;
    
    tick_to_string(game.reactionTime, buf);

    UART_LOG_PutString("Great - Correct button pressed\nReaction time in ms:");
    UART_LOG_PutString(buf);
}

/**
 * Helper function to calculate and print the average reaction time and total number of correct button pressed;
 */
static inline void RG_printFinalScore(void){
    char buf[16];
    char buf1[16];
    UART_LOG_PutString("GAME OVER \n");
    game.averageReactionTime = game.totalReactionTime/game.correctPress;
    
    tick_to_string(game.averageReactionTime, buf);
    tick_to_string(game.correctPress, buf1);
    UART_LOG_PutString("Average Time in ms:");
    UART_LOG_PutString(buf);
    UART_LOG_PutString("Total Correct Press:");
    UART_LOG_PutString(buf1);
    
    game.roundCounter = 0;
    game.startTimer = 0;
    game.averageReactionTime = 0;
    game.totalReactionTime = 0;
    game.correctPress = 0;
}

/**
 * Helper Function to convert the tick type to string, in order to avoid sprintf (blocking function)
 * @param TickType value : Value to be converted to string
 * @param char *buf      : buffer in which the converted value will be stored
 */
static inline void tick_to_string(TickType value, char *buf)
{
    uint8_t i = 0;
    char temp[11];     // Max 10 digits for uint32 + '\0'
    uint8_t j = 0;

    // Handle 0 explicitly
    if (value == 0) {
        buf[i++] = '0';
        buf[i++] = '\n';
        buf[i] = '\0';
        return;
    }

    // Convert digits in reverse order
    while (value > 0) {
        temp[j++] = '0' + (value % 10);
        value /= 10;
    }

    // Reverse the digits into the output buffer
    while (j > 0) {
        buf[i++] = temp[--j];
    }

    // Add newline + null terminator
    buf[i++] = '\n';
    buf[i]   = '\0';
}

/**
 * Helper Function to convert the uint8_t to string, in order to avoid sprintf (blocking function)
 * @param uint8_t value  : Value to be converted to string
 * @param char *buf      : buffer in which the converted value will be stored
 */
static inline void u8_to_string(uint8_t value, char *buf)
{
    uint8_t i = 0;

    if (value >= 100) {
        buf[i++] = '0' + value / 100;
        value %= 100;
    }
    if (value >= 10) {
        buf[i++] = '0' + value / 10;
        value %= 10;
    }

    buf[i++] = '0' + value;
    buf[i] = '\0';
}




