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
    int czyGameOver;
    int numKomentarzy;
    //aha tu nwm co bo rosliny nie maja ini i sie nie ruszaja
    vector<Organizm *> organizmy;
    Czlowiek *czlowiek;
    Plansza* planszaGry;
    vector<string> komentarze;
public:

    Swiat(int width, int height, Plansza *plansza);

    void setCzlowiek(Czlowiek *czlowiek);

    int getWidth();
    int getHeight();
    int getGameOver();
    int getNumOrg();
    Plansza* getPlansza();
    Czlowiek* getCzlowiek();
    vector<Organizm*> getOrganizmy();
    Organizm* getPolePlanszy(int y, int x);
    void addKom(string kom);

    void addOrganizm(Organizm *nowy);
    void usunOrg(Organizm * del);
    void usunZabite();
    void kolizje();
    void znajdzWolnePole(int *y, int *x);

    void wykonajTure();
    void rysujSwiat();
    void wyczysc();


    ~Swiat();
};


#endif //PO1_SWIAT_H
