/************************************************************************************
* Auteur : Nicolas Garant *
* Nom : game.h *
* Date : 30 mars 2021 *
* Description : L'objet game implémente Le jeu snake en console où les flèches *
* servent à déplacer le snake dans l’écran pour manger les pommes, *
* mais attention de ne pas toucher les côté ou le snake lui-même *
*************************************************************************************/
//Directives aux préprocesseurs

#include "game.h"
#include <iostream>

int main() {
    game g;

    g.play();

    system("pause");
    return 0;
}
