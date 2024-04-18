#include <cstdlib>

#include "GeneratorSwiata.h"
#include "Swiat.h"
#include "Stale.h"

int main() {
    srand(time(NULL));
    char input;

    int game = TRUE;
    int inputBool  =TRUE;

    cout << "Nacisnij klawisz aby zaczac gre" << endl;
    cin >> input;

    Plansza nowaPlansza(20, 20);
    Swiat nowySwiat(20, 20, &nowaPlansza);
    GeneratorSwiata generator(&nowySwiat);
    generator.GenerujSwiat();
    nowySwiat.rysujSwiat();

    while(!nowySwiat.getGameOver()){
        nowySwiat.wykonajTure();
        nowySwiat.rysujSwiat();
    }

    return 0;
}
