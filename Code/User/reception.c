#include "globaldefine.h"
#include "global.h"






void TIMER2_IRQHandler(void) 
{
	/* Les variable globale : header, debutMessage, indiceMessage et finMessage permettent d'annalyser la reception :
		- header : variable � "1" si la partie �mission du header a �t� re�u, � "2" si le header a �t� enti�rement re�u
		- debutMessage : variable � "1" si les 600us d'�mission pr�c�dant l'envoie d'un bit ont �t� re�u
		- indiceMessage : varible incr�menter � chaque reception de bit
		- finMessage: variable � "1" si un message entier a �t� re�u
	
	*/
	
	
		
		//r�ception de 9000 us d'�mission (header)
		if(tInitial+8500<LPC_TIM2->CR1 && LPC_TIM2->CR1<9500+tInitial){
							header=1; 
							indiceMessage=0;
							debutMessage=0;}
		
		//r�ception de 4500 us de non �mission (le contenu du message est pr�s � �tre re�u)					
		else if(tInitial+4400< LPC_TIM2->CR1 && LPC_TIM2->CR1<tInitial+4600){
						if(header==1){header++;}
						else{header=0;}
						debutMessage=0;
						indiceMessage=0;
						}
		
		//r�ception de 600us d'�mission (r�ception d'un bit)
		else if(400+tInitial<LPC_TIM2->CR1 && LPC_TIM2->CR1<750+tInitial){
					if((header=2 || indiceMessage!=0) && debutMessage==0){debutMessage=1;}
					else{debutMessage=0;
					indiceMessage=0;}
					header=0;
					}
								
		//r�ception de 1000us de non �mission (r�ception d'un "1")			
		else if(900+tInitial<LPC_TIM2->CR1 && LPC_TIM2->CR1<1100+tInitial){
				if(debutMessage==1){messageR[indiceMessage]=1;
														indiceMessage++;}
				else{indiceMessage=0;}
				debutMessage=0;
				header=0;}
								
		//r�ception de 2000us de non �mission (r�ception d'un "0")		
		else if(1900+tInitial<LPC_TIM2->CR1 && LPC_TIM2->CR1<2100+tInitial){ 
							if(debutMessage==1){indiceMessage++;
																	messageR[indiceMessage]=0;}
								debutMessage=0;
								header=0;}
								
	/*	//40 000us de non �mission -> fin du message			
		else if(30500+tInitial<LPC_TIM2->CR1 && LPC_TIM2->CR1<40500+tInitial){if(debutMessage==1){finMessage=1;}
								debutMessage=0;
								indiceMessage=0;
								header=0;
							}*/
	
		//dans les autres cas, on initialise les variable pour pr�parer la reception d'un header
		else{	debutMessage=0;
					indiceMessage=0;
					header=0;}													
		tInitial= LPC_TIM2->CR1;						
	
	if (indiceMessage==3){
		 GPIO_SetValue(0,(1<<0));}
	
	LPC_TIM2->IR=(1<<0); // R�ajuste IR
	TIM_ClearIntPending(LPC_TIM2, TIM_CR1_INT );

}
