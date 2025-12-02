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

#include "reactiongame.h"


int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
  
    for(;;)
    {
        StartOS(OSDEFAULTAPPMODE); 
    }
}

void unhandledException(){
    __asm("bkpt");
}

/********************************************************************************
 * ISR Definitions
 ********************************************************************************/

//ISR which will increment the systick counter every ms 
ISR(systick_handler) {
     CounterTick(Counter_Systick); 
}

ISR2(isr_Button_Pressed){

    if (BUTTON_1_Read() || BUTTON_3_Read()){
        SetEvent(Task_Event, ev_leftButton);
    }
    
    if( BUTTON_2_Read() || BUTTON_4_Read() ){
       SetEvent(Task_Event, ev_rightButton);
    }
    
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(Task_Init){
    
    RG_Init();
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
    
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start(); 

    
    //Activate all extended and the background task
    ActivateTask(Task_Background);
    ActivateTask(Task_Event);
   
    
    TerminateTask();

}



TASK(Task_Event){
    
    EventMaskType ev;
    
    RG_ShowWelcome();
    
    while(1){
        WaitEvent(ev_leftButton | ev_rightButton | ev_slow | ev_reset  | ev_score);
        GetEvent(Task_Event, &ev);
        ClearEvent(ev);
        
        RG_ProcessEvent(ev);

    }
    
    TerminateTask();
}


TASK(Task_Background){
    while(1)
    {
        //do something with low prioroty
        __asm("nop");
    }
}
/* [] END OF FILE */
