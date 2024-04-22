//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#ifndef PO1_BARSZCZSOSN_H
#define PO1_BARSZCZSOSN_H

#include "Roslina.h"

class BarszczSosn : public Roslina{
public:
    BarszczSosn(Point point, Swiat* swiat) : Roslina(10, point, swiat) {}

    string getNazwe() override;

    void rozprz() override;

    char symbolOrg() override;
};


#endif //PO1_BARSZCZSOSN_H
