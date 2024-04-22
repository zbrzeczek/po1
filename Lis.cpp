//
// Created by Zuza on 2024-04-18.
//

#include "Swiat.h"
#include "Lis.h"

string Lis::getNazwe() {
    return "Lis";
}

void Lis::ruch() {
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
char Lis::symbolOrg() {
    return 'L';
}