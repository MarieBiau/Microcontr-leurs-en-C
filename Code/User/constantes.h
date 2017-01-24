//fichier contenant l'inclusion des #define qui servent à toute l'application
//à inclure dans tous les fichiers

/**********************************************************
************************* Timers **************************
**********************************************************/

/*Timer0*/
#define TIMER0_TIME_STEP 1		// 1 us de Step Timer
#define TIMER0_MATCH_VALUE_1us  1		// valeur pour avoir 1 us 
//(en theorie 1, mais sur simulation, on est alors plus proche de 2us) 

/*Timer3*/
#define TIMER3_TIME_STEP 1		//1 us de Step Timer
#define TIMER3_MATCH_VALUE_13us 13		//pour avoir une fréquence de 38kHz 

/**********************************************************
******************* Valeurs a matcher *********************
**********************************************************/

/*Bipper*/
#define	dureePerMatch  568		//durée d'une demi-période
#define dureeBipMatch  250000		//durée d'un bip

