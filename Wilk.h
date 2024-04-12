//
// Created by Zuza on 2024-04-08.
//

#ifndef PO1_WILK_H
#define PO1_WILK_H

#include "Zwierze.h"

class Wilk : public Zwierze{
public:
    Wilk(int posX, int posY, Swiat* swiat) : Zwierze(9, 4, posX, posY, swiat) {}

    void ruch() override;
    //void rozmnazanie() override;

    void rysowanie() override;
};


#endif //PO1_WILK_H