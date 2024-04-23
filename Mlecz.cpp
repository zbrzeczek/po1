//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#include "Swiat.h"
#include "Mlecz.h"

string Mlecz::getNazwe() {
    return "Mlecz";
}
void Mlecz::akcja() {
    for (int i = 0; i < 3; i++) {
        int prawdopodobienstwo = rand() % PRAWD_ROZSIANIA;
        if (prawdopodobienstwo == 0) {
            rozprz();
        }
    }
}
char Mlecz::symbolOrg() {
    return 'm';
}

void Mlecz::rozprz() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Mlecz* nowa = new Mlecz(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Rozsianie mlecza");
}