#include <stdio.h>
#include "fonc jeu.h"
#include "Menu.h"


void plateau(struct joueur j1, struct joueur j2, int n) {
    cursor(n,0);
    color(15,0);
    printf("   ");
    for (int i = 0 ;i < 9; i++) {
        printf(" %d  ", i+1);
    }
    printf("\n");
    for (int i = 0 ;i < 9; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < 9; j++) {
            if (i+1==j1.x && j+1==j1.y){
                color(0,15);
                printf(" @ ");
            }
            else if (i+1==j2.x && j+1==j2.y) {
                color(0,15);
                printf(" * ");
            }
            else {
                color(0,15);
                printf("   ");
            }
            if(i+1==j1.tab[i].x1 && j+2==(j1.tab[i].y1+j1.tab[i].y2)/2+1){
                printf("%c", 0xBA);
            }
            else if(i+1==j2.tab[i].x1 && j+2==(j2.tab[i].y1+j1.tab[i].y2)/2+1){
                printf("%c", 0xBA);
            }
            else {
                color(15,0);
                printf(" ");
            }
        }
        printf("\n\n");
    }


    cursor(20+n,0);
    color(15,0);
    printf(" J1 ");
    cursor(23+n,0);
    printf(" J2 ");
    printf("\n\n");
    for (int i = 0; i < 10; i++) {
        if (j1.tab[i].x1==j1.tab[i].x2) {
            cursor(j1.tab[i].x1+n,(j1.tab[i].y1+j1.tab[i].y2)/2+1);
            printf("%c", 0xBA);
        }
        if (j2.tab[i].x1==j2.tab[i].x2) {
            cursor(j2.tab[i].x1+n,(j2.tab[i].y1+j2.tab[i].y2)/2+1);
            printf("%c", 0xBA);
        }
        if (j1.tab[i].y1==j1.tab[i].y2) {
            cursor(((j1.tab[i].x1+j1.tab[i].x2)/2)+n,j1.tab[i].y1-1+1);
            printf("%c%c%c", 0xCD, 0xCD, 0xCD);
        }
        if (j2.tab[i].y1==j2.tab[i].y2) {
            cursor(((j2.tab[i].x1+j2.tab[i].x2)/2)+n,j2.tab[i].y1-1+1);
            printf("%c%c%c", 0xCD, 0xCD, 0xCD);
        }
    }
    cursor(25+n,0);
    printf("\n\n");
}
