#include "globaldefine.h"
#include "global.h"
#include "constantes.h"

/**********************************************************
** Initialisation de Timer3 pour générer 1 signal à 26us **
**********************************************************/

void T3_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure;
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure;
	
	/*Initialisation Timer3*/
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_USVAL;					
	Timer_Config_Structure.PrescaleValue	= TIMER3_TIME_STEP;							
	TIM_Init(LPC_TIM3, TIM_TIMER_MODE,&Timer_Config_Structure);
	
	/*Configuration des registres de match*/
	Timer_MatchConfig_Structure.MatchChannel = 0;													
	Timer_MatchConfig_Structure.IntOnMatch   = FALSE;										
	Timer_MatchConfig_Structure.ResetOnMatch = TRUE;											
	Timer_MatchConfig_Structure.StopOnMatch  = FALSE;											
	Timer_MatchConfig_Structure.ExtMatchOutputType = TIM_EXTMATCH_TOGGLE;
	Timer_MatchConfig_Structure.MatchValue = TIMER3_MATCH_VALUE_13us;	
	TIM_ConfigMatch(LPC_TIM3,&Timer_MatchConfig_Structure);							
																				
}
