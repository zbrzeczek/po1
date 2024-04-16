#include <cstdlib>

#include "Swiat.h"
#include "Stale.h"

int main() {
    srand(time(NULL));
    char input;

    int game = TRUE;
    int inputBool  =TRUE;

    cout << "Nacisnij klawisz aby zaczac gre" << endl;
    cin >> input;

    Swiat nowySwiat(20, 20);


    while(game){
        nowySwiat.rysujSwiat();
        nowySwiat.wykonajTure();
    }

    return 0;
}
