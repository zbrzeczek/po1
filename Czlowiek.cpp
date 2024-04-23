//
// Created by Zuza on 2024-04-03.
//

#include "Swiat.h"
#include "GeneratorSwiata.h"
#include "Czlowiek.h"

string Czlowiek::getNazwe() {
    return "Czlowiek";
}

int Czlowiek::getCoolDown() {
    return coolDown;
}
void Czlowiek::ruch() {
    char ch;
    int x, y;
    int wybieranie = TRUE;

    while (wybieranie) {
        x = getX();
        y = getY();
        cout << "Ruch czlowieka" << endl;
        cin >> ch;

        wybieranie = FALSE;
        switch (ch) {
            case 'w':
                if(getY() - 1 >= 0) this->changePos(y-1,x);
                else wybieranie = TRUE;
                break;
            case 's':
                if(getY() + 1 < getSwiat()->getHeight()) this->changePos(y+1,x);
                else wybieranie = TRUE;
                break;
            case 'd':
                if(getX() + 1 < getSwiat()->getWidth()) this->changePos(y,x+1);
                else wybieranie = TRUE;
                break;
            case 'a':
                if(getX() - 1 > 0) this->changePos(y,x-1);
                else wybieranie = TRUE;
                break;
            case 'u':
                if (getCoolDown() < 5) {
                    cout << "Nie mozna uruchomic umiejetnosci" << endl;
                }
                else {
                    moc();
                    cout << "Uruchomiono umiejetnosc" << endl;
                }
                wybieranie = TRUE;
                break;
            default:
                break;
        }
    }
    this->setSila(dodatkowaSila - coolDown);
    if (getCoolDown() < 5) coolDown++;
}

void Czlowiek::moc() {
    coolDown = 0;
}
char Czlowiek::symbolOrg() {
    return 'C';
}
