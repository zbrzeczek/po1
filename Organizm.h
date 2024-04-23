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
    int ini;
    int wiek;
    Swiat *swiat;
    bool czyZwierze;
    bool czyZabity;
protected:
    Point point;
    Point prevPoint;
public:
    Organizm(int sila,int ini , Point point, Swiat *swiat, int czyZwierze) : ini(ini), czyZwierze(czyZwierze), wiek(0), sila(sila), point(point), swiat(swiat) {}

    virtual void akcja();
    virtual void rozmnazanie();
    void walka(Organizm* other);
    virtual bool ucieczka(Organizm* other);
    virtual bool obroniony(Organizm* other);
    void cofnijRuch();

    void rysowanie();

    virtual char symbolOrg();
    void kolizja(Organizm *other);
    void ucieczkaPole();

    void setSila(int ilosc);
    void zabity(Organizm* oprawca);

    int getX();
    int getY();
    int getSila();
    int getIni();
    int getWiek();
    bool getCzyZwierze();
    bool getCzyZabity();
    virtual string getNazwe();
    string getPoint();
    Swiat *getSwiat();

    bool teSameOrg(Organizm *drugi);
    bool taSamaPozycja(Organizm *drugi);
    void changePos(int y, int x);

    void starszyWiek();
};


#endif //PO1_ORGANIZM_H
