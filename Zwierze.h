//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_ZWIERZE_H
#define PO1_ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm {
public:
    Zwierze(int sila, int ini, Point point, Swiat *swiat) : Organizm(sila, ini, point, swiat, TRUE){}

    string getNazwe() override;
    void rozmnazanie() override;
    virtual void ruch();
    int getIni();

    char symbolOrg() override;

    void akcja() override;

};


#endif //PO1_ZWIERZE_H
