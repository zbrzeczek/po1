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
    if (other->getCzyZwierze() && this->getCzyZwierze()){
        if (other->getSila() < this->getSila() || (other->getSila() == this->getSila() && other->getWiek() < this->getWiek())){
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
int Organizm::getSila() {
    return sila;
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