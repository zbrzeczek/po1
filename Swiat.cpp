//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include <conio.h>
#include <iostream>
#include "Swiat.h"


int Swiat::getX() {
    return x;
}
int Swiat::getY() {
    return y;
}

void Swiat::addOrganizm(Organizm *nowy) {
    organizmy.push_back(nowy);
}
void Swiat::wykonajTure() {
    //// tutaj musi spawdzqac ta iunicjatywe kto sie pierwszy ruszy ale to pozniej
    for (int i = 0; i < organizmy.size(); i++){
        organizmy[i]->akcja();
    }
}
void Swiat::rysujSwiat() {
    clrscr();
    for (int yPole = 0; yPole < getY(); yPole++){
        for(int xPole = 0; xPole< getX(); xPole++){
            for (int o = 0; o < organizmy.size(); o++){
                if (xPole == organizmy[o]->getX() && yPole==organizmy[o]->getY()){
                    organizmy[o]->rysowanie();
                }
                else std::cout << ' ';
            }
        }
        std::cout << endl;
    }
}
