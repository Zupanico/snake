/************************************************************************************
* Auteur : Nicolas Garant *
* Nom : snake.h *
* Date : 30 mars 2021 *
* Description : L'objet snake implémenté avec un tableau primitif de point et une *
* taille pouvant se déplacer pour être intégré dans le jeu snake *
************************************************************************************/
//Directives aux préprocesseurs
#pragma once

#include "point.h"
#include <iostream>
#include <assert.h>
#include <windows.h>

using namespace std;

class snake {
private:
    point _snake[800];          //tableau pour toutes les positions du snake
    int _size;                  //taille réel du snake
public:
    snake();                    //initialise le snake à l’origine, à partir d’une
    snake(int x, int y);        //position ou d’une coordonnée x, y et de taille 6
    ~snake();                   //remet le _size à 0
    void initialize(int x, int y);              //setteurs appelés par les constructeurs qui initialise
    const point &getHeadPosition() const;       //retourne la position de la tête du snake
    const point &getPosition(int ind) const;    //retourne la position à l’indice reçue
    const point &operator[](int ind) const;     //opérateur qui appelle getteur de position
    int getSize() const;                        //retourne la taille du snake
    point newPosition(int dir);                 //retourne la nouvelle position selon la direction
    bool ifCollision(const point &pos) const;   //retourne vrai si la position reçue est en
    //collision avec une des positions du snake
    void move(int dir);                         //avance le snake dans la bonne direction
    void eat(int dir);                          //avance et mange une pomme dans la direction
    void draw(ostream &sortie) const;           //draw le snake
};

ostream &operator<<(ostream &sortie, const snake &s);

