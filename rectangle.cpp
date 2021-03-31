//===============//
//  Auteur :   Nicolas Garant
//  Lab :
//  Fichier :
//  Date :
//  But :
//===============//
#include "rectangle.h"


rectangle::rectangle() {
    _l = _h = 0;
    _coord.setPosition(0, 0);
    _coord.setColor(15);
}

rectangle::rectangle(int h, int l) {
    _h = h;
    _l = l;
}

rectangle::rectangle(int x, int y, int h, int l) {
    _coord.setPosition(x, y);
    _l = l; //si ce constructeur est appelé avec seulement 2 int
    _h = h; //les 2 autres seront initialisés à 0
}

rectangle::rectangle(const point &coord, int h, int l) {
    _coord = coord;
    _l = l;
    _h = h;
}

rectangle::rectangle(const rectangle &r) {
    _h = r._h;
    _l = r._l;
    _coord = r._coord;
}

rectangle::~rectangle() {
    _l = 0;
    _h = 0;
}

int rectangle::getHauteur() const {
    return _h;
}

int rectangle::getLargeur() const {
    return _l;
}

point & rectangle::getPosition() {
    return _coord;
}

void rectangle::setHauteur(int h) {
    assert(h >= 0);
    _h = h;
}

void rectangle::setLargeur(int l) {
    assert(l >= 0);
    _l = l;
}

void rectangle::setX(int x) {
    _coord.setX(x);
}

void rectangle::setY(int y) {
    _coord.setY(y);
}

void rectangle::setCoord(int x, int y) {
    _coord.setPosition(x, y);
}

void rectangle::setRectangle(int x, int y, int h, int l) {
    setCoord(x, y);
    setHauteur(h);
    setLargeur(l);
}


void rectangle::draw(ostream &output) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _coord.getColor());
    gotoxy(_coord.getX(), _coord.getY());
    for (int i = 0; i < _l; ++i) {
        output << "*";
    }

    for (int i = 0; i < _h - 2; ++i) {
        gotoxy(_coord.getX(), _coord.getY() + (i + 1));
        output << "*";
        for (int j = 0; j < _l - 2; ++j) {
            output << " ";
        }
        output << "*";
    }

    gotoxy(_h - 1, _coord.getY());
    for (int i = 0; i < _l; ++i) {
        output << "*";
    }
}

void rectangle::read(istream &input) {
    char symbole;
    _coord.read(input);
    input >> symbole >> _l >> symbole >> symbole >> symbole >> _h;
}

void rectangle::print(ostream &output) const {
    output << _l << " X " << _h;
}

bool rectangle::operator==(const rectangle &r) {
    return (_l == r._l && _h == r._h && _coord.getY() == r._coord.getY() && _coord.getX() == r._coord.getX());
}

bool rectangle::operator!=(const rectangle &r) {
    return (_l != r._l && _h != r._h && _coord.getY() != r._coord.getY() && _coord.getX() != r._coord.getX());
}

bool rectangle::operator<(const rectangle &r) {
    return (_l < r._l && _h < r._h && _coord.getY() < r._coord.getY() && _coord.getX() < r._coord.getX());
}

bool rectangle::operator>(const rectangle &r) {
    return (_l > r._l && _h > r._h && _coord.getY() > r._coord.getY() && _coord.getX() > r._coord.getX());
}

bool rectangle::operator<=(const rectangle &r) {
    return (_l <= r._l && _h <= r._h && _coord.getY() <= r._coord.getY() && _coord.getX() <= r._coord.getX());
}

bool rectangle::operator>=(const rectangle &r) {
    return (_l >= r._l && _h >= r._h && _coord.getY() >= r._coord.getY() && _coord.getX() >= r._coord.getX());
}

float rectangle::surface() const {
    return _h * _l;
}

float rectangle::perimetre() const {
    return 2 * (_h + _l);
}

void rectangle::gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void ligne(rectangle r, int nb) {
    for (int i = 0; i < nb; ++i) {
        r.draw(cout);
        r.getPosition().setX(r.getPosition().getX() + r.getLargeur());
    }
}

void triangle(rectangle r, int nb) {
    for (int i = 0; i < nb; ++i) {
        ligne(r, i + 1);
        r.getPosition().setY(r.getPosition().getY() + r.getHauteur());
    }
}

void grille(rectangle r, int nb) {
    for (int i = 0; i < nb; ++i) {
        ligne(r, nb);
        r.getPosition().setY(r.getPosition().getY() + r.getHauteur());
    }
}

istream &operator>>(istream &input, rectangle &r) {
    r.read(input);
    return input;
}

ostream &operator<<(ostream &output, const rectangle &r) {
    r.print(output);
    return output;
}
