//
// Created by Zuza on 2024-04-03.
//

#include "Czlowiek.h"

void Czlowiek::changePos(int yAdd, int xAdd) {
    point.x += xAdd;
    point.y += yAdd;
}

void Czlowiek::ruch() {
    char ch;
    cin >> ch;
    switch (ch) {
        case 'w':
            changePos(-1,0);
            break;
        case 's':
            changePos(1,0);
            break;
        case 'd':
            changePos(0,1);
            break;
        case 'a':
            changePos(0,-1);
            break;
        default:
            break;
    }
}

//void Czlowiek::rozmnazanie() {

//}

char Czlowiek::symbolOrg() {
    return 'C';
}

//void Czlowiek::wyswietlInfo() {

//}