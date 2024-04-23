//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#ifndef PO1_GENERATORSWIATA_H
#define PO1_GENERATORSWIATA_H

#include <iostream>
#include <cstdlib>

#include "Point.h"

using namespace std;

class Swiat;

class GeneratorSwiata {
private:
    Swiat* swiat;
    //void GenerowaniePunktowDlaOrganizmow(int* pola, int* ileZwZGat);
    //void OdczytajWspolrzedne(int* pola, int* x, int* y, int* ktory);
    //void WczytajOrganizm(string nazwa, int sila, int ini, int x, int y, int wiek);
public:
    GeneratorSwiata(Swiat* swiat);

    void GenerujSwiat();

    //bool Wczytaj_swiat();
    //void Zapisz_swiat();

    ~GeneratorSwiata();
};


#endif //PO1_GENERATORSWIATA_H
