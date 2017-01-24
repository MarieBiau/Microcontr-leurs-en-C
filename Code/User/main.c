//===========================================================//
// Projet Micro - Info1 - ENSSAT - Mars 2015				 //
//===========================================================//
// File                : Programme de test robot 
// Hardware Environment: Open1768	
// Build Environment   : Keil µVision V4.72.10
//===========================================================//


/*#include*/
#include "globaldefine.h"
/*Variables*/
#include "globaldec.h"
/*Constantes*/
#include "constantes.h"
/*Configuration des pins*/
#include "pinconf.h"
/*Timers*/
#include "timer0.h"
#include "timer2.h"
#include "timer3.h"
/*Bipper*/
#include "bip.h"
/*Emission IR*/
#include "emission.h"
/*Reception IR*/
#include "reception.h"
/*Ecran tactile*/
#include "../User/touch/ecran.h"
/*Ultrason*/
#include "ultrason.h"

 void initialisation_ecran(void);
 void initialisation_variables_ecran (void);
 void touch_down(uint16_t*,uint16_t*,int*);
 void remplissage_password(void);
 void test_password(void);

//===========================================================//
// Function: Main
//===========================================================//
int main(void)
{	
	/************************************************************
	                  Configuration des pins
	************************************************************/
	pin_Configuration();
	
	/************************************************************
	              Initialisation des périphériques
	************************************************************/
	T0_Init();
	T2_Init();
	T3_Init();
	initialisation_ecran();
	
	/************************************************************
	                    Programme principal
	************************************************************/
	while(1)
	{
		
		/*Ultrason*/
		start_compteur(); // Réinitialise le compteur et les flags ( sous certaines conditions )
		Poussoir_init(); // Initialise l'entier bouton_appui
		Bouton_poussoir(); // Permet l'activation du compteur et des flags en fonction de bouton_appui
		Trigger(); // Lance le Trigger ( En fonction de bouton_appui)
		Echo_fonction(); // Lance l'echo ( en fonction de bouton_appui et de l'entier echo )
		
		/*Ecran*/
		if (scrutecran==1 && bouton_appui==0) {		//Si le bouton poussoir n'est pas enclenché
			scrutecran=0;
			if (numero>0 && bipActive==0) {		//Si le temps imparti est écoulé on réinitialise l'écran
				initialisation_variables_ecran();
				affichage();
			}
			touch_down(&x_position,&y_position,&ecran_appui);		//On récupère la position de l'appui de l'écran si elle existe
			if (ecran_appui==1) {		//Si on a appuyé sur l'écran
				ecran_appui=0;
				bipActive=1;					//Activation du bipper
				update_password();		//Récupération du mot de passe
			}
			if (validation==1) {		//Si on a validé alors on réinitialise l'écran
				affichage();
				validation=0;
				bipActive=0;
			}
		} 
		
		/*Emission IR*/		
		if(open == 3 || tsOpen == 1){
			GPIO_ClearValue(0,1<<0);
			emission();
			tsOpen = 0;
			open = 0;
		}
		
		/*activation bippper*/
		if(ecran_appui == 1 || bouton_appui == 1){
			bipActive = 1;
		}
		
		/*Bipper*/
		 if(bipActive == 1){
			bip();
		}
		
		

	} 	
}




//---------------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
