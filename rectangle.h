/************************************************************************************
* Auteur : Nicolas Garant *
* Nom : snake.h *
* Date : 30 mars 2021 *
* Description : L'objet snake implémenté avec un tableau primitif de point et une *
* taille pouvant se déplacer pour être intégré dans le jeu snake *
************************************************************************************/
#pragma once

#include "point.h"

class rectangle {
private:
    point _coord;
    int _h;
    int _l;
public:
    //Constructeurs
    rectangle();                                    //Sans paramètres
    rectangle(int h, int l);                        //Avec largeur/hauteur
    rectangle(int x, int y, int h = 0, int l = 0);  //Avec x/y/hauteur/largeur
    rectangle(const point &coord, int h = 0, int l = 0);   //avec coord hauteur largeur
    rectangle(const rectangle &r);                  //Avec rectangle


    //Destructeur
    ~rectangle();                                   //Destucteur

    //Setteurs
    void setHauteur(int h);                         //Hauteur
    void setLargeur(int l);                         //Largeur
    void setX(int x);                               //X
    void setY(int Y);                               //X
    void setCoord(int x, int y);                    //Point
    void setRectangle(int x, int y, int h, int l);  //Rectangle au complet

    //Getteur
    int getHauteur() const;         //Hauteur
    int getLargeur() const;         //Largeur
    point &getPosition();           //Point

    //Affichage et lecture
    void draw(ostream &output);             //affichage rectangle
    void read(istream &input);              //lecture cin
    void print(ostream &output) const;      //affichage cout

    //surcharge des opérateurs
    bool operator==(const rectangle &r);    //opérateur ==
    bool operator!=(const rectangle &r);    //opérateur !=
    bool operator<(const rectangle &r);     //opérateur <
    bool operator>(const rectangle &r);     //opérateur >
    bool operator<=(const rectangle &r);    //opérateur <
    bool operator>=(const rectangle &r);    //opérateur >

    //calculs
    float surface() const;                    //Calcul de la surface (aire)
    float perimetre() const;                  //Calcul du périmètre
};

istream &operator>>(istream &input, rectangle &r);            //opérateur >>
ostream &operator<<(ostream &output, const rectangle &r);     //opérateur <<

void ligne(rectangle r, int nb);        //Affichage de ligne
void triangle(rectangle r, int nb);     //Affichage de triangle
void grille(rectangle r, int nb);       //Affichage de grille