#include <cstdlib>
#include <ctime>
//#include <ncurses.h>

#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Swiat.h"
#include "Trawa.h"

#define TRUE 1
#define FALSE 0

//WINDOW *create_newwin(int height, int width, int starty, int startx);
//void destroy_win(WINDOW *local_win);

int main() {
    srand( time( NULL ) );
    //WINDOW *plansza, *info;
    //info = create_newwin(24, 40, 4, 40);
    int game = TRUE;

    //initscr();

    //plansza = create_newwin(22, 44, 2, 4);


    //wprintw(plansza, "dziala");
    //wrefresh(plansza);
    //char inpput = getch();

    Swiat nowySwiat(20, 20);

    Czlowiek* czlowiek = new Czlowiek(10, 10, &nowySwiat);
    Wilk* wilk = new Wilk(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Owca* owca = new Owca(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Zolw* zolw = new Zolw(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Antylopa* antylopa = new Antylopa(std::rand() % 20, std::rand() % 20, &nowySwiat);
    Trawa *trawa = new Trawa(std::rand() % 20, std::rand() % 20, &nowySwiat);


    nowySwiat.addOrganizm(czlowiek);
    nowySwiat.addOrganizm(wilk);
    nowySwiat.addOrganizm(owca);
    nowySwiat.addOrganizm(zolw);
    nowySwiat.addOrganizm(antylopa);
    nowySwiat.addOrganizm(trawa);

    while(game){
        nowySwiat.rysujSwiat();
        nowySwiat.wykonajTure();
    }

    return 0;
}

/*WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, '|' , '-');

    wrefresh(local_win);		Show that box

    return local_win;
}*/
