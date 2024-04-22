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
                kolizja(getSwiat()->getPolePlanszy(y, x));
                changePos(y, x);
            } else losowanie = TRUE;
        }
    }
}

char Zolw::symbolOrg() {
    return 'Z';
}