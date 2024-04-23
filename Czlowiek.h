//
// Created by Zuza on 2024-04-03.
//

#ifndef PO1_CZLOWIEK_H
#define PO1_CZLOWIEK_H


#include "Zwierze.h"

using namespace std;

class Czlowiek : public Zwierze {
private:
    int coolDown;
    int dodatkowaSila;
public:
    Czlowiek(Point point, Swiat* swiat) : Zwierze(5, 4, point, swiat), coolDown(5), dodatkowaSila(10) {}

    string getNazwe() override;
    void ruch() override;
    void moc();

    int getCoolDown();

    char symbolOrg() override;

};


#endif //PO1_CZLOWIEK_H
