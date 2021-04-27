/* En-tête de programme
 ==========================================
Programme:		point.h
Acteur:			Frederick Perazzelli-Delorme et Nicolas Garant
Date de création:
But du programme:	
====================================================== */

/* directive au pré-processeur
-------------------------------*/
#include"point.h"
#include"game.h"
#include"rectangle.h"
#include"pomme.h"
#include"snake.h"

void game::play() {
    //Variables

    point pos;

    initialize();
    while (!_lose) {

        printScore(cout);
        printLive(cout);
        inputKey();

        if (_dir != STOP) {

            pos = _ekans.nouvellePosition(_dir);
            _ekans.move(_dir);

            if (!canMove(pos)) {

                _cptLive--;
                drawScreen(cout);

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

    if (_kbhit()) {                     //si une touche est appuyée
        touche = _getch();              //saisie la touche
        if (touche == 'q') {            //si la touche est q, on veut arrêter le jeu
            _lose = true;
            _dir = STOP;
        } else if (touche == 224) {       //si la touche est 224, c’est une flèche
            touche = _getch();          //dans le buffer on prend la 2e partie de la touche
            switch (touche) {
                case 75:                    //code ascii des flèches
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
                    break;
            }

        }
    }
}

//initialise les types primitifs à 0
game::game() {
    _lose = false;
    _dir = 0;
    _cptLive = 0;
    _score = 0;
}

//initialise les types primitifs à 0
game::~game() {
    _lose = false;
    _dir = 0;
    _cptLive = 0;
    _score = 0;

}

//initalise le jeu
void game::initialize() {
    _cptLive = 3;
    _ekans.initialize(_width / 2, _height / 2);
    _plateau.setLargeur(_width);
    _plateau.setHauteur(_height);
    srand(time(NULL));
    drawScreen(cout);
}

//génère une nouvelle position aléatoire ds le terrain
point game::randPosition() const {

    point p;
//    int x, y;
//
//
//    x = rand() % 37 + 2;    //Position random
//    y = rand() % 17 + 2;

    //Vérification que le rand n'est pas la position du snake
    p.setX(rand() % (_width - 2) + 1);
    p.setY(rand() % (_height - 2) + 1);
//    for (int i = 0; i < _ekans.getTaille(); ++i) {
//        if (x == _ekans[i].getX() && y == _ekans[i].getY()) {
//            x = rand() % 38 + 2;    //Position random
//            y = rand() % 17 + 2;
//        }
//    }
//    p.setPosition(x, y);
    return p;
}

//  Creation de la pomme;
void game::createApple() {
    _pomme.setPosition(randPosition().getX(), randPosition().getY());
    _pomme.draw(cout);
}

//  Peu tu bouger;
bool game::canMove(const point &p) const {

    if (_ekans.ifCollision(p)) {

        if ((p.getX() == 0 || p.getX() == _width - 1) || (p.getY() == 0 || p.getY() == _height - 1)) {

            return false;
        }
        for (int i = 1; i < _ekans.getTaille(); i++) {

            if (p == _ekans[i]) {

                return false;
            }
        }
    }
    return true;
}


// renvoie le score
int game::getScore() const {
    return _score;
}

// imprime le score
void game::printScore(ostream &output) const {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(0, 23);
    output << "Score : " << _score << endl;
}

// imprime le nombre de vie
void game::printLive(ostream &output) const {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(0, 24);
    output << "Vies restantes : " << _cptLive << endl;
}

// imprime game over
void game::printEndGame(ostream &ouput) const {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(0, 26);
    ouput << "Game Over" << endl << "Score : " << _score << endl;
}

void game::drawScreen(ostream &output) {
    system("cls");
    printScore(cout);
    printLive(cout);
    _ekans.initialize(_width / 2, _height / 2);
    _plateau.draw(cout);
    _ekans.draw(cout);
    createApple();
}
