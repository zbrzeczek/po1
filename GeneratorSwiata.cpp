//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#include "Swiat.h"
#include "GeneratorSwiata.h"
#include "WszystkieOrg.h"
#include "Stale.h"

GeneratorSwiata::GeneratorSwiata(Swiat* swiat)
{
    this->swiat = swiat;
}

void GeneratorSwiata::GenerujSwiat()
{
    Point point;

    //licznik jest na 1 bo liczac juz czlowieka
    int height, width, licznikWygenOrg = 1, iloscOrgLacznie, iloscTypu , x, y;
    int zmiennaSzukania = 0;

    height = swiat->getHeight();
    width = swiat->getWidth();
    iloscOrgLacznie = height * POLOWA * width * POLOWA * DEFAULT_ZAL;
    iloscTypu = iloscOrgLacznie/10;


    int* wszystkiePola = new int[height * width];

    this->GenerowanieMapowaniaPktOrg(wszystkiePola, iloscOrgLacznie, height, width);

    point.x = width/2;
    point.y = height/2;

    *(wszystkiePola+(height/2 * width) + width/2) = 2;

    Organizm* czlowiek = new Czlowiek(point, swiat);
    swiat->addOrganizm(czlowiek);

    for (int i = 0; i < iloscTypu; i++){
        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* wilk = new Wilk(point, swiat);
        swiat->addOrganizm(wilk);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* owca = new Owca(point, swiat);
        swiat->addOrganizm(owca);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* lis = new Lis(point, swiat);
        swiat->addOrganizm(lis);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* zolw = new Zolw(point, swiat);
        swiat->addOrganizm(zolw);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* antylopa = new Antylopa(point, swiat);
        swiat->addOrganizm(antylopa);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* trawa = new Trawa(point, swiat);
        swiat->addOrganizm(trawa);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);;
        Organizm* mlecz = new Mlecz(point, swiat);
        swiat->addOrganizm(mlecz);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* guarana = new Guarana(point, swiat);
        swiat->addOrganizm(guarana);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* jagoda = new WilczeJagody(point, swiat);
        swiat->addOrganizm(jagoda);

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
        Organizm* barszcz = new BarszczSosn(point, swiat);
        swiat->addOrganizm(barszcz);
    }
}

void GeneratorSwiata::GenerowanieMapowaniaPktOrg(int * wszystkiePola, int iloscOrg, int height, int width) {
    int los;

    for (int i = 0; i < height * width; i++){
        *(wszystkiePola+i) = 0;
    }

    for (int i = 0; i < iloscOrg; i++){
        do {
            los = rand() % (width * height);
        } while (*(wszystkiePola+los) != 0);
        *(wszystkiePola+los) = 1;
    }
}

void GeneratorSwiata::odczytajMiejsceOrg(int* wszystkiePola, Point *point, int *zmiennaSzukania, int width, int height){
    int pozycja;
    while (*(wszystkiePola+ *zmiennaSzukania) != 1) (*zmiennaSzukania)++;
    pozycja = *zmiennaSzukania;
    point->x = pozycja % width;
    point->y = pozycja / height;
    (*zmiennaSzukania)++;
}

GeneratorSwiata::~GeneratorSwiata() {
    delete swiat;
}