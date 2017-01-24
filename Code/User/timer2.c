#include "globaldefine.h"
#include "global.h"
#include "constantes.h"


void T2_Init(void)
{
	TIM_CAPTURECFG_Type Timer_ConfigCaptur_Structure;
	TIM_TIMERCFG_Type Timer_ConfigTim_Structure;
	
	// Timer2  Initialization
	Timer_ConfigTim_Structure.PrescaleOption=TIM_PRESCALE_USVAL;
	Timer_ConfigTim_Structure.PrescaleValue=1;											//valeur du préscalair en us
	TIM_Init(LPC_TIM2, TIM_TIMER_MODE,&Timer_ConfigTim_Structure);
	
	/*Capture Input configuration*/
	Timer_ConfigCaptur_Structure.CaptureChannel=1;			// utilisation de Cap2[1]		
	Timer_ConfigCaptur_Structure.RisingEdge=ENABLE;			
	Timer_ConfigCaptur_Structure.FallingEdge=ENABLE;
	Timer_ConfigCaptur_Structure.IntOnCaption= ENABLE;
	
	TIM_ConfigCapture(LPC_TIM2,&Timer_ConfigCaptur_Structure);							

	
	NVIC_EnableIRQ(TIMER2_IRQn);
	TIM_Cmd(LPC_TIM2,ENABLE);
	

}