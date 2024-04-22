//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#ifndef PO1_MLECZ_H
#define PO1_MLECZ_H

#include "Roslina.h"

class Mlecz : public Roslina{
public:
    Mlecz(Point point, Swiat* swiat) : Roslina(0, point, swiat) {}

    string getNazwe() override;

    void rozprz() override;

    char symbolOrg() override;
};


#endif //PO1_MLECZ_H
