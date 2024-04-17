//
// Created by Zuza on 2024-04-11.
//

#ifndef PO1_TRAWA_H
#define PO1_TRAWA_H

#include "Roslina.h"

class Trawa : public Roslina{
public:
    Trawa(Point point, Swiat* swiat) : Roslina(0, point, swiat) {}

    void rozprz() override;

    char symbolOrg() override;
};


#endif //PO1_TRAWA_H
