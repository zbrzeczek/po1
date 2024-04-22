//
// Created by Zuzanna Brzęczek on 22/04/2024.
//

#ifndef PO1_WILCZEJAGODY_H
#define PO1_WILCZEJAGODY_H

#include "Roslina.h"

class WilczeJagody : public Roslina{
public:
    WilczeJagody(Point point, Swiat* swiat) : Roslina(99, point, swiat) {}

    string getNazwe() override;

    void rozprz() override;

    char symbolOrg() override;
};


#endif //PO1_WILCZEJAGODY_H
