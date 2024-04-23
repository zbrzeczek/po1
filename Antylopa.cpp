//
// Created by Zuza on 2024-04-11.
//

#include "Swiat.h"
#include "Antylopa.h"

string Antylopa::getNazwe() {
    return "Antylopa";
}

bool Antylopa::ucieczka(Organizm *other) {
    int random = rand() % 2;
    if (random == 0){
        ucieczkaPole();
        getSwiat()->addKom("Antylopa uciekla przed: " + other->getNazwe());
        return true;
    }
    return false;
}

void Antylopa::ruch() {
    int los, x, y;
    int losowanie = TRUE;

    while (losowanie) {
        los = rand() % 4;
        x = getX();
        y = getY();

        losowanie = FALSE;
        switch (los) {
            case GORA:
                y -= 2;
                break;
            case DOL:
                y += 2;
                break;
            case PRAWO:
                x += 2;
                break;
            case LEWO:
                x -= 2;
                break;
            default:
                break;
        }

        losowanie = ruchWalidacja(y, x);
    }
}
char Antylopa::symbolOrg() {
    return 'A';
}