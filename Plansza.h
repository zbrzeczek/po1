//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#ifndef PO1_PLANSZA_H
#define PO1_PLANSZA_H


#include <cstdlib>
#include <iostream>
#include "Organizm.h"

using namespace std;

class Plansza {
private:
    vector <vector<Organizm*>> planszaOrg;
public:
    Plansza(int width, int height);

    ~Plansza();
};


#endif //PO1_PLANSZA_H
