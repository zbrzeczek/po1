//
// Created by Zuza on 2024-04-11.
//

#ifndef PO1_ANTYLOPA_H
#define PO1_ANTYLOPA_H

#include "Zwierze.h"

class Antylopa : public Zwierze{
public:
    Antylopa(Point point, Swiat* swiat) : Zwierze(2, 1, point, swiat) {}

    void ruch() override;
    //void rozmnazanie() override;

    char symbolOrg() override;
};


#endif //PO1_ANTYLOPA_H
