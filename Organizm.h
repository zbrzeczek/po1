//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_ORGANIZM_H
#define PO1_ORGANIZM_H

#include "Swiat.h"

class Swiat;

class Organizm {
private:
    int sila;
    int inicjatywa;
    Swiat *swiat;
protected:
    int x, y;
public:
    Organizm(int sila, int ini, int posX, int posY, Swiat *swiat) : sila(sila), inicjatywa(ini), x(posX), y(posY), swiat(swiat) {}

    virtual void akcja();
    //virtual void kolizja(Organizm *other);
    virtual void rysowanie();
    //virtual void wyswietlInfo();

    int getX();
    int getY();
    //int getSila();
    int getIni();
};


#endif //PO1_ORGANIZM_H
