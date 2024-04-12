//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#ifndef PO1_SWIAT_H
#define PO1_SWIAT_H

#include <vector>
#include "Organizm.h"

using  namespace std;

class Organizm;

class Swiat {
private:
    int x, y;
    vector <Organizm*> organizmy;
public:

    Swiat(int x, int y) : x(x), y(y){}

    int getX();
    int getY();

    void addOrganizm(Organizm *nowy);
    void wykonajTure();
    void rysujSwiat();

};


#endif //PO1_SWIAT_H
