#include <cstdlib>
#include <ctime>
#include <>

#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Swiat.h"
#include "Roslina.h"

#define TRUE 1
#define FALSE 0

int main() {
    srand( time( NULL ) );
    int game = TRUE;
    Swiat nowySwiat(20, 20);

    Czlowiek* czlowiek = new Czlowiek(10, 10, &nowySwiat);
    Wilk* wilk = new Wilk(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Owca* owca = new Owca(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Zolw* zolw = new Zolw(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Antylopa* antylopa = new Antylopa(std::rand() % 20, std::rand() % 20, &nowySwiat);


    nowySwiat.addOrganizm(czlowiek);
    nowySwiat.addOrganizm(wilk);
    nowySwiat.addOrganizm(owca);
    nowySwiat.addOrganizm(zolw);
    nowySwiat.addOrganizm(antylopa);

    while(game){
        nowySwiat.rysujSwiat();
        nowySwiat.wykonajTure();
    }

    return 0;
}
