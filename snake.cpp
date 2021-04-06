/* En-tête de programme
 ==========================================
Programme:		point.h
Acteur:			Frederick Perazzelli-Delorme et Nicolas Garant
Date de création:
But du programme:	
====================================================== */

/* directive au pré-processeur
-------------------------------*/
#include "snake.h"


//	Constructeur du serpent par défaut
snake::snake() {
    _snake[0].setPosition(20, 7);
    _snake[1].setPosition(21, 7);
    _snake[2].setPosition(22, 7);
    _snake[3].setPosition(23, 7);
    _snake[4].setPosition(24, 7);
    _snake[5].setPosition(25, 7);
    _taille = 6;
}

// constructeur du serpent en recevant;
snake::snake(int x, int y) {
    _snake[0].setPosition(x, y);
    _snake[1].setPosition(x + 1, y);
    _snake[2].setPosition(x + 2, y);
    _snake[3].setPosition(x + 3, y);
    _snake[4].setPosition(x + 4, y);
    _snake[5].setPosition(x + 5, y);
    _taille = 6;
}

//	Destructeur du snake
snake::~snake() {
    _taille = 0;
}

//	Initialise le serpent
void snake::initialize(int x, int y) {
    snake s(x, y);
}

// Renvoie la tête du serpent
const point &snake::getHeadPosition() const {
    return _snake[0];
}

// renvoie la position du serpent
const point &snake::getPosition(int ind) const {
    return _snake[ind];
}

// operator pour aller chercher la position du serpent
const point &snake::operator[](int ind) const {
    return getPosition(ind);
}

//	Renvoie la taille du serpent
int snake::getTaille() const {
    return _taille;
}

//	Donne la nouvelle position de la tête du serpent;
point snake::nouvellePosition(int dir) {
    point newHead = _snake[0];

    switch (dir) {
        case 1:
            newHead.setX(newHead.getX() - 1);
            break;
        case 2:
            newHead.setX(newHead.getX() + 1);
            break;
        case 3:
            newHead.setY(newHead.getY() - 1);
            break;
        case 4:
            newHead.setY(newHead.getY() + 1);
            break;
    }
    return newHead;
}

//	Méthode collision du serpent;
bool snake::ifCollision(const point &pos) const {
    for (int i = 0; i < _taille; i++) {
        if (pos == _snake[i]) {
            return true;
        }
    }
    return false;
}

//	Fait bouger le serpent;
void snake::move(int dir) {
    point newHead = nouvellePosition(dir);

    for (int i = _taille - 1; i >= 0; --i) {
        _snake[i].setColor(6);
        _snake[i + 1] = _snake[i];

    }
    _snake[0] = newHead;
    _snake[_taille].setColor(0);
}

void snake::eat(int dir) {
    move(dir);
    _taille++;
}

//	Operator draw;
void snake::draw(ostream &output) const {
    for (int i = 0; i < _taille; i++) {
        gotoxy(_snake[i].getX(), _snake[i].getY());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        output << "\xFE";
    }
    gotoxy(_snake[_taille - 1].getX(), _snake[_taille - 1].getY());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    output << "\xFE";
}

//	Operator cout;
ostream &operator<<(ostream &output, const snake &s) {
    return output;
}