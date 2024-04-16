//
// Created by Zuzanna Brzęczek on 16/04/2024.
//

#include "Plansza.h"


Plansza::Plansza(int width, int height) {
    for (int i = 0; i < height; i ++){
        for (int j =0; j < width; j++){
            planszaOrg[i][j] = nullptr;
        }
    }
}

Plansza::~Plansza(){

}
