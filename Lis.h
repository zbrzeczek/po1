//
// Created by Zuza on 2024-04-18.
//

#ifndef PO1_LIS_H
#define PO1_LIS_H

#include "Zwierze.h"

class Lis : public Zwierze{
public:
    Lis(Point point, Swiat* swiat) : Zwierze(3, 7, point, swiat) {}

    string getNazwe() override;
    //void rozmnazanie() override;
    void ruch() override;
    char symbolOrg() override;

};


#endif //PO1_LIS_H
