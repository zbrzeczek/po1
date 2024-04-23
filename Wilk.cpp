//
// Created by Zuza on 2024-04-08.
//

#include "Swiat.h"
#include "Wilk.h"

string Wilk::getNazwe() {
    return "Wilk";
}
void Wilk::rozmnazanie() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Wilk* nowa = new Wilk(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Pojawilo sie nowe zwierze: Wilk");
}
char Wilk::symbolOrg(){
    return 'W';
}