//
// Created by Zuza on 2024-04-09.
//

#include "Swiat.h"
#include "Owca.h"

string Owca::getNazwe() {
    return "Owca";
}
void Owca::rozmnazanie() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Owca* nowa = new Owca(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Pojawilo sie nowe zwierze: Owca");
}
char Owca::symbolOrg() {
    return 'O';
}