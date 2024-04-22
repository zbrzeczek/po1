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
    int los;
    int x = point.x;
    int y = point.y;
    int losowanie = TRUE;

    czyRuszy = rand() % 4;
    if (!czyRuszy) {
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
                kolizja(getSwiat()->getPolePlanszy(x, y));
                changePos(y, x);
            } else losowanie = TRUE;
        }
    }
}

char Zolw::symbolOrg() {
    return 'Z';
}