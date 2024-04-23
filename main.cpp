#include <cstdlib>
#include <fstream>


#include "GeneratorSwiata.h"
#include "Swiat.h"
#include "Stale.h"

int main() {
    srand(time(NULL));
    int y, x;
    char input;
    int game = TRUE;
    int inputBool  =TRUE;

    cout << "Wysokosc planszy: " << endl;
    cin >> y;
    cout << "Szerokosc planszy: " << endl;
    cin >> x;

    Plansza nowaPlansza(x, y);
    Swiat nowySwiat(x, y, &nowaPlansza);
    GeneratorSwiata generator(&nowySwiat);
    printf("Zuzanna Brzeczek 198256 \n");
    printf("Sposob sterowania \n");
    printf("wsad - poruszanie czlowiekiem podczas tury\n");
    printf("u - umiejetnosc \n\n");
    //sleep(1);
    printf("nowa gra - n\n");
    printf("wczytaj - l \n");
    system("CLS");

    cin >> input;

    if (input == 'n') {
        generator.GenerujSwiat();
    }
    else if (input == 'l'){
        generator.wczytaj(&nowySwiat);
    }
    nowySwiat.rysujSwiat();

    while (!nowySwiat.getGameOver()){
        printf("kontynuuj - k \n");
        printf("zapisz - z \n");
        printf("wyjdz - q \n");

        cin >> input;
        if (input == 'k') {
            nowySwiat.wykonajTure();
            nowySwiat.rysujSwiat();
        }
        else if (input == 'z'){
            generator.zapisz(&nowySwiat);
            break;
        }
        else if (input == 'q') {
            break;
        }

    }

    return 0;
}
