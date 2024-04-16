//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"

Swiat::Swiat(int width, int height) {
    width = width;
    height = height;

    /*
    _liczbaOrgBezNowonarodzonych = 0;
    _liczbaOrg = 0;
    _tura = 0;
    _czyCzlowiekZyje = false;
    _czlowiek = nullptr;
    _komentarze = new string[KOMENTARZE_NA_ORG *  * m];
    _liczbaKomentarzy = 0;

    _organizmy = new Organizm * [_n * _m];*/

    Plansza planszaGry(width, height);

}

int Swiat::getWidth() {
    return width;
}
int Swiat::getHeight() {
    return height;
}

void Swiat::addOrganizm(Organizm *nowy) {
    organizmy.push_back(nowy);
}

void Swiat::nowaGra(int zaludnienie) {
    //-1 bo czlowiek jest juz jednym deafult organizmem
    int ilosc = getX() * getY() * zaludnienie;
    int iloscDefault = ilosc/10;

    Point middlePoint;
    middlePoint.x = getX()/2;
    middlePoint.y = getY()/2;

    Czlowiek* czlowiek = new Czlowiek(middlePoint, this);
    cout << "Tu doszlo" << endl;
    vector <Organizm *> czlowiek
    organizmy[0].push_back(czlowiek);

    cout << "dodano czlowieka" << endl;
    for (int i = 0; i< iloscDefault; i++){
        Point varPoint;
        varPoint.x = rand() % 20;
        varPoint.y = rand() % 20;
        Wilk* wilk = new Wilk(varPoint, this);
        addOrganizm(wilk, 0);
    }
    cout << "dodano wilki" << endl;
    for (int i = 0; i< iloscDefault; i++){
        Point varPoint;
        varPoint.x = rand() % 20;
        varPoint.y = rand() % 20;
        Owca *owca = new Owca(varPoint, this);
        addOrganizm(owca, 1);
    }
    cout << "dodano owce" << endl;
}

void Swiat::wykonajTure() {
    //// tutaj musi spawdzqac ta iunicjatywe kto sie pierwszy ruszy ale to pozniej
    for (int i = 0; i < organizmy.size(); i++){
        for (int j = 0; j < organizmy[i].size(); j++){
            organizmy[i][j]->akcja();
        }
    }
}
void Swiat::rysujSwiat() {
    for (int yPole = 0; yPole < getY(); yPole++){
        for(int xPole = 0; xPole< getX(); xPole++){
            for (int o = 0; o < organizmy.size(); o++){
                for(int t = 0; t < organizmy[o].size(); t++) {
                    if (xPole == organizmy[o][t]->getX() && yPole == organizmy[o][t]->getY()) {
                        organizmy[o][t]->rysowanie();
                    }
                    else std::cout << ' ';
                }
            }
        }
        std::cout << endl;
    }
}
