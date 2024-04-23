//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#include "Swiat.h"
#include "WilczeJagody.h"

string WilczeJagody::getNazwe() {
    return "Wilcze jagody";
}

void WilczeJagody::akcja() {
    int prawdopodobienstwo = rand() % PRAWD_ROZSIANIA;
    if (prawdopodobienstwo == 0) {
        rozprz();
    }
}
void WilczeJagody::rozprz() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    WilczeJagody* nowa = new WilczeJagody(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Rozsianie Wilczych jagod");
}
char WilczeJagody::symbolOrg() {
    return 'w';
}