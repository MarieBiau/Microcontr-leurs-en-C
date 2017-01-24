#include "globaldefine.h"
#include "global.h"

// Voici le code de Thibaud GRIET 



/********************************************************** 
******************* Codage du Trigger *********************
**********************************************************/
void Trigger(void){ // Permet de faire des pulsations de 48 µs en moyenne espacées de 100ms
    if(flag1==1) { 
			if(((LPC_GPIO0->FIOPIN>>24)&(1<<0))== 0) {
                    GPIO_SetValue(0,(1<<24));
			}
    }else{
        if(flag2==1){
            if(((LPC_GPIO0->FIOPIN>>24)&(1<<0))== 1) {
							GPIO_ClearValue(0, (1<<24));
							echo=1;    // On autorise l'echo dès que le front montant de 48µs est passé
						}
				}
				else{
					echo=0; // S'il ne se passe rien, on réinitialise tout.
					compteur_init=0;
					globalT=0;
        }
		}
}

/**********************************************************
**************** Codage du bouton poussoir ****************
**********************************************************/

void Poussoir_init(void){ // On passe un booléen ( ici entier qui ne prend que 0 ou 1 comme valeur ) par adresse
	if(((LPC_GPIO0->FIOPIN>>26)&(1<<0))== 0){ // Si le port0.26 est à 1   
		bouton_appui=1;
  }
	else{
		bouton_appui=0;
	}
}


void Compteur(void){
	flag1=1;
  flag2=0;
  if(globalT>=((compteur_init+25)*2)){ // Si le compteur n'atteind pas 40 µs ( étendu à 100 µs ici )
		flag1=0;
  }
  if(globalT<=((compteur_init+100010)/2)){ // Tant que le temps est différent de a +100,010ms        
		flag2=1;
  }
}


void Bouton_poussoir(void){
	if (bouton_appui==1){
		Compteur();
  }
}

/**********************************************************
******************* Codage de l'écho **********************
**********************************************************/

void compteur_echo(void){		// Permet de compter le nombre de passage de main devant l'ultrason
	GPIO_IntCmd(0,(1<<25),1);		// On autorise l'interruption GPIO sur le port0.25 ( front descendant )
	temps_ecoule=(cpt_echo_final-cpt_echo);		// On calcule la différence entre le front montant et descendant 
	if( passage<(406/2)| passage>(754/2)){		// Si le temps du précédant echo n'est pas compris entre 406/2 µs et 754/2 µs
		if(((406/2)<=temps_ecoule) && (temps_ecoule<=(754/2))){		// Si le temps de l'écho actuel est compris dans cet intervalle
			open=open+1;		// on incrémente le compteur open
		}
	}
	passage=temps_ecoule; 
}
            
void start_compteur(void){
	if(bouton_appui!=1){ // Si le bouton poussoir n'est pas appuyé, on réinitialise les flags et les compteurs
		compteur_init=globalT;
		flag1=0;
		flag2=0;
		open=0;
		GPIO_ClearValue(0, (1<<24));
	}
}
    

void Echo_fonction(void){
	if(echo==1){ // Si l'echo est activé
		GPIO_IntCmd(0, (1<<25), 0); //Autorisation d'effectuer une interruption GPIO sur le port0.25 ( interruption sur front montant )
		compteur_echo();         
	}
}
void EINT3_IRQHandler(void){
	if(((LPC_GPIO0->FIOPIN>>25)&(1<<0))== 1) {
		GPIO_ClearInt(0,(1<<25)); // On arrête l'interruption
		cpt_echo=globalT;
	}
	if(((LPC_GPIO0->FIOPIN>>25)&(1<<0))== 0) {
		GPIO_ClearInt(0,(1<<25)); // On arrête l'interruption
		cpt_echo_final=globalT;
	}
}
