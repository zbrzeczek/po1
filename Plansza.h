//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#ifndef PO1_PLANSZA_H
#define PO1_PLANSZA_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include "Organizm.h"

using namespace std;

class Plansza {
private:
    vector <vector<Organizm*>> planszaOrg;
    int width, height;
public:
    Plansza(int width, int height) : height(height), width(width), planszaOrg(height, std::vector<Organizm*>(width, nullptr)) {}

    Organizm * getOrganizmZPlanszy(int x, int y);
    void addOrgDoPlanszy(int x, int y, Organizm *nowy);

    ~Plansza();
};


#endif //PO1_PLANSZA_H
