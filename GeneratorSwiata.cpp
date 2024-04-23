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

void GeneratorSwiata::GenerujSwiat(){
    Point point;
    //licznik jest na 1 bo liczac juz czlowieka
    int height, width, iloscOrgLacznie, iloscTypu;

    height = swiat->getHeight();
    width = swiat->getWidth();
    iloscOrgLacznie = height * width * DEFAULT_ZAL;
    iloscTypu = iloscOrgLacznie/10;

    point.x = width/2;
    point.y = height/2;


    Czlowiek* czlowiek = new Czlowiek(point, swiat);
    swiat->setCzlowiek(czlowiek);

    for (int i = 0; i < iloscTypu; i++){
        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* wilk = new Wilk(point, swiat);
        swiat->addOrganizm(wilk);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* owca = new Owca(point, swiat);
        swiat->addOrganizm(owca);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* lis = new Lis(point, swiat);
        swiat->addOrganizm(lis);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* zolw = new Zolw(point, swiat);
        swiat->addOrganizm(zolw);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* antylopa = new Antylopa(point, swiat);
        swiat->addOrganizm(antylopa);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* trawa = new Trawa(point, swiat);
        swiat->addOrganizm(trawa);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* mlecz = new Mlecz(point, swiat);
        swiat->addOrganizm(mlecz);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* guarana = new Guarana(point, swiat);
        swiat->addOrganizm(guarana);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* jagoda = new WilczeJagody(point, swiat);
        swiat->addOrganizm(jagoda);

        point.x = rand() % width;
        point.y = rand() % height;
        Organizm* barszcz = new BarszczSosn(point, swiat);
        swiat->addOrganizm(barszcz);
    }
    cout << "nmie doszlo";
}


GeneratorSwiata::~GeneratorSwiata() {
    delete swiat;
}