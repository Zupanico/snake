/* En-tête de programme
 ==========================================
Programme:		point.h
Acteur:			Frederick Perazzelli-Delorme et Nicolas Garant
Date de création:	
But du programme:	Méthodes et prototypes de l'objet pomme;
====================================================== */

/* directive au pré-processeur
-------------------------------*/
#pragma once

#include<iostream>
#include"point.h"
#include"rectangle.h"

class pomme {

	private:

		point _pomme;					//	Objet pomme;

	public:

		//	Constructeur;
		pomme();					//	Constructeur par défaut;
		pomme(int x, int y);				//	Constructeur avec variable;

		//	Destructeur;
		~pomme();					//	Destructeur de l'objet pomme;

		//	Getteur;
		const point& getPosition();			//	Getteur de la position de pomme;

		//	Setteur;	
		void setPosition(int x, int y);			//	Setteur de la position de la pomme;

		//	Autre Méthode;
		void draw(ofstream& output) const;		//	Dessine la pomme;


//	Operator;
ostream& operator<<(ostream& output, const pomme& p);		//	Operatour cout / output;
