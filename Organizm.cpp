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

bool Organizm::teSameOrg(Organizm *drugi) {
    return this->getNazwe()==drugi->getNazwe();
}
bool Organizm::taSamaPozycja(Organizm *drugi) {
    return this->getX()==drugi->getX() && this->getY()==drugi->getY();
}

void Organizm::kolizja(Organizm *other) {
    if (teSameOrg(other)) rozmnazanie();
    /*string kom;
    if (this->getNazwe() == other->getNazwe()){
        //this->rozmnazanie();
    }
    else{
        int los = rand() %2;
        if (typeid(other) == typeid(Zolw) && this->getSila() < 5){
            kom = other->getNazwe() + other->getPoint() + " odbil atak " + this->getNazwe() + this->getPoint();
        }
        else if (typeid(other) == typeid(Antylopa) && los == 0){

        }
        else if (typeid(other) == typeid(Guarana)) this->setSila(3);
        else {
            if (other->getSila() < this->getSila() || (other->getSila() == this->getSila() && other->getWiek() < this->getWiek())) {
                kom = this->getNazwe() + this->getPoint() + " zabija " + other->getNazwe() + other->getPoint();
                getSwiat()->delOrganizm(other);
            } else {
                kom = other->getNazwe() + other->getPoint() + " zabija " + this->getNazwe() + this->getPoint();
                getSwiat()->delOrganizm(this);
            }
        }
        /*else {
            Roslina *zmienna = dynamic_cast<Roslina *>(other);
            kom = this->getNazwe() + this->getPoint() + " zjada " + other->getNazwe() + other->getPoint();
            if (zmienna->getSila() > 0) {
                kom = kom + " oraz ginie";
                swiat->delOrganizm(this);
            }
            else {
                if (typeid(other) == typeid(Guarana)) this->setSila(3);
            }
            swiat->delOrganizm(other);
        }
        this->getSwiat()->addKom(kom);
    }*/
}
void Organizm::changePos(int y, int x) {
    point.x = x;
    point.y = y;
}

int Organizm::ruchWalidacja(int y, int x) {
    if (x < swiat->getWidth() && x >= 0 &&  y < swiat->getHeight() && y >= 0){
        if (swiat->getPolePlanszy(y , x) == nullptr) this->changePos(y, x);
        else kolizja(this->getSwiat()->getPolePlanszy(y , x));
        return FALSE;
    }
    else return TRUE;
}

void Organizm::starszyWiek() {
    wiek++;
}