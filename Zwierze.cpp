//
// Created by Zuza on 2024-04-03.
//

#include "Swiat.h"
#include "Zwierze.h"

string Zwierze::getNazwe() {
    return " ";
}

void Zwierze::rozmnazanie() {}

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
                if(getY() - 1 >= 0) this->changePos(y-1,x);
                else losowanie = TRUE;
                break;
            case DOL:
                if(getY() + 1 < getSwiat()->getHeight()) this->changePos(y+1,x);
                else losowanie = TRUE;
                break;
            case PRAWO:
                if(getX() + 1 < getSwiat()->getWidth()) this->changePos(y,x+1);
                else losowanie = TRUE;
                break;
            case LEWO:
                if(getX() - 1 > 0) this->changePos(y,x-1);
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
