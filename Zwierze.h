//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_ZWIERZE_H
#define PO1_ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm {
private:
    int inicjatywa;
public:
    Zwierze(int sila, int ini, Point point, Swiat *swiat) : Organizm(sila, point, swiat, TRUE), inicjatywa(ini) {}

    string getNazwe() override;
    //virtual void rozmnazanie();
    virtual void ruch();
    int getIni();

    char symbolOrg() override;

    void akcja() override;

};


#endif //PO1_ZWIERZE_H
