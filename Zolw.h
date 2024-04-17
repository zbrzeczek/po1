//
// Created by Zuza on 2024-04-11.
//

#ifndef PO1_ZOLW_H
#define PO1_ZOLW_H

#include "Zwierze.h"

class Zolw : public Zwierze{
public:
    Zolw(Point point, Swiat* swiat) : Zwierze(2, 1, point, swiat) {}

    void ruch() override;
    //void rozmnazanie() override;

    char symbolOrg() override;
};


#endif //PO1_ZOLW_H
