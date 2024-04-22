//
// Created by Zuza on 2024-04-03.
//

#include "Swiat.h"
#include "Zwierze.h"

string Zwierze::getNazwe() {
    return " ";
}
int Zwierze::getIni() {
    return inicjatywa;
}
void Zwierze::changePos(int y, int x) {

    point.x = x;
    point.y = y;
}
void Zwierze::ruch() {
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
            kolizja(getSwiat()->getPolePlanszy(x, y));
            changePos(y, x);
        }
        else losowanie = TRUE;
    }
}

char Zwierze::symbolOrg() {
    return ' ';
}

void Zwierze::akcja() {
    ruch();
}
