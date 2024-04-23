//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"
#include "Organizm.h"

void Organizm::akcja() {}

void Organizm::rozmnazanie() {}

void Organizm::rysowanie() {
    swiat->getPlansza()->addOrgDoPlanszy(getY(), getX(), this);
}
char Organizm::symbolOrg() {
    return ' ';
}

void Organizm::ucieczkaPole() {
    this->prevPoint.x = this->point.x;
    this->prevPoint.y = this->point.y;

    if (this->getSwiat()->getPolePlanszy(this->point.y, this->point.x+1) == nullptr && this->point.x + 1 < getSwiat()->getWidth() - 1){
        this->point.x++;
    }
    else if (this->getSwiat()->getPolePlanszy(this->point.y, this->point.x-1) == nullptr && this->point.x - 1 >= 0){
        this->point.x--;
    }
    else if (this->getSwiat()->getPolePlanszy(this->point.y+1, this->point.x) == nullptr && this->point.y + 1 < getSwiat()->getHeight() - 1){
        this->point.y++;
    }
    else if (this->getSwiat()->getPolePlanszy(this->point.y -1, this->point.x) == nullptr && this->point.y - 1 >= 0){
        this->point.y--;
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
int Organizm::getIni() {
    return ini;
}
void Organizm::setSila(int ilosc) {
    sila += ilosc;
}
void Organizm::zabity(Organizm *oprawca) {
    string kom = this->getNazwe() + this->getPoint() + " zabity przez: " + oprawca->getNazwe() + oprawca->getPoint();
    swiat->addKom(kom);
    this->czyZabity = true;
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
bool Organizm::getCzyZwierze() {
    return czyZwierze;
}
bool Organizm::getCzyZabity(){
    return czyZabity;
}

bool Organizm::teSameOrg(Organizm *drugi) {
    return this->getNazwe()==drugi->getNazwe();
}
bool Organizm::taSamaPozycja(Organizm *drugi) {
    return this->getX() == drugi->getX() && this->getY()==drugi->getY();
}

bool Organizm::ucieczka(Organizm *other) {
    return false;
}
bool Organizm::obroniony(Organizm *other) {
    return false;
}
void Organizm::cofnijRuch() {
    point.x = prevPoint.x;
    point.y = prevPoint.y;
}

void Organizm::walka(Organizm* other){
    if (other->ucieczka(this) || this->ucieczka(other)){
        return;
    }

    if (this->obroniony(other)){
        other->cofnijRuch();
        return;
    }
    else if (other->obroniony(this)){
        this->cofnijRuch();
        return;
    }

    if (this->getSila() > other->getSila() || (this->getSila() == other->getSila() && this->getWiek() > other->getWiek())){
        other->zabity(this);
    }
    else{
        this->zabity(other);
    }
}

void Organizm::kolizja(Organizm *other) {
    if (teSameOrg(other)) rozmnazanie();
    else walka(other);
}

void Organizm::changePos(int y, int x) {
    prevPoint.x = point.x;
    prevPoint.y = point.y;
    point.x = x;
    point.y = y;
}

void Organizm::starszyWiek() {
    wiek++;
}