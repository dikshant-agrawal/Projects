/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdlib.h"
#include "stdio.h"
#include "reactiongame.h"
#include "led.h"



void unhandledException(){
    __asm("bkpt");
}

/**
* Main function to enable to the erika os, systick timer and the global interrupts.
*/
int main(void){
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
    
    for(;;)
    StartOS(OSDEFAULTAPPMODE); 
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

/**
* Task Init to initialize all the peripherals and erika os, also activate the respective task
* \Task init autostarts on bootup. 
*/
TASK(tsk_init){
    
    RG_Init();
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();
    
    ActivateTask(tsk_background);       ///< Activate the background task 
    ActivateTask(tsk_event);            ///< Activate the main event handler extended task
    ActivateTask(tsk_glower);           ///< Activate the task for RGB glower functionality
    SetRelAlarm(alrm_Tick1ms,1,100);  ///< Start the cyclic alarms 

    TerminateTask();
}

/**
* Extended task to handle all the event and alarm triggers for the reaction game.
*/
TASK(tsk_event){

    EventMaskType ev;


    RG_ShowWelcome();
    while(1){
        WaitEvent(ev_leftButton | ev_rightButton |ev_waitOver | ev_slow | ev_reset );
        GetEvent(tsk_event, &ev);
        ClearEvent(ev);
        
        RG_ProcessEvent(ev);


    }
    
    TerminateTask();
}

/**
* Task background to keep the system alive
*/
TASK(tsk_background){
    while(1)
    {
        //do something with low prioroty
        __asm("nop");
    }
}

/**
* Task declaration for the glower function from arcadian lights
*/
TASK(tsk_glower){
    //RG_RGB_Set();
    TerminateTask();
}

/**
* Task declaration for the arcadian function
*/
TASK(tsk_arcadian){
    RG_Arcadian();
    TerminateTask();
}




/********************************************************************************
 * ISR Definitions
 ********************************************************************************/

//ISR which will increment the systick counter every ms 
ISR(systick_handler) {
    CounterTick(cnt_systick);   
}

//ISR to handle button press
ISR2(isr_buttonPressed){

    if (BUTTON_3_Read() == 1){
        SetEvent(tsk_event, ev_leftButton);
    }
    if (BUTTON_4_Read() == 1){
        SetEvent(tsk_event, ev_rightButton);
    }
}

/* [] END OF FILE */
