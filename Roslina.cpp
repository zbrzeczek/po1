//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"
#include "Roslina.h"

void Roslina::akcja() {
    int prawdopodobienstwo = rand() % 10;
    if (prawdopodobienstwo == 0){
        rozprz();
    }
}
string Roslina::getNazwe() {
    return " ";
}

void Roslina::rozprz() {

}

char Roslina::symbolOrg() {
    return ' ';
}