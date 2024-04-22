//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_ORGANIZM_H
#define PO1_ORGANIZM_H

#include <iostream>
#include "Point.h"
#include "Stale.h"

class Swiat;

class Organizm {
private:
    int inicjatywa;
    int wiek;
    Swiat *swiat;
    int czyZwierze;
protected:
    Point point;
public:
    Organizm(int ini, Point point, Swiat *swiat, int czyZwierze) : czyZwierze(czyZwierze), wiek(0), inicjatywa(ini), point(point), swiat(swiat) {}

    virtual void akcja();

    void rysowanie();

    virtual char symbolOrg();
    void kolizja(Organizm *other);
    //virtual void wyswietlInfo();

    int getX();
    int getY();
    int getIni();
    int getWiek();
    int getCzyZwierze();
    virtual string getNazwe();
    Swiat *getSwiat();

    int walidacjaRuchu(int x, int y);
    void starszyWiek();

};


#endif //PO1_ORGANIZM_H
