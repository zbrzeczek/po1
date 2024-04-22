//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"
#include "Organizm.h"

void Organizm::akcja() {}

void Organizm::rysowanie() {
    swiat->getPlansza()->addOrgDoPlanszy(getY(), getX(), this);
}

char Organizm::symbolOrg() {
    return ' ';
}

void Organizm::kolizja(Organizm *other) {
    string kom;
    if (other != this) {
        if (other->getCzyZwierze() && this->getCzyZwierze()) {
            Zolw *zmiennaZolw = dynamic_cast<Zolw*>(other);
            if (zmiennaZolw){

            }
            else {
                if (other->getSila() < this->getSila() ||
                    (other->getSila() == this->getSila() && other->getWiek() < this->getWiek())) {
                    kom = this->getNazwe() + this->getPoint() + " zabija " + other->getNazwe() + other->getPoint();
                    swiat->delOrganizm(other);
                } else {
                    kom = other->getNazwe() + other->getPoint() + " zabija " + this->getNazwe() + this->getPoint();
                    swiat->delOrganizm(this);
                }
            }
        } else {
            Roslina *zmienna = dynamic_cast<Roslina *>(other);
            kom = this->getNazwe() + this->getPoint() + " zjada " + other->getNazwe() + other->getPoint();
            if (zmienna->getSila() > 0) {
                kom = kom + " oraz ginie";
                swiat->delOrganizm(this);
            } else {
                Guarana *zmiennaGua = dynamic_cast<Guarana *>(zmienna);
                if (zmiennaGua) {
                    this->setSila(3);
                }
            }
            swiat->delOrganizm(other);
        }
        this->getSwiat()->addKom(kom);
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
string Organizm::getPoint() {
    return " ( " + to_string(this->getY()) + " , " + to_string(this->getX()) +" )";
}
int Organizm::getCzyZwierze() {
    return czyZwierze;
}

int Organizm::walidacjaRuchu(int y, int x) {
    if (x < swiat->getWidth() && x >= 0 &&  y < swiat->getHeight() && y >= 0){
        if (swiat->getPolePlanszy(y , x) == nullptr) return POLE_PUSTE;
        else return KOLIZJA;
    }
    else return FALSE;
}

void Organizm::starszyWiek() {
    wiek++;
}