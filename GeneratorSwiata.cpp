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
    int zmiennaSzukania = 0;

    int* wszystkiePola = new int[height * width];
    this->GenerowanieMapowaniaPktOrg(wszystkiePola, iloscOrgLacznie, height, width);


    point.x = width/2;
    point.y = height/2;

    *(wszystkiePola+(height/2 * width) + width/2) = 2;
    Czlowiek* czlowiek = new Czlowiek(point, swiat);
    swiat->setCzlowiek(czlowiek);
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

        odczytajMiejsceOrg(wszystkiePola, &point, &zmiennaSzukania, width, height);
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
    while (*zmiennaSzukania < width * height && *(wszystkiePola + *zmiennaSzukania) != 1) {
        (*zmiennaSzukania)++;
    }
    if (*zmiennaSzukania >= width * height) {
        // Handle error: no available position found
        return;
    }
    pozycja = *zmiennaSzukania;
    point->x = pozycja % width;
    point->y = pozycja / width;
    (*zmiennaSzukania)++;
}

void GeneratorSwiata::generujOrganizmZZapisu(string name, int x, int y) {
    Organizm* nowy = nullptr;
    Point point;
    point.x = x;
    point.y = y;

    if (name == "Antylopa"){
        nowy = new Antylopa(point, this->swiat);
    }
    else if (name== "Lis"){
        nowy = new Antylopa(point, this->swiat);
    }
    else if (name == "Owca"){
        nowy = new Owca(point, this->swiat);
    }
    else if (name == "Zolw"){
        nowy = new Zolw(point, this->swiat);
    }
    else if (name == "Wilk"){
        nowy = new Wilk(point, this->swiat);
    }
    else if (name == "Mlecz"){
        nowy = new Mlecz(point, this->swiat);
    }
    else if (name == "Trawa"){
        nowy = new Trawa(point, this->swiat);
    }
    else if (name == "Guarana"){
        nowy = new Guarana(point, this->swiat);
    }
    else if (name == "Wilcze jagody"){
        nowy = new WilczeJagody(point, this->swiat);
    }
    else if (name == "Barszcz sosnowskiego"){
        nowy = new BarszczSosn(point, this->swiat);
    }

    swiat->addOrganizm(nowy);
}

void GeneratorSwiata::zapisz(Swiat *swiat) {
    ofstream saveFile("save.txt");

    saveFile << swiat->getNumOrg() << std::endl;
    saveFile << swiat->getWidth() << std::endl;
    saveFile << swiat->getHeight() << std::endl;
    saveFile << swiat->getCzlowiek()->getX() << std::endl;
    saveFile << swiat->getCzlowiek()->getY() << std::endl;
    saveFile << swiat->getCzlowiek()->getCoolDown() << std::endl;
    for (Organizm* organizm : swiat->getOrganizmy()){
        saveFile << organizm->getNazwe() << std::endl;
        saveFile << organizm->getX() << std::endl;
        saveFile << organizm->getY() << std::endl;
    }
    //cout << "doszlo tu";
    saveFile.close();
}

void GeneratorSwiata::wczytaj(Swiat *swiat) {
    string name;
    int posX, posY;
    swiat->wyczysc();

    ifstream loadFile("save.txt");
    string line;

    getline(loadFile, line);
    int numOrg = atoi(line.c_str());

    Point czlowiekPoint;
    getline(loadFile, line);
    czlowiekPoint.x = atoi(line.c_str());

    getline(loadFile, line);
    czlowiekPoint.y = atoi(line.c_str());

    getline(loadFile, line);
    int coolDown = atoi(line.c_str());

    for (int i = 0; i < numOrg; i++) {
        for (int j = 0; j < 3; j++) {
            getline(loadFile, line);
            switch (j) {
                case 0:
                    name = line;
                    replace(name.begin(), name.end(), '\n', '\0');
                    break;
                case 1:
                    posX = atoi(line.c_str());
                    break;
                case 2:
                    posY = atoi(line.c_str());
                    break;
            }
        }
        if (name == "Czlowiek") {
            Point var;
            var.x = posX;
            var.y = posY;
            Czlowiek *nowyCzlowiek = new Czlowiek(var, swiat);
            swiat->addOrganizm(nowyCzlowiek);
            continue;
        }
        generujOrganizmZZapisu(name, posX, posY);
    }
    loadFile.close();
}

GeneratorSwiata::~GeneratorSwiata() {
    //delete swiat;
}