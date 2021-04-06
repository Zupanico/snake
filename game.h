/* En-tête de programme
 ==========================================
Programme:		point.h
Acteur:			Frederick Perazzelli-Delorme et Nicolas Garant
Date de création:
But du programme:	Méthodes et prototypes de l'objet game;
====================================================== */

/* directive au pré-processeur
-------------------------------*/
#pragma	once
#include<iostream>
#include<conio.h>
#include"rectangle.h"
#include"snake.h"
#include"pomme.h"
#include"point.h"
#include<windows.h>
#include<time.h>

using	namespace std;

class game {

    private:
        bool _lose;                 //Si on perd

        int _dir,                   //la direction choisie
            _cptLive,               //le compteur de vie
            _score;                 //le score de la game

        snake _ekans;               //le serpent
        pomme _pomme;               //la pomme

        rectangle _plateau;         //rectangle du terrain de jeu
        const int _width = 40;      //dimension du terrain de jeu
        const int _height = 20;     // Hauteur;

        enum direction { STOP, LEFT, RIGHT, UP, DOWN, NONE };


    public:

        game();                     //initialise les types primitifs à 0

        ~game();                    //initialise les types primitifs à 0

        void initialize();          //initalise le jeu

        point randPosition() const; //génère une nouvelle position aléatoire ds le terrain

        void createApple();         //génère une nouvelle pomme tq position est ds le snake

        void play();                //la main loop du jeu

        void inputKey();            //la saisie des touches pour le déplacement du snake

        bool canMove(const point& p) const; //retourne vrai si la tête du snake peut bouger

        int getScore() const;       //retourne le score (seule info qui pourrait être intéressante
                                    //de l’extérieur) et aucun setteur pour cet objet.

        void printScore(ostream& output) const;     //affiche le score
        void printLive(ostream& output) const;      //affiche le compteur de vie
        void printEndGame(ostream& output) const;   //affiche game over et le score
        void drawScreen(ostream& output);
};
