//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_SWIAT_H
#define PO1_SWIAT_H

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Plansza.h"
#include "WszystkieOrg.h"

/*//zwierzeta sa od najwiekszej inicjatywy
#define STADO_LISOW 0
#define STADO_WILKOW 1
#define */

using  namespace std;

class Organizm;

class Swiat {
private:
    int width, height;
    //aha tu nwm co bo rosliny nie maja ini i sie nie ruszaja
    vector<Organizm *> organizmy;
    Plansza* planszaGry;
public:

    Swiat(int width, int height, Plansza *plansza);

    int getWidth();
    int getHeight();
    Plansza* getPlansza();
    Organizm* getPolePlanszy(int x, int y);

    void addOrganizm(Organizm *nowy);
    void wykonajTure();
    void rysujSwiat();

};


#endif //PO1_SWIAT_H
