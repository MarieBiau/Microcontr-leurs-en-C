#include "globaldefine.h"
#include "global.h"



/*******************************************************
                   Gestion du bipper 
*******************************************************/

/*G�n�ration d'un signal carr� p�riodique*/
void periode(){
	//on met 1 ou 0 sur P1.9 suivant la valeur de flagPer
	if(flagPer == 1){
		GPIO_SetValue(1,512);
	}else{
		GPIO_ClearValue(1,512);
	}
}


/*G�n�ration d'une suite de bips*/
void bip(){
	//on fait un bip ou on met 0 sur P1.9 suivant la valeur de flagBip
	if (flagBip == 1){
		periode();
	}else{
		GPIO_ClearValue(1,512);
	}
}
