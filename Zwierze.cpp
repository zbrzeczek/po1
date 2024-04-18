//
// Created by Zuza on 2024-04-03.
//

#include "Zwierze.h"

void Zwierze::changePos(int y, int x) {

    point.x += x;
    point.y += y;
}
void Zwierze::ruch() {
    int los;
    int losowanie =TRUE;
    while (losowanie) {
        los = rand() % 4;

        switch (los) {
            case GORA:
                if (walidacjaRuchu(0, -1)){
                    changePos(-1, 0);
                    losowanie = FALSE;
                }
                break;
            case DOL:
                if (walidacjaRuchu(0, 1)){
                    changePos(1, 0);
                    losowanie = FALSE;
                }
                break;
            case PRAWO:
                if (walidacjaRuchu(1, 0)){
                    changePos(0, 1);
                    losowanie = FALSE;
                }
                break;
            case LEWO:
                if (walidacjaRuchu(-1, 0)){
                    changePos(0, -1);
                    losowanie = FALSE;
                }
                break;
            default:
                break;
        }
    }
}

char Zwierze::symbolOrg() {

}

void Zwierze::akcja() {
    ruch();
}
void Zwierze::kolizja(Organizm *other) {
    
}