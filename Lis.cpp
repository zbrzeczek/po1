//
// Created by Zuza on 2024-04-18.
//

#include "Swiat.h"
#include "Lis.h"

string Lis::getNazwe() {
    return "Lis";
}

void Lis::ruch() {
    int los, x, y;
    int losowanie = TRUE;

    while (losowanie) {
        x = getX();
        y = getY();
        los = rand() % 4;

        losowanie = FALSE;
        switch (los) {
            case GORA:
                if(getY() - 1 >= 0) y--;
                else losowanie = TRUE;
                break;
            case DOL:
                if(getY() + 1 < getSwiat()->getHeight()) y++;
                else losowanie = TRUE;
                break;
            case PRAWO:
                if(getX() + 1 < getSwiat()->getWidth()) x++;
                else losowanie = TRUE;
                break;
            case LEWO:
                if(getX() - 1 > 0) x--;
                else losowanie = TRUE;
                break;
            default:
                break;
        }
        Organizm *zmienna = getSwiat()->getPolePlanszy(y, x);

        if (zmienna != nullptr){
            if (zmienna->getSila() > this->getSila()) losowanie = TRUE;
            else this->changePos(y,x);
        }
        else this->changePos(y,x);
    }
}

void Lis::rozmnazanie() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Lis* nowa = new Lis(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Pojawilo sie nowe zwierze: Lis");
}

char Lis::symbolOrg() {
    return 'L';
}