//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_ORGANIZM_H
#define PO1_ORGANIZM_H

#include "Swiat.h"

class Organizm {
private:
    int sila;
    int inicjatywa;
    int x;
    int y;
    Swiat *swiat;
public:
    virtual void akcja();
    virtual void kolicja();
    virtual void rysowanie();

    virtual ~Organizm();
};


#endif //PO1_ORGANIZM_H
