//
// Created by gabri on 23/11/2024.
//
#include <stdio.h>
#include <stdlib.h>

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
};


struct partie {
    struct joueur joueur1;
    struct joueur joueur2;
};


void sauvegarder_partie(struct partie *p, const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "wb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
        exit(EXIT_FAILURE);
    }
    fwrite(p, sizeof(struct partie), 1, f);
    fclose(f);
    printf("Partie sauvegardée dans %s\n", nom_fichier);
}


void charger_partie(struct partie *p, const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
        exit(EXIT_FAILURE);
    }
    fread(p, sizeof(struct partie), 1, f);
    fclose(f);
    printf("Partie chargée depuis %s\n", nom_fichier);
}
