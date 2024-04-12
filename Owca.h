//
// Created by Zuza on 2024-04-09.
//

#ifndef PO1_OWCA_H
#define PO1_OWCA_H

#include "Zwierze.h"

class Owca : public Zwierze{
public:
    Owca(int posX, int posY, Swiat* swiat) : Zwierze(4, 4, posX, posY, swiat) {}

    void ruch() override;
    //void rozmnazanie() override;

    void rysowanie() override;

};


#endif //PO1_OWCA_H
