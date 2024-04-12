//
// Created by Zuza on 2024-04-11.
//

#ifndef PO1_ANTYLOPA_H
#define PO1_ANTYLOPA_H

#include "Zwierze.h"

class Antylopa : public Zwierze{
public:
    Antylopa(int posX, int posY, Swiat* swiat) : Zwierze(2, 1, posX, posY, swiat) {}

    void ruch() override;
    //void rozmnazanie() override;

    void rysowanie() override;
};


#endif //PO1_ANTYLOPA_H
