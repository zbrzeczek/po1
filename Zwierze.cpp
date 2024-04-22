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

        losowanie = ruchWalidacja(y, x);
    }
}

char Zwierze::symbolOrg() {
    return ' ';
}

void Zwierze::akcja() {
    ruch();
}
