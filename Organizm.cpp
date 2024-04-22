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
    string kom;
    if (other->getCzyZwierze() && this->getCzyZwierze()){
        if (other->getSila() < this->getSila() || (other->getSila() == this->getSila() && other->getWiek() < this->getWiek())){
            kom = this->getNazwe() + " zabija " + other->getNazwe();
            swiat->delOrganizm(other);
        }
        else {
            kom = other->getNazwe() + " zabija " + this->getNazwe();
            swiat->delOrganizm(this);
        }
        this->getSwiat()->addKom(kom);
    }
    else{
        Roslina *zmienna = dynamic_cast<Roslina*>(other);
        kom = this->getNazwe() + " zjada " + other->getNazwe();
        if (zmienna->getSila() > 0) {
            kom += " oraz ginie";
            swiat->delOrganizm(this);
        }
        else {
            Guarana *zmiennaGua = dynamic_cast<Guarana*>(zmienna);
            if (zmiennaGua){
                this->setSila(3);
            }
        }
        swiat->delOrganizm(zmienna);
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

void Organizm::setSila(int ilosc) {
    sila += ilosc;
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