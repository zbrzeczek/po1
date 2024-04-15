//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_CZLOWIEK_H
#define PO1_CZLOWIEK_H


#include <iostream>
#include "Zwierze.h"

using namespace std;

class Czlowiek : public Zwierze {
public:
    Czlowiek(int posX, int posY, Swiat* swiat) : Zwierze(5, 4, posX, posY, swiat) {}

    void changePos(int yAdd, int xAdd);

    void ruch() override;
    //void rozmnazanie() override;

    void rysowanie() override;
    //void wyswietlInfo() override;

};


#endif //PO1_CZLOWIEK_H
