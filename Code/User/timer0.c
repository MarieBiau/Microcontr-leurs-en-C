#include "globaldefine.h"
#include "global.h"
#include "constantes.h"

/**********************************************************
** Initialisation de Timer0 pour g�n�rer 1 signal � 1us ***
**********************************************************/
void T0_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure; 
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure;
	
	/*Initialisation de Timer0*/
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_USVAL;						
	Timer_Config_Structure.PrescaleValue	= TIMER0_TIME_STEP;				
	TIM_Init(LPC_TIM0, TIM_TIMER_MODE,&Timer_Config_Structure);
	
	/*Configuration des registres de match*/
	Timer_MatchConfig_Structure.MatchChannel = 0;													
	Timer_MatchConfig_Structure.IntOnMatch   = TRUE;											
	Timer_MatchConfig_Structure.ResetOnMatch = TRUE;										
	Timer_MatchConfig_Structure.StopOnMatch  = FALSE;										
	Timer_MatchConfig_Structure.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;	
	Timer_MatchConfig_Structure.MatchValue = TIMER0_MATCH_VALUE_1us;		
	TIM_ConfigMatch(LPC_TIM0,&Timer_MatchConfig_Structure);								
	
	/*Activation interruption*/
	TIM_Cmd(LPC_TIM0,ENABLE);																							
	NVIC_EnableIRQ(TIMER0_IRQn);
}

/**************************************************************
   Routine d'interruption de Timer0
**************************************************************/
void TIMER0_IRQHandler(void){
	
	/*Incr�mentation base de temps*/
	//mise � jour de globalTime0
	globalTime0 = globalTime0 + 1;
	if (globalTime0%50000==0) {scrutecran=1;}		//On teste le tactile toutes les 0,05 secondes
	globalT = globalT+1;
	
	/*Bipper*/
	if (bipActive == 1){
		dureeBipActive ++;
		//mise � jour de dureePer
		dureePer ++;
		//mise � jour de dureeBip
		dureeBip ++;
		//mise � jour de flagPer
		if (dureePer == dureePerMatch){ 
			flagPer = (flagPer+1)%2;
			dureePer = 0;
		}
		//Mise � jour de flagBip
		if (dureeBip == dureeBipMatch){
			flagBip  = (flagBip+1)%2;
			dureeBip =0;
		}
		//Mise � jour de bipActive
		if (dureeBipActive == 7500000){
			bipActive = 0;
			dureeBipActive = 0;
		}
	}

	// R�ajuste IR
	TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT);
}
