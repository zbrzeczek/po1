//
// Created by Zuza on 2024-04-18.
//

#include "Swiat.h"
#include "Lis.h"

string Lis::getNazwe() {
    return "Lis";
}

void Lis::ruch() {
    int los;
    int x = point.x;
    int y = point.y;
    int losowanie = TRUE;

    while (losowanie) {
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

        if (walidacjaRuchu(x, y) == POLE_PUSTE) changePos(y, x);
        else if (walidacjaRuchu(x, y) == KOLIZJA) {
            if(getSwiat()->getPolePlanszy(x, y)->getCzyZwierze()) {
                Zwierze *zmienna = dynamic_cast<Zwierze*>(getSwiat()->getPolePlanszy(x, y));
                if (zmienna->getSila() > this->getSila()) losowanie = TRUE;
                else {
                    kolizja(getSwiat()->getPolePlanszy(x, y));
                    changePos(y, x);
                }
            }
            else {
                kolizja(getSwiat()->getPolePlanszy(x, y));
                changePos(y, x);
            }
        }
        else losowanie = TRUE;
    }
}
char Lis::symbolOrg() {
    return 'L';
}