//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_ROSLINA_H
#define PO1_ROSLINA_H

#include "Organizm.h"

class Roslina : public Organizm {
public:
    Roslina(int sila, Point point, Swiat *swiat) : Organizm(sila, 0,  point, swiat, FALSE) {}

    string getNazwe() override;
    virtual void rozprz();

    char symbolOrg() override;

    void akcja() override;
};


#endif //PO1_ROSLINA_H
