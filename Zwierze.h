//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_ZWIERZE_H
#define PO1_ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm {
private:
    int sila;
public:
    Zwierze(int sila, int ini, Point point, Swiat *swiat) : Organizm(ini, point, swiat), sila(sila) {}

    //virtual void rozmnazanie();
    virtual void ruch();

    char symbolOrg() override;

    void akcja() override {
        ruch();
    }
    //void kolizja(Organizm *other) override {
        //rozmnazanie();
    //}

};


#endif //PO1_ZWIERZE_H
