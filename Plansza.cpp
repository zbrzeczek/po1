//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#include "Plansza.h"

void Plansza::addOrgDoPlanszy(int x, int y, Organizm *nowy) {
    planszaOrg[x][y] = nowy;
}

Plansza::~Plansza(){

}
