//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_CZLOWIEK_H
#define PO1_CZLOWIEK_H


#include "Zwierze.h"

using namespace std;

class Czlowiek : public Zwierze {
public:
    Czlowiek(Point point, Swiat* swiat) : Zwierze(5, 4, point, swiat) {}

    void changePos(int yAdd, int xAdd);

    void ruch() override;
    //void rozmnazanie() override;

    void rysowanie() override;
    //void wyswietlInfo() override;

};


#endif //PO1_CZLOWIEK_H
