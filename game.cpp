//
// Created by nicol on 31/mars/2021.
//

#include "game.h"

game::game() {
    _lose = false;
    _dir = NONE;
    _cptLive = 3;
    _score = 0;

}

void game::play() {
    //Variables
    game g;
    point pos;

    initialize();
    while (!_lose) {

        printScore(cout);
        inputKey();

        if (_dir != STOP) {
            pos = _bob.newPosition(_dir);
            if (!canMove(pos)) {
                _cptLive--;
                printLive(cout);
                if (_cptLive == 0) {
                    _lose = true;
                }
            } else if (pos == _pomme.getPosition()) {
                _bob.eat(_dir);
                _score++;
                printScore(cout);
                createApple();
            } else {
                _bob.newPosition(_dir);
            }
            _bob.draw(cout);
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



