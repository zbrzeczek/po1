//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"
#include "Organizm.h"

void Organizm::akcja() {}

void Organizm::kolizja(Organizm *other) {}

void Organizm::rysowanie() {
    swiat->getPlansza()->addOrgDoPlanszy(point.x, point.y, this);
}

char Organizm::symbolOrg() {

}
int Organizm::getX() {
    return point.x;
}
int Organizm::getY() {
    return point.y;
}
/*int Organizm::getSila() {
    return sila;
}*/
int Organizm::getIni() {
    return inicjatywa;
}

int Organizm::getWiek() {
    return wiek;
}

int Organizm::walidacjaRuchu(int x, int y) {
    if (point.x + x < swiat->getWidth() && point.x + x > 0 &&  point.y + y < swiat->getHeight() && point.y + y> 0) return TRUE;
    else return FALSE;
}

void Organizm::starszyWiek() {
    wiek++;
}