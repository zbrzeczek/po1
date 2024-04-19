//
// Created by Zuza on 2024-04-03.
//

#include "Swiat.h"
#include "Zwierze.h"

int Zwierze::getSila() {
    return sila;
}
void Zwierze::changePos(int y, int x) {

    point.x += x;
    point.y += y;
}
void Zwierze::ruch() {
    int los;
    int losowanie =TRUE;
    while (losowanie) {
        los = rand() % 4;

        losowanie = FALSE;
        switch (los) {
            case GORA:
                if (walidacjaRuchu(0, -1) == POLE_PUSTE) changePos(-1, 0);
                else if (walidacjaRuchu(0, -1) == KOLIZJA) {
                    if (kolizja(getSwiat()->getPolePlanszy(point.x, point.y-1))) changePos(-1, 0);
                }
                else losowanie = TRUE;
                break;
            case DOL:
                if (walidacjaRuchu(0, 1) == POLE_PUSTE) changePos(1, 0);
                else if (walidacjaRuchu(0, 1) == KOLIZJA){
                    if (kolizja(getSwiat()->getPolePlanszy(point.x, point.y+1))) changePos(1, 0);
                }
                else losowanie = TRUE;
                break;
            case PRAWO:
                if (walidacjaRuchu(1, 0) == POLE_PUSTE) changePos(0, 1);
                else if (walidacjaRuchu(1, 0) == KOLIZJA){
                    if (kolizja(getSwiat()->getPolePlanszy(point.x +1, point.y))) changePos(0, 1);
                }
                else losowanie = TRUE;
                break;
            case LEWO:
                if (walidacjaRuchu(-1, 0) == POLE_PUSTE) changePos(0, -1);
                else if (walidacjaRuchu(-1, 0) == KOLIZJA) {
                    if (kolizja(getSwiat()->getPolePlanszy(point.x -1, point.y))) changePos(0, -1);
                }
                else losowanie = TRUE;
                break;
            default:
                break;
        }
    }
}

char Zwierze::symbolOrg() {
    return ' ';
}

void Zwierze::akcja() {
    ruch();
}
