//
// Created by Zuza on 2024-04-11.
//

#ifndef PO1_ZOLW_H
#define PO1_ZOLW_H

#include "Zwierze.h"

class Zolw : public Zwierze{
public:
    Zolw(Point point, Swiat* swiat) : Zwierze(2, 1, point, swiat) {}

    string getNazwe() override;
    bool obroniony(Organizm* other) override;
    void rozmnazanie() override;
    void ruch() override;
    char symbolOrg() override;
};


#endif //PO1_ZOLW_H
