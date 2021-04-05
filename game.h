/************************************************************************************
* Auteur : Nicolas Garant *
* Nom : game.h *
* Date : 30 mars 2021 *
* Description : L'objet game implémente Le jeu snake en console où les flèches *
* servent à déplacer le snake dans l’écran pour manger les pommes, *
* mais attention de ne pas toucher les côté ou le snake lui-même *
*************************************************************************************/
//Directives aux préprocesseurs
#pragma once

#include <iostream>
#include <conio.h>
#include "rectangle.h"
#include "game.h"
#include "pomme.h"
#include "snake.h"
#include <windows.h>
#include <time.h>

using namespace std;

class game {
private:
    bool _lose;             //Si on perd
    int _dir,               //la direction choisie
    _cptLive,               //le compteur de vie
    _score;                 //le score de la game
    snake _bob;             //le snake
    pomme _pomme;           //la pomme
    rectangle _plateau;     //rectangle du terrain de jeu
    const int _width = 40;  //dimension du terrain de jeu
    const int _height = 20;
    enum direction {
        STOP, LEFT, RIGHT, UP, DOWN, NONE
    };
public:
    game();                 //initialise les types primitifs à 0
    ~game();                //initialise les types primitifs à 0
    void initialize();      //initalise le jeu
    point randPosition() const; //génère une nouvelle position aléatoire ds le terrain
    void createApple();     //génère une nouvelle pomme tq position est ds le snake
    void play();            //la main loop du jeu
    void inputKey();        //la saisie des touches pour le déplacement du snake
    bool canMove(const point &p) const;//retourne vrai si la tête du snake peut bouger
    int getScore() const;   //retourne le score (seule info qui pourrait être intéressante
    //de l’extérieur) et aucun setteur pour cet objet.
    void printScore(ostream &sortie) const;     //affiche le score
    void printLive(ostream &sortie) const;      //affiche le compteur de vie
    void printEndGame(ostream &sortie) const;   //affiche game over et le score
};