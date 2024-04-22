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

void Swiat::sortKolejkeAkcji() {
    sort(organizmy.begin(), organizmy.end(), [](Organizm *a, Organizm *b){
        if (a->getCzyZwierze() && b->getCzyZwierze()) {
            Zwierze *aVar = dynamic_cast<Zwierze*>(a);
            Zwierze *bVar = dynamic_cast<Zwierze*>(b);
            if (bVar->getIni() != aVar->getIni()) {
                return aVar->getIni() > bVar->getIni(); // Sort by initiative in descending order
            } else {
                return aVar->getWiek() > bVar->getWiek(); // If initiative is the same, sort by age in descending order
            }
        }
        else if (b == nullptr || !b->getCzyZwierze()) return false;
        else return true;
    });

    for (Organizm *org : organizmy) {
        if(org->getCzyZwierze() == TRUE) kolejkaAkcji.push_back(org);
    }

}

void Swiat::addOrganizm(Organizm *nowy) {
    organizmy.push_back(nowy);
    liczbaOrg++;
}

void Swiat::delOrganizm(Organizm *del) {
    Czlowiek *zmienna = dynamic_cast<Czlowiek*>(del);
    if (zmienna) czyGameOver = TRUE;
    organizmy.erase(remove_if(organizmy.begin(), organizmy.end(),
                                   [del](Organizm* org) { return org == del; }),
                    organizmy.end());
    kolejkaAkcji.erase(remove_if(kolejkaAkcji.begin(), kolejkaAkcji.end(),
                              [del](Organizm* org) { return org == del; }),
                    kolejkaAkcji.end());
    delete del;
    liczbaOrg--;
}

void Swiat::wykonajTure() {
    sortKolejkeAkcji();
    int i =0;
    //// tutaj musi spawdzqac ta iunicjatywe kto sie pierwszy ruszy ale to pozniej
    while (i < kolejkaAkcji.size()){
        kolejkaAkcji[i]->akcja();
        i++;
    }
    for (int j = 0; j < kolejkaAkcji.size(); j++){
        kolejkaAkcji.pop_back();
    }

    for (int x = 0; x < liczbaOrg; x++){
        organizmy[x]->starszyWiek();
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
