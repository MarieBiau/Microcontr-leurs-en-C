#include "globaldefine.h"
#include "global.h"





void emission (void){
	

	
	/*Envoie du header*/
	
	//Emission pendant 9000us
	TIM_Cmd(LPC_TIM3,ENABLE);	
	eIRt0= globalTime0;
	while (globalTime0 != eIRt0 +4500){};
	
	//Non émission pendant 4500us 
	TIM_Cmd(LPC_TIM3,DISABLE);
	eIRt0= globalTime0;
	while (globalTime0 !=eIRt0+2250){};
		
	/*Envoie du message*/
		
	for (i=0; i<=lg_message-1; i++){
		if (message[i]==1){
			TIM_Cmd(LPC_TIM3,ENABLE);
			eIRt0= globalTime0;
			while (globalTime0!=eIRt0+300){};
			TIM_Cmd(LPC_TIM3,DISABLE);
			eIRt0= globalTime0;
			while (globalTime0 !=eIRt0+500){};
			eIRj++;
		};
		if (message[i]==0){
			TIM_Cmd(LPC_TIM3,ENABLE);
			eIRt0= globalTime0;
			while (globalTime0!=eIRt0+300){};
			TIM_Cmd(LPC_TIM3,DISABLE);
			eIRt0= globalTime0;
			while (globalTime0!=eIRt0+1000){};
		};
		
	}
	
	/*Envoie du signal de fin*/
	
	//Emission pendant 600 us
	TIM_Cmd(LPC_TIM3,ENABLE);
	eIRt0= globalTime0;
	while (globalTime0!=eIRt0+300){};
		
	//Non Emission pendant 40 000 us	
	TIM_Cmd(LPC_TIM3,DISABLE);
	eIRt0= globalTime0;
	while (globalTime0!=eIRt0+20000){};
	
}