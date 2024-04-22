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
    int sila;
    int wiek;
    Swiat *swiat;
    int czyZwierze;
protected:
    Point point;
public:
    Organizm(int sila, Point point, Swiat *swiat, int czyZwierze) : czyZwierze(czyZwierze), wiek(0), sila(sila), point(point), swiat(swiat) {}

    virtual void akcja();

    void rysowanie();

    virtual char symbolOrg();
    void kolizja(Organizm *other);
    //virtual void wyswietlInfo();

    int getX();
    int getY();
    int getSila();
    void setSila(int ilosc);
    int getWiek();
    int getCzyZwierze();
    virtual string getNazwe();
    string getPoint();
    Swiat *getSwiat();

    int walidacjaRuchu(int y, int x);
    void starszyWiek();

};


#endif //PO1_ORGANIZM_H
