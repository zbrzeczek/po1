//
// Created by Zuza on 2024-04-08.
//

#ifndef PO1_WILK_H
#define PO1_WILK_H

#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(Point point, Swiat* swiat) : Zwierze(9, 5, point, swiat) {}

    string getNazwe() override;
    void rozmnazanie() override;
    char symbolOrg() override;
};


#endif //PO1_WILK_H
