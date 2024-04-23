//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#ifndef PO1_GUARANA_H
#define PO1_GUARANA_H

#include "Roslina.h"

class Guarana : public Roslina{
public:
    Guarana(Point point, Swiat* swiat) : Roslina(0, point, swiat) {}

    string getNazwe() override;

    void akcja() override;
    void rozprz() override;

    char symbolOrg() override;
};


#endif //PO1_GUARANA_H
