//
// Created by Zuza on 2024-04-11.
//

#include "Swiat.h"
#include "Trawa.h"

string Trawa::getNazwe() {
    return "Trawa";
}

void Trawa::akcja() {
    int prawdopodobienstwo = rand() % PRAWD_ROZSIANIA;
    if (prawdopodobienstwo == 0) {
        rozprz();
    }
}

void Trawa::rozprz() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Trawa* nowa = new Trawa(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Rozsianie Trawy");
}
char Trawa::symbolOrg() {
    return 't';
}