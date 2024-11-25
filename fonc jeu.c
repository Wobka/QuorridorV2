#include "fonc jeu.h"
#include <stdio.h>
#include "Menu.h"



int findepartie(struct joueur j1, struct joueur j2) {
    if (j1.x == 9) {
        printf("Joueur 1 gagne !\n");
        return 1;
    } else if (j2.x == 1) {
        printf("Joueur 2 gagne !\n");
        return 2;
    }
    return 0;
}

int mouvementimpossible(int x, int y, int n, struct bar tab1[10], struct bar tab2[10]) {
    for (int i = 0; i < 10; i++) {
        struct bar b = tab1[i];
        b.x1++;
        b.x2++;
        b.x1=b.x1/2;
        b.x2=b.x2/2;
        b.y1++;
        b.y2++;
        b.y1=b.y1/4;
        b.y2=b.y2/4;
        if (n == 1 && b.y2 == b.y1 == y && (b.x1 == x && b.x2 == x+1 || b.x1 == x+1 && b.x2 == x )) {
            return 1;
        }
        if (n == 2 && b.x1 == x && b.y1 == y - 1 && b.x2 == x && b.y2 == y - 1) {
            return 1;
        }
        if (n == 3 && b.x1 == x + 1 && b.y1 == y && b.x2 == x + 1 && b.y2 == y) {
            return 1;
        }
        if (n == 4 && b.x1 == x - 1 && b.y1 == y && b.x2 == x - 1 && b.y2 == y) {
            return 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        struct bar b = tab2[i];
        b.x1++;
        b.x2++;
        b.x1=b.x1/2;
        b.x2=b.x2/2;
        b.y1++;
        b.y2++;
        b.y1=b.y1/4;
        b.y2=b.y2/4;
        if (n == 1 && b.x1 == x && b.y1 == y + 1 && b.x2 == x && b.y2 == y + 1) {
            return 1;
        }
        if (n == 2 && b.x1 == x && b.y1 == y - 1 && b.x2 == x && b.y2 == y - 1) {
            return 1;
        }
        if (n == 3 && b.x1 == x + 1 && b.y1 == y && b.x2 == x + 1 && b.y2 == y) {
            return 1;
        }
        if (n == 4 && b.x1 == x - 1 && b.y1 == y && b.x2 == x - 1 && b.y2 == y) {
            return 1;
        }
    }

    return 0;
}

struct joueur tour(struct joueur j1, struct bar tab2[], struct joueur j2) {
    printf("Actions possibles: \n1 - deplacer son pion\n2 - poser une barriere\n3 - passer son tour\n4 - annuler la derniere action\n");
    int n,m;
    do {
        printf("Choisissez une action:\n");
        scanf("%d",&n);
    }while (n<1 || n>4 || (j1.annuler==1 && n==4)||(j1.bar<0&&n==2));
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
        }while (m<1 || m>4 || mouvementimpossible(j1.x , j1.y, m, j1.tab, tab2)==1);
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
        }while((j1.tab[j1.bar].x1 == j1.tab[j1.bar].x2 && j1.tab[j1.bar].y1 == j1.tab[j1.bar].y2)||(j1.tab[j1.bar].x1 != j1.tab[j1.bar].x2 && j1.tab[j1.bar].y1 != j1.tab[j1.bar].y2)||j1.tab[j1.bar].x1<1||j1.tab[j1.bar].x1>9||j1.tab[j1.bar].y1<1||j1.tab[j1.bar].y1>9||j1.tab[j1.bar].x2<1||j1.tab[j1.bar].x2>9||j1.tab[j1.bar].y2<1||j1.tab[j1.bar].y2>9);
        j1.tab[j1.bar].x1=j1.tab[j1.bar].x1*2-1;
        j1.tab[j1.bar].x2=j1.tab[j1.bar].x2*2-1;
        j1.tab[j1.bar].y1=j1.tab[j1.bar].y1*4-1;
        j1.tab[j1.bar].y2=j1.tab[j1.bar].y2*4-1;
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
