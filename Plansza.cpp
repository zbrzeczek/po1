//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#include "Plansza.h"

Organizm *Plansza::getOrganizmZPlanszy(int x, int y) {
    return planszaOrg[y][x];
}

void Plansza::addOrgDoPlanszy(int x, int y, Organizm *nowy) {
    planszaOrg[y][x] = nowy;
}

void Plansza::wyczyscPlansze() {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            planszaOrg[i][j] = nullptr;
        }
    }
}

Plansza::~Plansza(){

}
