/* En-tête de programme
 ==========================================
Programme:		point.h
Acteur:			Frederick Perazzelli-Delorme et Nicolas Garant
Date de création:	
But du programme:	Méthodes et prototypes de l'objet pomme;
====================================================== */

/* directive au pré-processeur
-------------------------------*/
#include<iostream>
#include"point.h"
#include"pomme.h"

//	Construteur pomme par défaut;
pomme::pomme() {
//    _pomme.setX(0);
//    _pomme.setY(0);
    _pomme.setPosition(0, 0);
    _pomme.setColor(4);
}

//	Constructeur pomme avec variable;
pomme::pomme(int x, int y) {
//    _pomme.setX(x);
//    _pomme.setY(y);
    _pomme.setPosition(x, y);
    _pomme.setColor(4);
}

//	Destructeur de pomme;
pomme::~pomme() {
    _pomme.setX(0);
    _pomme.setY(0);
    _pomme.setColor(0);
}

//	Getteur de pomme;
const point &pomme::getPosition() const {
    return _pomme;
}


//	Setteur de pomme;
void pomme::setPosition(int x, int y) {
    _pomme.setX(x);
    _pomme.setY(y);
    _pomme.setColor(4);
}

//	Dessine la pomme;
void pomme::draw(ostream &output) const {
    _pomme.draw(output);
//    gotoxy(_pomme.getX(), _pomme.getY());
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//    cout << "\xFE";
}

//	Operator output;
ostream &operator<<(ostream &output, const pomme &p) {
    p.draw(output);
    return output;
}
