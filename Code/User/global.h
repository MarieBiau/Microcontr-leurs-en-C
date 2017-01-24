// fichier contenant l'importation des variables globales de l'application
// à inclure dans les autres fichiers que le main

/*Base de temps de TIMER0*/
extern unsigned int globalTime0;

/*Emission IR*/
extern int lg_message;
extern int message[3];
extern int eIRi, eIRj;
extern unsigned int eIRt0;

/*Reception IR*/
extern int header;
extern int indiceMessage;
extern int debutMessage;
extern unsigned int tInitial;
extern int messageR[3]; //variable permettant de recevoir le message
extern int finMessage; // variable à "1" si un message entier a été reçu
extern int lg_message;

/*Ecran LCD tactile*/
extern char bufferTX[16];		//buffer pour l'affichage sur uart0
extern int n; 		//taille du message à envoyer (max 16)
extern char chaine[16];		//chaîne pour l'affichage sur l'écran
extern int i;		//itérateur
extern int password[4];		//tableau recevant le mot de passe entré
extern int numero;		//on récupère le numéro_ième chiffre du mot de passe
extern uint16_t x_position;		//x de l'appui sur l'écran
extern uint16_t y_position;		//y de l'appui sur l'écran

/*Ultrason*/
extern int cpt_echo;		// Temps à la réception d'un front montant de l'écho
extern int cpt_echo_final;		// Temps à la réception d'un front descendant de l'écho
extern int globalT;

/**********************************************************
************************* Flags ***************************
**********************************************************/
 
/*Flags "d'activation" des fonctions*/
extern int bipActive;		//activation du bipper 
extern int ecran_appui;	//appui sur l'écran tactile
extern int scrutecran;	//pour regarder s'il y a un appui sur l'écran
extern int open;				//flag code ultrason OK. si = 3 on ouvre le cadenas
extern int tsOpen;			//flag code ecran OK
 
/*Flags "internes" des fonctions*/
//Bipper
extern int flagPer;			//pour faire une periode sur le bipper
extern int flagBip;			//pour alterner les bips
//Ecran tactile
extern int validation;	//pour faire disparaître le message de validation

/*Variables pour les durées pour l'actualisation des flags*/
//Bipper
extern int dureePer;		//pour la fonction periode
extern int dureeBip;		//pour la fonction bip
extern int dureeBipActive;		// duree d'activation du bip

/***************************************************Ultrason*****************************************************************************/
extern int bouton_appui;
extern int open;
extern int cpt_echo;
extern int cpt_echo_final;
extern int b;
extern int compteur_init;
extern int flag1;
extern int flag2;
extern int echo;
extern float temps_ecoule;
extern int passage;
