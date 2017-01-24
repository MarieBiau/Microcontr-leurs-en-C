// fichier contenant la déclaration des variables globales de l'application
// à inclure seulement dans le main

/*Base de temps de TIMER0*/
unsigned int globalTime0;

/*Emission IR*/
int lg_message=3;
int message[3]={1,1,0};
int eIRi, eIRj;
unsigned int eIRt0;

/*ReceptionIR*/
unsigned int globalTime0;
int header;
int indiceMessage;
int debutMessage;
unsigned int tInitial;
int messageR[3]; //variable permettant de recevoir le message
int finMessage=0; // variable à "1" si un message entier a été reçu

/*Ecran tactile*/
char bufferTX[16];		//buffer pour l'affichage sur uart0
int n;		//taille du message à envoyer (max 16)
char chaine[16];		//chaîne pour l'affichage sur l'écran
int i;		//itérateur
int password[4];		//tableau recevant le mot de passe entré
int numero;		//on récupère le numéro_ième chiffre du mot de passe
uint16_t x_position;		//x de l'appui sur l'écran
uint16_t y_position;		//y de l'appui sur l'écran

/*Ultrason*/
int cpt_echo = 0;		// Temps à la réception d'un front montant de l'écho
int cpt_echo_final = 0;		// Temps à la réception d'un front descendant de l'écho
int globalT = 0;

/**********************************************************
************************* Flags ***************************
**********************************************************/
 
/*Flags "d'activation" des fonctions*/
int bipActive;		//activation du bip 
int ecran_appui;	//appui sur l'écran tactile
int scrutecran;		//pour regarder s'il y a un appui sur l'écran
int open = 0;			//flag code ultrason OK. si = 3 on ouvre le cadenas
int tsOpen = 0;		//flag code ecran OK

/*Flags "internes" des fonctions*/
//Bipper
int flagPer;		//pour faire une periode sur le bipper
int flagBip;		//pour alterner les bips
//Ecran tactile
int validation;	//pour faire disparaître le message de validation

/*Variables pour les durées pour l'actualisation des flags*/
//Bipper
int dureePer;		//pour la fonction periode
int dureeBip;		//pour la fonction bip
int dureeBipActive = 0;		// duree d'activation du bip

/***********************************************************Ultrason************************************************************/
int bouton_appui;		//1 si BP appuyé
int b=0;		// Variable d'appui
int compteur_init=0;		// compteur proportionnelle à globalTime0
int flag1;		// flag signalant que le pin24 est à 1
int flag2;		// flag signalant que le pin24 est à 0
int echo=0;		// Variable d'activation de l'écho
float temps_ecoule;		// Différence ente cpt_echo et cpt_echo_final
int passage=0;		// temps de passage de l'echo précédent
