#ifndef FONC_JEU_H
#define FONC_JEU_H

#endif //FONC_JEU_H


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

struct partie {
    struct joueur joueur1;
    struct joueur joueur2;
};

int findepartie(struct joueur j1, struct joueur j2);
int mouvementimpossible(int x, int y, int n, struct bar tab1[10], struct bar tab2[10]);
struct joueur tour(struct joueur j1, struct bar tab2[], struct joueur j2);
