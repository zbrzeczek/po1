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

Czlowiek *Swiat::getCzlowiek() {
    return czlowiek;
}
int Swiat::getNumOrg(){
    return liczbaOrg;
}

vector<Organizm *> Swiat::getOrganizmy() {
    return organizmy;
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
    if (organizmy.empty()) organizmy.push_back(nowy);
    else {
        bool inserted = false;
        for (int i = 0; i < organizmy.size(); i++) {
            if (organizmy[i]->getIni() < nowy->getIni()) {
                organizmy.insert(organizmy.begin() + i, nowy);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            organizmy.push_back(nowy);
        }
    }
}

void Swiat::usunOrg(Organizm *del) {
    if (del == czlowiek) {
        czyGameOver = TRUE;
        return;
    }
    this->organizmy.erase(std::remove(organizmy.begin(), organizmy.end(), del), organizmy.end());
}

void Swiat::usunZabite(){
    for (Organizm* i : this->organizmy){
        if (i->getCzyZabity()) {
            if (i == czlowiek) {
                czyGameOver = TRUE;
                break;
            }
            usunOrg(i);
        }
    }
}

void Swiat::kolizje() {
    vector<Organizm*> tempOrganisms = this->organizmy;

    for (int i = 0; i < tempOrganisms.size(); i++){
        for (int j = i; j < tempOrganisms.size(); j++){
            if (i == j){
                continue;
            }
            if (tempOrganisms[i]->taSamaPozycja(tempOrganisms[j])){
                tempOrganisms[i]->kolizja(tempOrganisms[j]);
            }
        }
    }
}

void Swiat::znajdzWolnePole(int *y, int *x) {
    int zmiennaY = *y;
    int zmiennaX = *x;
    if (zmiennaY + 1 < this->getHeight() && this->getPolePlanszy(zmiennaY+1, zmiennaX) == nullptr) *y += 1;
    else if (zmiennaY - 1 >= 0 && this->getPolePlanszy(zmiennaY-1, zmiennaX) == nullptr) *y -= 1;
    else if (zmiennaX + 1 < this->getWidth() && this->getPolePlanszy(zmiennaY, zmiennaX+1) == nullptr) *x += 1;
    else if (zmiennaX -1 >= 0 && this->getPolePlanszy(zmiennaY, zmiennaX-1) == nullptr) *x -= 1;
}

void Swiat::wykonajTure() {
    //// tutaj musi spawdzqac ta iunicjatywe kto sie pierwszy ruszy ale to pozniej
    for (int i = 0; i < organizmy.size(); i++){
        if (!organizmy[i]->getCzyZabity()) organizmy[i]->akcja();
    }

    for (int x = 0; x < liczbaOrg; x++){
        organizmy[x]->starszyWiek();
    }

    kolizje();
    if (czlowiek->getCzyZabity()) {
        czyGameOver = TRUE;
        return;
    }
    usunZabite();
    liczbaOrg = organizmy.size();
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

void Swiat::wyczysc() {
    liczbaOrg = 0;
    if(!organizmy.empty()) organizmy.clear();
}

Swiat::~Swiat() {
}
