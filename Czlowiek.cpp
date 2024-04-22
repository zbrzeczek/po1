//
// Created by Zuza on 2024-04-03.
//

#include "Swiat.h"
#include "Czlowiek.h"

string Czlowiek::getNazwe() {
    return "Czlowiek";
}

void Czlowiek::ruch() {
    char ch;
    int x = point.x;
    int y = point.y;
    int wybieranie = TRUE;

    while (wybieranie) {
        wybieranie = FALSE;
        cin >> ch;

        switch (ch) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            case 'a':
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
        else wybieranie = TRUE;
    }
}

char Czlowiek::symbolOrg() {
    return 'C';
}
