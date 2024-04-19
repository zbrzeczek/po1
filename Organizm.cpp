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

int Organizm::kolizja(Organizm *other) {
    if (other->czyZwierze){
        Zwierze *zmienna = dynamic_cast<Zwierze*>(other);
        Zwierze *zmienna2 = dynamic_cast<Zwierze*>(this);
        if (zmienna->getSila() < zmienna2->getSila() || (zmienna->getSila() == zmienna2->getSila() && zmienna->getWiek() < zmienna2->getWiek())){
            swiat->delOrganizm(other);
            return TRUE;
        }
        else return FALSE;
    }
    /*else {
        Roslina *zmienna = dynamic_cast<Zwierze*>(other);
    }*/
    return FALSE;
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

int Organizm::walidacjaRuchu(int x, int y) {
    if (point.x + x < swiat->getWidth() && point.x + x > 0 &&  point.y + y < swiat->getHeight() && point.y + y> 0){
        if (swiat->getPolePlanszy(point.x + x , point.y + y) == nullptr) return POLE_PUSTE;
        else return KOLIZJA;
    }
    else return FALSE;
}

void Organizm::starszyWiek() {
    wiek++;
}