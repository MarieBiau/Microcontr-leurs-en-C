#include "globaldefine.h"
#include "global.h"


void pin_Configuration(void)
{
	/*Déclaration de la structure de configuration*/
	PINSEL_CFG_Type maconfig;
	
	/********************************************************
	***************** Base de temps Timer0 ******************
	********************************************************/
	
	// Config MAT0
	maconfig.Portnum = PINSEL_PORT_1;		//port 1
	maconfig.Pinnum =PINSEL_PIN_28;		//pin 28
	maconfig.Funcnum = PINSEL_FUNC_3;		//MAT0.0
	maconfig.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);
	
	/********************************************************
	********************** Bipper ***************************
	********************************************************/
	
	//GPIO1
	GPIO_SetDir(1,512,1); //P1.9 en sortie
	
	//Config P1.9
	maconfig.Portnum = PINSEL_PORT_1;		//port 1
	maconfig.Pinnum =PINSEL_PIN_9;		//pin 9
	maconfig.Funcnum = PINSEL_FUNC_0;		//GPIO 
	maconfig.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
	PINSEL_ConfigPin(&maconfig);
	
/********************************************************
******************** Emission IR ***********************
	********************************************************/
	
	//Config MAT3
	maconfig.Portnum = PINSEL_PORT_0;		//port 0
	maconfig.Pinnum = PINSEL_PIN_10;		//pin 10
	maconfig.Funcnum = PINSEL_FUNC_3;		//MAT3.0
	maconfig.Pinmode = PINSEL_PINMODE_PULLDOWN;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);

/*
* Reception IR
*/
		//Config CAP2
		maconfig.Portnum = PINSEL_PORT_0;
		maconfig.Pinnum =PINSEL_PIN_5;
		maconfig.Funcnum = PINSEL_FUNC_3;			//fonction 3 corespond à CAP2[1]
		maconfig.Pinmode =PINSEL_PINMODE_PULLUP;
		maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
		PINSEL_ConfigPin(&maconfig);
/*
* LED fin émission
*/
	
	GPIO_SetDir(0,1<<0,1);
	GPIO_ClearValue(0,1<<0);
	

/**********************************************************
*********************** Ultrason **************************
**********************************************************/

/*Trigger*/
	//GPIO0
	GPIO_SetDir(0,(1<<24),1); //P0.24 en sortie
	//Activation du port0.24 en pulldown 
	maconfig.Portnum = PINSEL_PORT_0;		//port 0
	maconfig.Pinnum = PINSEL_PIN_24;		//pin 24
	maconfig.Funcnum = PINSEL_FUNC_0;		//GPIO
	maconfig.Pinmode = PINSEL_PINMODE_PULLUP;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
	PINSEL_ConfigPin(&maconfig);
	GPIO_ClearValue(0, (1<<24));

/*Bouton poussoir*/
	//GPIO0
	GPIO_SetDir(0,(1<<26),0); //port0.26 en entrée
	// Activation du port0.26
  maconfig.Portnum = PINSEL_PORT_0;		//port 0
  maconfig.Pinnum = PINSEL_PIN_26;		//pin 26
  maconfig.Funcnum = PINSEL_FUNC_0;		//GPIO
  maconfig.Pinmode =PINSEL_PINMODE_PULLUP;
  maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);

/*Echo*/
	//GPIO
	GPIO_SetDir(0,(1<<25),0); //P0.25 en entrée
	// Activation de P0.25 en pullup
  maconfig.Portnum = PINSEL_PORT_0;
  maconfig.Pinnum = PINSEL_PIN_25;
  maconfig.Funcnum = PINSEL_FUNC_0;
  maconfig.Pinmode =PINSEL_PINMODE_PULLDOWN;
  maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);
	//Activation interruption sur P0.25
  NVIC_EnableIRQ(EINT3_IRQn);
  GPIO_ClearValue(0, (1<<25));
}
