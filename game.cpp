//
// Created by nicol on 31/mars/2021.
//

#include "game.h"


void game::play() {
    //Variables
    point pos;

    initialize();
    while (!_lose) {

        printScore(cout);
        inputKey();

        if (_dir != STOP) {
            pos = _ekans.nouvellePosition(_dir);
            if (!canMove(pos)) {
                _cptLive--;
                printLive(cout);
                if (_cptLive == 0) {
                    _lose = true;
                }
            } else if (pos == _pomme.getPosition()) {
                _ekans.eat(_dir);
                _score++;
                printScore(cout);
                createApple();
            } else {
                _ekans.nouvellePosition(_dir);
            }
            _ekans.draw(cout);
            Sleep(100);
        }
    }
    printEndGame(cout);
}

//Touches entrées, initialise la direction et le booléen _lose si Q est touché
void game::inputKey() {
    int touche;
    if (_kbhit()) {                 //si une touche est appuyée
        touche = _getch();          //saisie la touche
        if (touche == 'q') {        //si la touche est q, on veut arrêter le jeu
            _lose = true;
            _dir = STOP;
        } else if (touche == 224) { //si la touche est 224, c’est une flèche
            touche = _getch();      //dans le buffer on prend la 2e partie de la touche
            switch (touche) {
                case 75:            //code ascii des flèches
                    _dir = LEFT;
                    break;
                case 72:
                    _dir = UP;
                    break;
                case 80:
                    _dir = DOWN;
                    break;
                case 77:
                    _dir = RIGHT;
            }

        }
    }
}

//initialise les types primitifs à 0
game::game() {
    _lose = false;
    _dir = NONE;
    _cptLive = 3;
    _score = 0;
    _ekans.initialize(20, 7);
    _plateau.setLargeur(_width);
    _plateau.setHauteur(_height);
}

//initialise les types primitifs à 0
game::~game() {
    _lose = false;
    _dir = NONE;
    _cptLive = 0;
    _score = 0;
    _ekans.initialize(0, 0);
    _plateau.setLargeur(0);
    _plateau.setHauteur(0);
}

//initalise le jeu
void game::initialize() {
    _lose = false;
    _dir = NONE;
    _cptLive = 3;
    _score = 0;
    _ekans.initialize(20, 7);
    _plateau.setLargeur(_width);
    _plateau.setHauteur(_height);
    _plateau.draw(cout);
    createApple();
}

//génère une nouvelle position aléatoire ds le terrain
point game::randPosition() const {
    point p;
    int x, y;
    srand(time(NULL));

    x = rand() % 38 + 2;    //Position random
    y = rand() % 18 + 2;

    //Vérification que le rand n'est pas la position du snake
    for (int i = 0; i < _ekans.getTaille(); ++i) {
        if (x == _ekans.getPosition(i).getX() && y == _ekans.getPosition(i).getY()) {
            x = rand() % 39 + 1;    //Position random
            y = rand() % 19 + 1;
        }
    }

    p.setPosition(x, y);
    return p;
}

void game::createApple() {
    _pomme.setPosition(randPosition().getX(), randPosition().getY());
    _pomme.draw(cout);
}

bool game::canMove(const point &p) const {
    return (!(_ekans.ifCollision(p)));
}

int game::getScore() const {
    return _score;
}

void game::printScore(ostream &output) const {
    gotoxy(0, 22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    output << endl << "Score : " << _score << endl;
}

void game::printLive(ostream &output) const {
    gotoxy(0, 23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    output << endl << "Vies restantes : " << _cptLive << endl;
}

void game::printEndGame(ostream &ouput) const {
    gotoxy(0, 24);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    ouput << endl << "Game Over" << endl << "Score : " << _score;
}

