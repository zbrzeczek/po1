#include <cstdlib>

#include "GeneratorSwiata.h"
#include "Swiat.h"
#include "Stale.h"

int main() {
    srand(time(NULL));
    int y, x;

    int game = TRUE;
    int inputBool  =TRUE;

    cout << "wysokosc planszy" << endl;
    cin >> y;
    cout << "wysokosc planszy" << endl;
    cin >> x;

    Plansza nowaPlansza(x, y);
    Swiat nowySwiat(x, y, &nowaPlansza);
    GeneratorSwiata generator(&nowySwiat);
    generator.GenerujSwiat();
    printf("Zuzanna Brzeczek 198256");
    nowySwiat.rysujSwiat();

    while(!nowySwiat.getGameOver()){
        nowySwiat.wykonajTure();
        nowySwiat.rysujSwiat();
    }

    return 0;
}
