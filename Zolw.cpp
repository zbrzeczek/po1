//
// Created by Zuza on 2024-04-11.
//

#include "Swiat.h"
#include "Zolw.h"

string Zolw::getNazwe() {
    return "Zolw";
}

void Zolw::ruch() {
    int czyRuszy = 0;
    int los, x, y;
    int losowanie = TRUE;

    czyRuszy = rand() % 4;
    if (!czyRuszy) {
        while (losowanie) {
            x = getX();
            y = getY();
            los = rand() % 4;

            losowanie = FALSE;
            switch (los) {
                case GORA:
                    if(getY() - 1 >= 0) this->changePos(y-1,x);
                    else losowanie = TRUE;
                    break;
                case DOL:
                    if(getY() + 1 < getSwiat()->getHeight()) this->changePos(y+1,x);
                    else losowanie = TRUE;
                    break;
                case PRAWO:
                    if(getX() + 1 < getSwiat()->getWidth()) this->changePos(y,x+1);
                    else losowanie = TRUE;
                    break;
                case LEWO:
                    if(getX() - 1 > 0) this->changePos(y,x-1);
                    else losowanie = TRUE;
                    break;
                default:
                    break;
            }
        }
    }
}
void Zolw::rozmnazanie() {
    int zmiennaX = this->getX();
    int zmiennaY = this->getY();
    getSwiat()->znajdzWolnePole(&zmiennaY, &zmiennaY);

    Point zmienna;
    zmienna.x = zmiennaX;
    zmienna.y = zmiennaY;
    Zolw* nowa = new Zolw(zmienna, getSwiat());
    this->getSwiat()->addOrganizm(nowa);
    this->getSwiat()->addKom("Pojawilo sie nowe zwierze: Zolw");
}

bool Zolw::obroniony(Organizm *other) {
    if (other->getSila() < 5 && other->getSila() != 0) {
        getSwiat()->addKom("Zolw obronil atak " + other->getNazwe() + other->getPoint());
        return true;
    }
    else return false;
}

char Zolw::symbolOrg() {
    return 'Z';
}