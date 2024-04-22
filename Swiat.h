//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_SWIAT_H
#define PO1_SWIAT_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "Plansza.h"
#include "WszystkieOrg.h"
#include "Stale.h"

using  namespace std;

class Organizm;

class Swiat {
private:
    int width, height, liczbaOrg;
    //aha tu nwm co bo rosliny nie maja ini i sie nie ruszaja
    vector<Organizm *> organizmy;
    Plansza* planszaGry;
    int czyGameOver;
    vector<string> komentarze;
    int numKomentarzy;
protected:
    //vector od najmniejszej inicjatywy do najwiekszej
    vector<Organizm *> kolejkaAkcji;
public:

    Swiat(int width, int height, Plansza *plansza);

    int getWidth();
    int getHeight();
    int getGameOver();
    Plansza* getPlansza();
    Organizm* getPolePlanszy(int y, int x);
    void addKom(string kom);

    void addOrganizm(Organizm *nowy);
    void delOrganizm(Organizm* del);

    void sortKolejkeAkcji();
    void wykonajTure();
    void rysujSwiat();

    ~Swiat();
};


#endif //PO1_SWIAT_H
