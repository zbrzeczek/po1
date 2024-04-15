//
// Created by Zuza on 2024-04-11.
//

#ifndef PO1_TRAWA_H
#define PO1_TRAWA_H

#include "Roslina.h"

class Trawa : public Roslina{
public:
    Trawa(int posX, int posY, Swiat* swiat) : Roslina(0, 0, posX, posY, swiat) {}

    void rozprz() override;

    void rysowanie() override;
};


#endif //PO1_TRAWA_H
