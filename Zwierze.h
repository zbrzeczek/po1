//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_ZWIERZE_H
#define PO1_ZWIERZE_H

#include <iostream>
#include "Organizm.h"

class Zwierze : public Organizm {
public:
    Zwierze(int sila, int ini, int posX, int posY, Swiat *swiat) : Organizm(sila, ini, posX, posY, swiat) {}

    //virtual void rozmnazanie();
    virtual void ruch();

    void rysowanie() override;

    void akcja() override {
        ruch();
    }
    //void kolizja(Organizm *other) override {
        //rozmnazanie();
    //}

};


#endif //PO1_ZWIERZE_H
