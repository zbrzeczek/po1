//
// Created by Zuza on 2024-04-11.
//

#include "Swiat.h"
#include "Antylopa.h"

string Antylopa::getNazwe() {
    return "Antylopa";
}

void Antylopa::ruch() {
    int los, x, y;
    int losowanie = TRUE;

    while (losowanie) {
        los = rand() % 4;
        x = getX();
        y = getY();

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

        int walidacja = walidacjaRuchu(y, x);
        if (walidacja == POLE_PUSTE) changePos(y, x);
        else if (walidacja == KOLIZJA) {
            kolizja(getSwiat()->getPolePlanszy(y, x));
            changePos(y, x);
        }
        else losowanie = TRUE;
    }
}
char Antylopa::symbolOrg() {
    return 'A';
}