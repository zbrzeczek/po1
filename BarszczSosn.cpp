//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#include "Swiat.h"
#include "BarszczSosn.h"

string BarszczSosn::getNazwe() {
    return "Barszcz sosnowskiego";
}
void BarszczSosn::akcja() {
    zabijDookola();
    int prawdopodobienstwo = rand() % PRAWD_ROZSIANIA;
    if (prawdopodobienstwo == 0) {
        rozprz();
    }
}

void BarszczSosn::zabijDookola() {
    Organizm* zmienna;
    int x = getX();
    int y = getY();

    zmienna = getSwiat()->getPolePlanszy(y+1,x);

    if (zmienna != nullptr){
        if (zmienna->getCzyZwierze()){
            getSwiat()->usunOrg(zmienna);
        }
    }

    zmienna = getSwiat()->getPolePlanszy(y-1,x);

    if (zmienna != nullptr){
        if (zmienna->getCzyZwierze()){
            getSwiat()->usunOrg(zmienna);
        }
    }

    zmienna = getSwiat()->getPolePlanszy(y,x+1);

    if (zmienna != nullptr){
        if (zmienna->getCzyZwierze()){
            getSwiat()->usunOrg(zmienna);
        }
    }

    zmienna = getSwiat()->getPolePlanszy(y,x-1);

    if (zmienna != nullptr){
        if (zmienna->getCzyZwierze()){
            getSwiat()->usunOrg(zmienna);
        }
    }
}
void BarszczSosn::rozprz() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    BarszczSosn* nowa = new BarszczSosn(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Rozsianie Barszczu Sosnowskiego");
}
char BarszczSosn::symbolOrg() {
    return 'b';
}