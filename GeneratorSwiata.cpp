//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#include "Swiat.h"
#include "GeneratorSwiata.h"
#include "WszystkieOrg.h"
#include "Stale.h"

Generator_swiata::Generator_swiata(Swiat* swiat)
{
    swiat = swiat;
}

void Generator_swiata::Generuj_swiat()
{
    Point point;

    //licznik jest na 1 bo liczac juz czlowieka
    int height, width, licznikWygenOrg = 1, iloscOrgLacznie, iloscTypu , x, y;
    int zmiennaSzukania = 0;

    height = swiat->getHeight();
    width = swiat->getWidth();
    iloscOrgLacznie = height * width * DEFAULT_ZAL;
    iloscTypu = iloscOrgLacznie/10;


    int* wszystkiePola = new int[height * width];

    //+1 bo czlowiek
    this->GenerowanieMapowaniaPktOrg(wszystkiePola, iloscOrgLacznie, height, width);

    point.x = width/2;
    point.y = height/2;

    Organizm* czlowiek = new Czlowiek(point, swiat);
    swiat->addOrganizm(czlowiek);

    for (int i = 0; i < iloscTypu; i++)
    {
        odczytajMiejsceOrg(wszystkiePola, &point, zmiennaSzukania);
        Organizm* wilk = new Wilk(point, swiat);
        swiat->addOrganizm(wilk);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* owca = new Owca(x, y, _swiat);
        _swiat->DodajOrganizm(owca);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* lis = new Lis(x, y, _swiat);
        _swiat->DodajOrganizm(lis);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* zolw = new Zolw(x, y, _swiat);
        _swiat->DodajOrganizm(zolw);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* antylopa = new Antylopa(x, y, _swiat);
        _swiat->DodajOrganizm(antylopa);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* trawa = new Trawa(x, y, _swiat);
        _swiat->DodajOrganizm(trawa);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* mlecz = new Mlecz(x, y, _swiat);
        _swiat->DodajOrganizm(mlecz);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* guarana = new Guarana(x, y, _swiat);
        _swiat->DodajOrganizm(guarana);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* jagoda = new Wilcze_jagody(x, y, _swiat);
        _swiat->DodajOrganizm(jagoda);

        OdczytajWspolrzedne(polaZajete, &x, &y, &j);
        Organizm* barszcz = new Barszcz_sosnowskiego(x, y, _swiat);
        _swiat->DodajOrganizm(barszcz);
    }
}

void Generator_swiata::GenerowanieMapowaniaPktOrg(int * wszystkiePola, int iloscOrg, int height, int width) {
    int los;

    for (int i = 0; i < height * width; i++){
        *(wszystkiePola+i) = 0;
    }
    height/2 * width

    for (int i = 0; i < iloscOrg; i++){
        do {
            los = rand() % (width * height);
        } while (*(wszystkiePola+los) == 1);
        *(wszystkiePola+los) = 1;
    }
}

void Generator_swiata::odczytajMiejsceOrg(int* wszystkiePola, Point *point, int *zmeinnaSzukania){
    *x = pola[*ktory] % n;
    *y = (pola[*ktory] - *x) / n;
    (*ktory)++;
}

Generator_swiata::~Generator_swiata()
{
    delete swiat;
