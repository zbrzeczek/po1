//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Organizm.h"

void Organizm::akcja() {}

//void Organizm::kolizja(Organizm *other) {}

void Organizm::rysowanie() {}

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