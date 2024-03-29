/************************************************************************************
* Auteur : Nicolas Garant *
* Nom : snake.h *
* Date : 30 mars 2021 *
* Description : L'objet snake implémenté avec un tableau primitif de point et une *
* taille pouvant se déplacer pour être intégré dans le jeu snake *
************************************************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <cassert>
#include <cmath>
#include "point.h"

using namespace std;

class point {
private:


    int _x;
    int _y;
    int _color;

public:
    //constructeurs
    point();                            //constructeur sans paramètres
    point(int x, int y);                //Constructeur avec juste les x et y lala
    point(int x, int y, int color);     //constructeur avec paramètres
    point(const point &p);              //constructeur de copie

    //destructeur
    ~point();

    //getteur
    int getX() const;           //getteur de x
    int getY() const;           //getteur de y
    int getColor() const;       //getteur de color

    //setteur
    void setX(int x);           //setteur de x
    void setY(int y);           //setteur de y
    void setColor(int color);   //setteur de color
    void setPosition(int x, int y);//setteur de postition

    //surcharge des opérateurs
    bool operator==(const point &p) const;    //opérateur ==
    bool operator!=(const point &p) const;    //opérateur !=
    const point &operator=(const point &p);//opérateur=

    point operator+(const point &p) const;    //opérateur +
    point operator-(const point &p) const;    //opérateur -
    //operator>>
    //operator<<

    //autres méthodes
    void read(istream &input);          //lecture cin
    void print(ostream &output) const;  //affichage cout
    void draw(ostream &output) const;         //affiche le point
    friend float distance(const point &p1, const point &p2);//calcul de distance
};

void gotoxy(int xpos, int ypos);        //Placement du curseur au point

istream &operator>>(istream &input, point &p);      //opérateur >>
ostream &operator<<(ostream &output, const point &p);     //opérateur <<


