//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"
#include "Organizm.h"

void Organizm::akcja() {}

void Organizm::rysowanie() {
    swiat->getPlansza()->addOrgDoPlanszy(point.x, point.y, this);
}

char Organizm::symbolOrg() {
    return ' ';
}

void Organizm::kolizja(Organizm *other) {
    if (other->czyZwierze){
        Zwierze *zmienna = dynamic_cast<Zwierze*>(other);
        Zwierze *zmienna2 = dynamic_cast<Zwierze*>(this);
        if (zmienna->getSila() < zmienna2->getSila() || (zmienna->getSila() == zmienna2->getSila() && zmienna->getWiek() < zmienna2->getWiek())){
            cout << this->getNazwe() << " zabija " << other->getNazwe();
            swiat->delOrganizm(other);
        }
        else {
            cout << other->getNazwe() << " zabija " << this->getNazwe();
            swiat->delOrganizm(this);
        }
    }
}

int Organizm::getX() {
    return point.x;
}
int Organizm::getY() {
    return point.y;
}
int Organizm::getIni() {
    return inicjatywa;
}

int Organizm::getWiek() {
    return wiek;
}
Swiat *Organizm::getSwiat() {
    return swiat;
}
string Organizm::getNazwe() {
    return " ";
}
int Organizm::getCzyZwierze() {
    return czyZwierze;
}

int Organizm::walidacjaRuchu(int x, int y) {
    if (x < swiat->getWidth() && x >= 0 &&  y < swiat->getHeight() && y >= 0){
        if (swiat->getPolePlanszy(x , y) == nullptr) return POLE_PUSTE;
        else return KOLIZJA;
    }
    else return FALSE;
}

void Organizm::starszyWiek() {
    wiek++;
}