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
    Zwierze(int sila, int ini, Point point, Swiat *swiat) : Organizm(ini, point, swiat, TRUE), sila(sila) {}

    //virtual void rozmnazanie();
    virtual void ruch();
    int getSila();

    void changePos(int y, int x);
    char symbolOrg() override;

    void akcja() override;

};


#endif //PO1_ZWIERZE_H
