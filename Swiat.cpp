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
    /*
    _liczbaOrgBezNowonarodzonych = 0;
    _tura = 0;
    _czyCzlowiekZyje = false;
    _czlowiek = nullptr;
    _komentarze = new string[KOMENTARZE_NA_ORG *  * m];
    _liczbaKomentarzy = 0;
*/
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
Organizm *Swiat::getPolePlanszy(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height){
        return planszaGry->getOrganizmZPlanszy(x, y);
    }
    return nullptr;
}
void Swiat::addKom(string kom) {
    komentarze.push_back(kom);
    numKomentarzy++;
}

void Swiat::sortKolejkeAkcji() {
    sort(organizmy.begin(), organizmy.end(), [](Organizm *a, Organizm *b){
        if (b->getIni() != a->getIni()) {
            return b->getIni() > a->getIni(); // Sort by inicjatywa in descending order
        } else {
            return b->getWiek() > a->getWiek(); // If inicjatywa is the same, sort by wiek in descending order
        }
    });

    for (Organizm *org : organizmy) {
        kolejkaAkcji.push_back(org);
    }
}

void Swiat::addOrganizm(Organizm *nowy) {
    organizmy.push_back(nowy);
    liczbaOrg++;
}

void Swiat::delOrganizm(Organizm *del) {
    organizmy.erase(remove_if(organizmy.begin(), organizmy.end(),
                                   [del](Organizm* org) { return org == del; }),
                    organizmy.end());
    kolejkaAkcji.erase(remove_if(kolejkaAkcji.begin(), kolejkaAkcji.end(),
                              [del](Organizm* org) { return org == del; }),
                    kolejkaAkcji.end());
    string kom = del->getNazwe() + ": \tsmierc organizmu";
    this->addKom(kom);
    delete del;
    liczbaOrg--;
}

void Swiat::wykonajTure() {
    sortKolejkeAkcji();

    //// tutaj musi spawdzqac ta iunicjatywe kto sie pierwszy ruszy ale to pozniej
    for (int i = kolejkaAkcji.size(); i > 0; i--){
        kolejkaAkcji[i-1]->akcja();
        kolejkaAkcji.pop_back();
    }

    for (int i = 0; i < liczbaOrg; i++){
        organizmy[i]->starszyWiek();
    }
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
                if (getPolePlanszy(x-1, y-1) == nullptr) cout << ' ';
                else {
                    cout << getPolePlanszy(x-1, y-1)->symbolOrg();
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
