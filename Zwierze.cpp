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
            kolizja(getSwiat()->getPolePlanszy(y, x));
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
