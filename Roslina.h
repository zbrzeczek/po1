//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_ROSLINA_H
#define PO1_ROSLINA_H

#include "Organizm.h"

class Roslina : public Organizm {
public:
    Roslina(int sila, int ini, int posX, int posY, Swiat *swiat) : Organizm(sila, ini, posX, posY, swiat) {}

    virtual void spread();

    //void akcja() override {
    //    spread();
    //}
};


#endif //PO1_ROSLINA_H