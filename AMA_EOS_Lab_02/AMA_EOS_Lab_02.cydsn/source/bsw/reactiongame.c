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

#include "led.h"
#include "sEVen.h"


/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/


static  uint8_t roundCounter = 1;
static uint8_t correctPress = 0;
static uint8_t expectedButton = 0;

static volatile uint32_t sysTimer = 0;
static uint32_t startTimer = 0;
static uint32_t totalReactionTime = 0;
static uint32_t averageReactionTime = 0;
TickType currentTick;

static char tempBuf[64];
static RG_State_t state = S_RG_START;


/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
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
    
    char Buf[64];
    sprintf(Buf, "Welcome to Reaction Game\n");
    RG_Print(Buf);
    
    
    return RC_SUCCESS;
}

void RG_Print(char const * const log){
    
    GetResource(res_printf);
    UART_LOG_PutStringConst(log);
    ReleaseResource(res_printf);
   
}

void RG_ShowWelcome(void){
    
    SEVEN_Init();
    char Buf[128];
    sprintf(Buf, "Round %u Started: \nPress one of the two buttons to start.. \n", 
        (unsigned char)roundCounter);
    RG_Print(Buf);
   

}


int CurrentSysTick(){
    GetCounterValue(Counter_Systick, &currentTick);
    return currentTick;
}               

void RG_ProcessEVent(EventMaskType EV){

    switch(state){
            
        case S_RG_START:
            if(EV & (ev_leftButton | ev_rightButton)){
                
                //uint32_t randomTime = 2000;
                //CancelAlarm(Alarm_startWaitOver);
                //SetRelAlarm(Alarm_startWaitOver, randomTime, 0);
                //CyDelay(randomTime);
                
                expectedButton = 1;
                SEVEN_Set(0, expectedButton);
                SEVEN_Set(1, expectedButton);
                
                state = S_RG_WAITPLAYER;
                
                
            }
        
            break;
            
        
        case S_RG_WAITPLAYER:
            if(EV & ev_rightButton){
                if(expectedButton == 1){
                    uint32_t currentReactionTime =  CurrentSysTick() - startTimer;
                    totalReactionTime += currentReactionTime;
                    
                    sprintf(tempBuf, "Great - Correct Button Pressed \nReaction Time in ms: %u", 
                        (unsigned int)currentReactionTime);
                    RG_Print(tempBuf);
                    
                    correctPress++;
                    
                    roundCounter++;
                    RG_ShowWelcome();
                }
                else{
                    RG_Print("Incorrect Button Pressed \n");
                    
                    roundCounter++;
                    RG_ShowWelcome();
                }
            }
            
            else if(EV & ev_leftButton){
                if(expectedButton == 2){
                    uint32_t currentReactionTime =  CurrentSysTick() - startTimer;
                    totalReactionTime += currentReactionTime;
                    
                    sprintf(tempBuf, "Great - Correct Button Pressed \nReaction Time in ms: %u", (unsigned int)currentReactionTime);
                    RG_Print(tempBuf);
                    
                    correctPress++;
                    
                    roundCounter++;
                    RG_ShowWelcome();
                }
                else{
                    RG_Print("Incorrect Button Pressed \n");
                    roundCounter++;
                    RG_ShowWelcome();
                    
                }
            }
               
            else if (EV & ev_slow){
                RG_Print("Too slow \n");
                roundCounter++;
                RG_ShowWelcome();
                
            }
                               
            
            break;
        
        case S_RG_SCORE:
            if(EV & ev_score){   
                char buf[128];
                averageReactionTime = totalReactionTime / correctPress;
                sprintf(buf, "Correct Button Pressed : %u \n Total reaction time: %u \n Average Reaction Time: %u", 
                    correctPress, (unsigned int)totalReactionTime, (unsigned int)averageReactionTime);
                RG_Print(buf);
                
                state = S_RG_RESET;
            }
            break;
            
        case S_RG_RESET:
            if(EV & ev_reset){
                roundCounter = 1;
                sysTimer = 0;
                startTimer = 0;
                correctPress = 0;
                expectedButton = 0;
                totalReactionTime = 0;
                averageReactionTime = 0;
                RG_ShowWelcome();
            }    
            break;
            
    }

}

