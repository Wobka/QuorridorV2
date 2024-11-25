#include <stdio.h>
#include "Menu.h"
#include "fonc jeu.h"
#include "Affichage Jeu.h"
#include "score.h"
#include "sauvegarde.h"


int main()
{
    struct joueur j1;
    j1.x = 1;
    j1.y = 5;
    j1.bar = 9;
    j1.x_pre = j1.x;
    j1.y_pre = j1.y;
    j1.annuler=0;
    struct joueur j2;
    j2.x = 9;
    j2.y = 5;
    j2.bar = 9;
    j2.x_pre = j2.x;
    j2.y_pre = j2.y;
    j2.annuler=0;
    for (int i = 0; i < 10; i++) {
        j1.tab[i].x1=20;
        j1.tab[i].y1=i*3+5;
        j1.tab[i].x2=20;
        j1.tab[i].y2=i*3+6;

    }
    for (int i = 0; i < 10; i++) {
        j2.tab[i].x1=23;
        j2.tab[i].y1=i*3+5;
        j2.tab[i].x2=23;
        j2.tab[i].y2=i*3+6;

    }
    struct partie partie_actuelle;
    partie_actuelle.joueur1 = j1;
    partie_actuelle.joueur2 = j2;
    int i =50;
    int gagnant=0;
    int choix = menu();
    if(choix==1) {
        do {
            plateau(j1,j2,i);
            cursor(25+i,0);
            printf("A J1 de jouer :\n\n");
            j1 = tour (j1, j2.tab, j2);
            gagnant = findepartie(j1,j2);

            if (gagnant==0) {
                plateau(j1,j2,i+50);
                cursor(75+i,0);
                printf("A J2 de jouer :\n\n");
                j2 = tour(j2, j1.tab, j1);
                gagnant = findepartie(j1,j2);
            }
            i+=100;
        }while (gagnant==0);
        score(gagnant);
    }
    if (choix==2) {

    }
    if (choix==4) {
        score(0);
    }
    return 0;
}
