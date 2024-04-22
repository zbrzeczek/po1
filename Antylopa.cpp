//
// Created by Zuza on 2024-04-11.
//

#include "Swiat.h"
#include "Antylopa.h"

string Antylopa::getNazwe() {
    return "Antylopa";
}

void Antylopa::ruch() {
    int los;
    int x = point.x;
    int y = point.y;
    int losowanie = TRUE;

    while (losowanie) {
        los = rand() % 4;

        losowanie = FALSE;
        switch (los) {
            case GORA:
                y -= 2;
                break;
            case DOL:
                y += 2;
                break;
            case PRAWO:
                x += 2;
                break;
            case LEWO:
                x -= 2;
                break;
            default:
                break;
        }

        if (walidacjaRuchu(x, y) == POLE_PUSTE) changePos(y, x);
        else if (walidacjaRuchu(x, y) == KOLIZJA) {
            kolizja(getSwiat()->getPolePlanszy(x, y));
            changePos(y, x);
        }
        else losowanie = TRUE;
    }
}
char Antylopa::symbolOrg() {
    return 'A';
}