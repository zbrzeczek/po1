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
protected:
    Point point;
public:
    Organizm(int ini, Point point, Swiat *swiat) : wiek(0), inicjatywa(ini), point(point), swiat(swiat) {}

    virtual void akcja();
    virtual void kolizja(Organizm *other);

    void rysowanie();

    virtual char symbolOrg();
    //virtual void wyswietlInfo();

    int getX();
    int getY();
    int getIni();
    int getWiek();

    int walidacjaRuchu(int x, int y);
    void starszyWiek();

};


#endif //PO1_ORGANIZM_H
