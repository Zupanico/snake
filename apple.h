#include "point.h"
#include <iostream>
#include <assert.h>
#include <windows.h>

class apple {
private:
    point _apple; //position de la pomme
public:
    apple();                                //initialise la positon à 0 et couleur rouge
    apple(int x, int y);                    //initialise la position reçue
    void setPosition(int x, int y);         //initialise la pomme à la position reçue
    const point &getPosition() const;       //retourne la position de la pomme
    void draw(ostream &sortie) const;       //draw la pomme rouge
};

ostream &operator<<(ostream &sortie, const apple &a);