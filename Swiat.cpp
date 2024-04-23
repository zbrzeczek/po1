//
// Created by Zuzanna Brzęczek on 20/03/2024.
//

#include "Swiat.h"

#include <utility>

Swiat::Swiat(int width, int height, Plansza *plansza) {
    this->width = width;
    this->height = height;
    this->planszaGry = plansza;
    czyGameOver = FALSE;
    numKomentarzy = 0;
    liczbaOrg = 0;
    this->czlowiek = nullptr;
}

void Swiat::setCzlowiek(Czlowiek *czlowiek) {
    this->czlowiek = czlowiek;
}

//gettery
int Swiat::getWidth() {
    return width;
}
int Swiat::getHeight() {
    return height;
}
Plansza *Swiat::getPlansza() {
    return planszaGry;
}
int Swiat::getGameOver() {
    return czyGameOver;
}
Organizm *Swiat::getPolePlanszy(int y, int x) {
    if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight()){
        return planszaGry->getOrganizmZPlanszy(y, x);
    }
    return nullptr;
}
void Swiat::addKom(string kom) {
    komentarze.push_back(kom);
    numKomentarzy++;
}

void Swiat::addOrganizm(Organizm *nowy) {
    for (int i = 0; i < this->organizmy.size(); i++){
        if (this->organizmy[i]->getIni() < nowy->getIni()){
            organizmy.insert(organizmy.begin() + i, nowy);
        }
    }
    if (organizmy.empty()) organizmy.push_back(nowy);
    //organizmy.push_back(nowy);
}

void Swiat::usunOrg(Organizm *del) {
    this->organizmy.erase(std::remove(organizmy.begin(), organizmy.end(), del), organizmy.end());
}

void Swiat::usunZabite(){
    for (Organizm* i : this->organizmy){
        if (i->getCzyZabity()) {
            usunOrg(i);
        }
    }
}

void Swiat::wykonajTure() {
    //// tutaj musi spawdzqac ta iunicjatywe kto sie pierwszy ruszy ale to pozniej
    for (int i = 0; i < organizmy.size(); i++){
        if (!kolejkaAkcji[i]->getCzyZabity()) kolejkaAkcji[i]->akcja();
    }

    for (int x = 0; x < liczbaOrg; x++){
        organizmy[x]->starszyWiek();
    }
    usunZabite();
}

void Swiat::rysujSwiat() {
    planszaGry->wyczyscPlansze();

    //mapowanie tych organizmow na planszy po turze
    for (int i = 0; i < organizmy.size(); i++){
        organizmy[i]->rysowanie();
    }

    for (int y = 0; y < (height + 2); y++){
        for (int x = 0; x < (width + 2); x++){
            if ((x == 0) || (y == 0) || (x == width + 1) || (y == height + 1)) cout << '#';
            else {
                if (getPolePlanszy(y-1, x-1) == nullptr) cout << ' ';
                else {
                    cout << getPolePlanszy(y-1, x-1)->symbolOrg();
                }
            }
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < numKomentarzy; i++){
        cout << komentarze[i] << endl;
    }
    while (!komentarze.empty()){
        komentarze.pop_back();
    }
    numKomentarzy = 0;
}

Swiat::~Swiat() {
    delete planszaGry;
}
