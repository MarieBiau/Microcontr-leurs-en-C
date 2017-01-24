// fichier contenant la d�claration des variables globales de l'application
// � inclure seulement dans le main

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
int finMessage=0; // variable � "1" si un message entier a �t� re�u

/*Ecran tactile*/
char bufferTX[16];		//buffer pour l'affichage sur uart0
int n;		//taille du message � envoyer (max 16)
char chaine[16];		//cha�ne pour l'affichage sur l'�cran
int i;		//it�rateur
int password[4];		//tableau recevant le mot de passe entr�
int numero;		//on r�cup�re le num�ro_i�me chiffre du mot de passe
uint16_t x_position;		//x de l'appui sur l'�cran
uint16_t y_position;		//y de l'appui sur l'�cran

/*Ultrason*/
int cpt_echo = 0;		// Temps � la r�ception d'un front montant de l'�cho
int cpt_echo_final = 0;		// Temps � la r�ception d'un front descendant de l'�cho
int globalT = 0;

/**********************************************************
************************* Flags ***************************
**********************************************************/
 
/*Flags "d'activation" des fonctions*/
int bipActive;		//activation du bip 
int ecran_appui;	//appui sur l'�cran tactile
int scrutecran;		//pour regarder s'il y a un appui sur l'�cran
int open = 0;			//flag code ultrason OK. si = 3 on ouvre le cadenas
int tsOpen = 0;		//flag code ecran OK

/*Flags "internes" des fonctions*/
//Bipper
int flagPer;		//pour faire une periode sur le bipper
int flagBip;		//pour alterner les bips
//Ecran tactile
int validation;	//pour faire dispara�tre le message de validation

/*Variables pour les dur�es pour l'actualisation des flags*/
//Bipper
int dureePer;		//pour la fonction periode
int dureeBip;		//pour la fonction bip
int dureeBipActive = 0;		// duree d'activation du bip

/***********************************************************Ultrason************************************************************/
int bouton_appui;		//1 si BP appuy�
int b=0;		// Variable d'appui
int compteur_init=0;		// compteur proportionnelle � globalTime0
int flag1;		// flag signalant que le pin24 est � 1
int flag2;		// flag signalant que le pin24 est � 0
int echo=0;		// Variable d'activation de l'�cho
float temps_ecoule;		// Diff�rence ente cpt_echo et cpt_echo_final
int passage=0;		// temps de passage de l'echo pr�c�dent
