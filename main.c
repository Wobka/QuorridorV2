#include <stdio.h>
#include "Menu.h"

struct bar {
    int x1;
    int y1;
    int x2;
    int y2;
};

struct joueur {
    int x;
    int y;
    int bar;
    struct bar tab[10];
    int x_pre;
    int y_pre;
    int annuler;
};


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
            color(15,0);
            printf(" ");
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
        cursor(j1.tab[i].x1+n,j1.tab[i].y1);
        printf("%c", 0xBA);
    }
    for (int i = 0; i < 10; i++) {
        cursor(j2.tab[i].x1+n,j2.tab[i].y1);
        printf("%c", 0xBA);
    }
    printf("\n\n");
}

struct joueur tour(struct joueur j1) {
    printf("Actions possibles: \n1 - deplacer son pion\n2 - poser une barriere\n3 - passer son tour\n4 - annuler la derniere action\n");
    int n,m;
    do {
        printf("Choisissez une action:\n");
        scanf("%d",&n);
    }while (n<1 || n>4 || (j1.annuler==1 && n==4)||(j1.bar<1&&n==2));
    if (n==1) {
        j1.x_pre = j1.x;
        j1.y_pre = j1.y;

        printf("Directions possibles: \n");
        if (j1.x<9) {
            printf("1 - Bas\n");
        }
        if (j1.x>1) {
            printf("2 - Haut\n");
        }
        if (j1.y<9) {
            printf("3 - Droite\n");
        }
        if (j1.y>1) {
            printf("4 - Gauche\n");
        }
        do {
            printf("Choisissez une direction:\n");
            scanf("%d",&m);
        }while (m<1 || m>4);
        if (m==1) {
            j1.x++;
        }
        else if (m==2) {
            j1.x--;
        }
        else if (m==3) {
            j1.y++;
        }
        else if (m==4) {
            j1.y--;
        }

    }
    else if (n==2) {
        do {
            printf("Entrez les coordonnees des 2 cases que vous voulez separer: \n");
            scanf("%d%d",&j1.tab[j1.bar].x1,&j1.tab[j1.bar].y1);
            scanf("%d%d",&j1.tab[j1.bar].x2,&j1.tab[j1.bar].y2);
        }while(j1.tab[j1.bar].x1<1||j1.tab[j1.bar].x1>9||j1.tab[j1.bar].y1<1||j1.tab[j1.bar].y1>9||j1.tab[j1.bar].x2<1||j1.tab[j1.bar].x2>9||j1.tab[j1.bar].y2<1||j1.tab[j1.bar].y2>9);
        j1.bar--;
    }
    else if (n==3) {
        printf("Vous avez saute votre tour. \n");
    }
    else if (n==4) {
        if (j1.annuler==0) {
            do {
                printf("Annulation du dernier coup:\n 1 - Le dernier coup etait un deplacement de pion\n2 - Le dernier coup etait un placement de barriere\n");
                scanf("%d",&m);
            }while (m<1 || m>2);
            if (m==1) {
                j1.x=j1.x_pre;
                j1.y=j1.y_pre;
            }
            else if (m==2) {
                j1.bar++;
                j1.tab[j1.bar].x1=20;
                j1.tab[j1.bar].y1=j1.bar*3+5;
                j1.tab[j1.bar].x2=21;
                j1.tab[j1.bar].y2=j1.bar*3+5;
            }

            j1.annuler=1;
        }
        else {
            printf("Vous avez deja annule un coup\n");
        }
    }
    n = 0;
    return j1;
}

int main()
{
    struct joueur j1;
    j1.x = 1;
    j1.y = 5;
    j1.bar = 10;
    j1.x_pre = j1.x;
    j1.y_pre = j1.y;
    j1.annuler=0;
    struct joueur j2;
    j2.x = 9;
    j2.y = 5;
    j2.bar = 10;
    j2.x_pre = j2.x;
    j2.y_pre = j2.y;
    j2.annuler=0;
    for (int i = 0; i < 10; i++) {
        j1.tab[i].x1=20;
        j1.tab[i].y1=i*3+5;
        j1.tab[i].x2=21;
        j1.tab[i].y2=i*3+5;

    }
    for (int i = 0; i < 10; i++) {
        j2.tab[i].x1=23;
        j2.tab[i].y1=i*3+5;
        j2.tab[i].x2=24;
        j2.tab[i].y2=i*3+5;

    }
    int n = 0;
    for (int i = 0; i < 1000; i+=100) {
        plateau(j1,j2,i);
        j1 = tour (j1);
        plateau(j1,j2,i+50);
        j2 = tour(j2);
    }

    return 0;
}