
#include "globaldefine.h"
#include "global.h"


void affichage () {
	
	int x;
	int y;
	lcd_clear(Cyan);															//Fond de couleur Cyan
	LCD_write_english(33,32,'1',Black,Cyan);			//Ecriture des chiffres
	LCD_write_english(115,32,'2',Black,Cyan);
	LCD_write_english(195,32,'3',Black,Cyan);
	LCD_write_english(33,112,'4',Black,Cyan);
	LCD_write_english(115,112,'5',Black,Cyan);
	LCD_write_english(195,112,'6',Black,Cyan);
	LCD_write_english(33,192,'7',Black,Cyan);
	LCD_write_english(115,192,'8',Black,Cyan);
	LCD_write_english(195,192,'9',Black,Cyan);
	LCD_write_english(115,272,'0',Black,Cyan);
	n=sprintf(chaine,"Retour");
	LCD_write_english_string(16,272,chaine,Black,Cyan);			//Bouton retour
	n=sprintf(chaine,"Valider");
	LCD_write_english_string(173,272,chaine,Black,Cyan);		//Bouton de validation
	
	for (x=0;x<240;x=x+5) {												//Délimitation des touches
		LCD_write_english(x,73,'-',Black,Cyan);
		LCD_write_english(x,153,'-',Black,Cyan);
		LCD_write_english(x,233,'-',Black,Cyan);
	}
	
	for (y=0;y<320;y=y+8) {
		LCD_write_english(75,y,'|',Black,Cyan);
		LCD_write_english(155,y,'|',Black,Cyan);
	}
	
}


void initialisation_variables_ecran () {

	ecran_appui=0;						//Variable passant à 1 lorsqu'il vient d'y avoir un appui
	for (i=0;i<4;i++) {
		password[i]=0;					//Mise à zéro du tableau recevant le mot de passe entré
	}
	x_position=0;							//Initialisation du x de l'appui sur l'écran
	y_position=0;							//Initialisation du y de l'appui sur l'écran
	numero=0;									//Initialisation de la position du prochain chiffre entré du mot de passe

}


void initialisation_ecran () {
	
	lcd_Initializtion();								//Initialisation de l'écran LCD
	initialisation_variables_ecran();		//Initialisation des variables utilisées par l'écran
	affichage();												//Initialisation de l'affichage des touches
	touch_init();												//Initialisation du contrôleur tactile de l'écran LCD

}


void valider() {
	
	if (numero==4) {
		if (password[0]==1 && password[1]==2 && password[2]==3 && password[3]==4) {	//Mot de passe juste
			tsOpen=1;		//Ouverture du verrou
			n=sprintf(chaine,"Deverrouillage");
			LCD_write_english_string(62,300,chaine,Black,Cyan);
		} else {	//Mot de passe faux
			n=sprintf(chaine,"Erreur de mot de passe");
			LCD_write_english_string(35,300,chaine,Black,Cyan);
		}
	}
	
	else {
		n=sprintf(chaine,"Erreur de mot de passe");
		LCD_write_english_string(35,300,chaine,Black,Cyan);	//Mot de passe incomplet
	}
	
	validation=1;
	initialisation_variables_ecran();
	
}


void update_password () {
	
	if (x_position>300 && x_position<1450) {			//Touches de gauche
		if (y_position>2900 && y_position<3800) {
			password[numero]=1;
			numero++;
		}
		if (y_position>2000 && y_position<2900) {
			password[numero]=4;
			numero++;
		}
		if (y_position>1100 && y_position<2000) {
			password[numero]=7;
			numero++;
		}
		if (y_position>200 && y_position<1100) {		//Touche retour
			if (numero>0) {
				numero--;
			}
		}
	}
	
	if (x_position>1450 && x_position<2600) {			//Touches du milieu
		if (y_position>2900 && y_position<3800) {
			password[numero]=2;
		}
		if (y_position>2000 && y_position<2900) {
			password[numero]=5;
		}
		if (y_position>1100 && y_position<2000) {
			password[numero]=8;
		}
		if (y_position>200 && y_position<1100) {
			password[numero]=0;
		}
		numero++;
	}
	
	if (x_position>2600 && x_position<3750) {			//Touches de droite
		if (y_position>2900 && y_position<3800) {
			password[numero]=3;
			numero++;
		}
		if (y_position>2000 && y_position<2900) {
			password[numero]=6;
			numero++;
		}
		if (y_position>1100 && y_position<2000) {
			password[numero]=9;
			numero++;
		}
		if (y_position>200 && y_position<1100) {	//Touche de validation
			valider();
		}
	}
	
}
