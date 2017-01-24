// fichier contenant l'importation des variables globales de l'application
// � inclure dans les autres fichiers que le main

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
extern int finMessage; // variable � "1" si un message entier a �t� re�u
extern int lg_message;

/*Ecran LCD tactile*/
extern char bufferTX[16];		//buffer pour l'affichage sur uart0
extern int n; 		//taille du message � envoyer (max 16)
extern char chaine[16];		//cha�ne pour l'affichage sur l'�cran
extern int i;		//it�rateur
extern int password[4];		//tableau recevant le mot de passe entr�
extern int numero;		//on r�cup�re le num�ro_i�me chiffre du mot de passe
extern uint16_t x_position;		//x de l'appui sur l'�cran
extern uint16_t y_position;		//y de l'appui sur l'�cran

/*Ultrason*/
extern int cpt_echo;		// Temps � la r�ception d'un front montant de l'�cho
extern int cpt_echo_final;		// Temps � la r�ception d'un front descendant de l'�cho
extern int globalT;

/**********************************************************
************************* Flags ***************************
**********************************************************/
 
/*Flags "d'activation" des fonctions*/
extern int bipActive;		//activation du bipper 
extern int ecran_appui;	//appui sur l'�cran tactile
extern int scrutecran;	//pour regarder s'il y a un appui sur l'�cran
extern int open;				//flag code ultrason OK. si = 3 on ouvre le cadenas
extern int tsOpen;			//flag code ecran OK
 
/*Flags "internes" des fonctions*/
//Bipper
extern int flagPer;			//pour faire une periode sur le bipper
extern int flagBip;			//pour alterner les bips
//Ecran tactile
extern int validation;	//pour faire dispara�tre le message de validation

/*Variables pour les dur�es pour l'actualisation des flags*/
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
