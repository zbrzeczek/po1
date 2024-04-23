//
// Created by Zuza on 2024-04-11.
//

#include "Swiat.h"
#include "Antylopa.h"

string Antylopa::getNazwe() {
    return "Antylopa";
}

bool Antylopa::ucieczka(Organizm *other) {
    int random = rand() % 2;
    if (random == 0){
        ucieczkaPole();
        getSwiat()->addKom("Antylopa uciekla przed: " + other->getNazwe() + other->getPoint());
        return true;
    }
    return false;
}

void Antylopa::ruch() {
    int los, x, y;
    int losowanie = TRUE;

    while (losowanie) {
        x = getX();
        y = getY();
        los = rand() % 4;

        losowanie = FALSE;
        switch (los) {
            case GORA:
                if(getY() - 2 >= 0) this->changePos(y-2,x);
                else losowanie = TRUE;
                break;
            case DOL:
                if(getY() + 2 < getSwiat()->getHeight()) this->changePos(y+2,x);
                else losowanie = TRUE;
                break;
            case PRAWO:
                if(getX() + 2 < getSwiat()->getWidth()) this->changePos(y,x+2);
                else losowanie = TRUE;
                break;
            case LEWO:
                if(getX() - 2 > 0) this->changePos(y,x-2);
                else losowanie = TRUE;
                break;
            default:
                break;
        }
    }
}

void Antylopa::rozmnazanie() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Antylopa* nowa = new Antylopa(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Pojawilo sie nowe zwierze: Antylopa");
}

char Antylopa::symbolOrg() {
    return 'A';
}