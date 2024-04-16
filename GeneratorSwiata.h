//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#ifndef PO1_GENERATORSWIATA_H
#define PO1_GENERATORSWIATA_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Swiat;

class Generator_swiata {
private:
    Swiat* swiat;
    //void GenerowaniePunktowDlaOrganizmow(int* pola, int* ileZwZGat);
    //void OdczytajWspolrzedne(int* pola, int* x, int* y, int* ktory);
    //void WczytajOrganizm(string nazwa, int sila, int ini, int x, int y, int wiek);
public:
    Generator_swiata(Swiat* swiat);

    void Generuj_swiat();
    void GenerowanieMapowaniaPktOrg(int *wszystkiePola, int iloscOrg, int height, int width);
    void odczytajMiejsceOrg(int* wszystkiePola, Point *point, int * zmiennaSzukania);
    //bool Wczytaj_swiat();
    //void Zapisz_swiat();

    ~Generator_swiata();
};


#endif //PO1_GENERATORSWIATA_H
