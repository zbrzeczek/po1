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
                y--;
                break;
            case DOL:
                y++;
                break;
            case PRAWO:
                x++;
                break;
            case LEWO:
                x--;
                break;
            default:
                break;
        }

        int walidacja = walidacjaRuchu(y, x);
        if (walidacja == POLE_PUSTE) changePos(y, x);
        else if (walidacja == KOLIZJA) {
            if(getSwiat()->getPolePlanszy(y, x)->getCzyZwierze()) {
                Zwierze *zmienna = dynamic_cast<Zwierze*>(getSwiat()->getPolePlanszy(y, x));
                if (zmienna->getSila() > this->getSila()) losowanie = TRUE;
                else {
                    kolizja(getSwiat()->getPolePlanszy(y, x));
                    changePos(y, x);
                }
            }
            else {
                kolizja(getSwiat()->getPolePlanszy(y, x));
                changePos(y, x);
            }
        }
        else losowanie = TRUE;
    }
}
char Lis::symbolOrg() {
    return 'L';
}