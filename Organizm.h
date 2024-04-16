//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_ORGANIZM_H
#define PO1_ORGANIZM_H

#include <iostream>
#include "Point.h"

class Swiat;

class Organizm {
private:
    int inicjatywa;
    Swiat *swiat;
protected:
    Point point;
public:
    Organizm(int ini, Point point, Swiat *swiat) : inicjatywa(ini), point(point), swiat(swiat) {}

    virtual void akcja();
    //virtual void kolizja(Organizm *other);
    virtual void rysowanie();
    //virtual void wyswietlInfo();

    int getX();
    int getY();
    int getIni();
};


#endif //PO1_ORGANIZM_H
