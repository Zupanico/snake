//===============//
//  Auteur :   Nicolas Garant
//  Lab :
//  Fichier :
//  Date :
//  But :
//===============//
#include "point.h"

point::point() {
    _x = _y = _color = 0;
}

//constructeur de point avec une position
point::point(int x, int y) {
    _x = x;
    _y = y;
    _color = 15; //couleur blanche par défaut
}

//constructeur avec point de postition et couleur
point::point(int x, int y, int color) {
    _x = x;
    _y = y;
    _color = color;
}

//constructeur avec point
point::point(const point &p) {
    _x = p._x;
    _y = p._y;
    _color = p._color;
}

//destructeur
point::~point() {
    _x = 0;
    _y = 0;
    _color = 7;
}

//getteur de x
int point::getX() const {
    return _x;
}

//getteur de y
int point::getY() const {
    return _y;
}

//getteur de la couleur
int point::getColor() const {
    return _color;
}

//setteur de x
void point::setX(int x) {
    assert(x >= 0);
    _x = x;
}

//setteur y
void point::setY(int y) {
    assert(y >= 0);
    _y = y;
}

//setteur de couleur
void point::setColor(int color) {
    assert(color >= 1 && color <= 15);
    _color = color;
}

//setteur de position
void point::setPosition(int x, int y) {
    setX(x);
    setY(y);
    setColor(7);

}

//surcharge d'opérateur ==
bool point::operator==(const point &p) {
    return (_x == p._x && _y == p._y);
}

//surcharge d'opérateur !=
bool point::operator!=(const point &p) {
    return (_x != p._x && _y != p._y);
}

//surcharge d'opérateur +
point point::operator+(const point &p) {

    _x = _x + p._x;
    _y = _y + p._y;
    return *this;
}

//surcharge d'opérateur -
point point::operator-(const point &p) {
    _x = _x - p._x;
    _y = _y - p._y;
    return *this;
}

//surcharge d'opérateur >>
istream &operator>>(istream &input, point &p) {
    p.read(input);
    return input;
}

//surcharge d'opérateur <<
ostream &operator<<(ostream &output, const point &p) {
    p.print(output);
    return output;
}

//équivalent cin
void point::read(istream &input) {
    char symbole;
    input >> symbole >> _x >> symbole >> _y >> symbole;
}

//équivalent cout
void point::print(ostream &output) const {
    output << "(" << _x << "," << _y << ")";
}

//Calcul de distance entre deux points
float distance(const point &p1, const point &p2) {
    return sqrt(pow(p2.getY() - p1.getY(), 2) + pow(p2.getX() - p1.getX(), 2));
}

void point::draw(ostream &output) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
    gotoxy(_x, _y);
    cout << "\xFE";             //on dessine un petit carré, à mettre ds le draw
}

void point::gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}

const point &point::operator=(const point &p) {
    _x = p._x;
    _y = p._y;
    _color = p._color;
    return *this;
}

//met le point dans la position de console
void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}

// Created by nicol on 20/mars/2021.
//

#include "point.h"

l