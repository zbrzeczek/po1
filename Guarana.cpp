//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#include "Swiat.h"
#include "Guarana.h"

string Guarana::getNazwe() {
    return "Guarana";
}

void Guarana::akcja() {
    int prawdopodobienstwo = rand() % PRAWD_ROZSIANIA;
    if (prawdopodobienstwo == 0) {
        rozprz();
    }
}
void Guarana::rozprz() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Guarana* nowa = new Guarana(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Rozsianie Guarany");
}
char Guarana::symbolOrg() {
    return 'g';
}