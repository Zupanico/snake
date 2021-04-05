/************************************************************************************
* Auteur : Nicolas Garant *
* Nom : snake.h *
* Date : 30 mars 2021 *
* Description : L'objet snake implémenté avec un tableau primitif de point et une *
* taille pouvant se déplacer pour être intégré dans le jeu snake *
************************************************************************************/

#include "snake.h"


snake::snake() {
    _taille = 6;
}

snake::snake(int x, int y) {

}

void snake::initialize(int x, int y) {

}


point snake::newPosition(int dir) {
    point newHead = _snake[0];

    switch (dir) {
        case 1: //gauche
            newHead.setX(newHead.getX() - 1);
            break;
        case 2: //droite
            newHead.setX(newHead.getX() + 1);
            break;
        case 3:
            newHead.setY(newHead.getY() - 1);
            break;
        case 4:
            newHead.setY(newHead.getY() + 1);
    }
    return newHead;
}

void snake::move(int dir) {
    point newHead = newPosition(dir);
    for (int i = _taille - 1; i >= 0; --i) {
        _snake[i + 1] = _snake[i];
    }
    _snake[0] = newHead;
}



