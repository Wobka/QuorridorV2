#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
#include "fonc jeu.h"






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

void sauvegarde(struct partie partie_actuelle) {
    const char *nom_fichier = "sauvegarde.dat";

    int choix;
    printf("1: Sauvegarder la partie\n2: Charger la dernière partie sauvegardée\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);

    if (choix == 1) {
        sauvegarder_partie(&partie_actuelle, nom_fichier);
    } else if (choix == 2) {
        charger_partie(&partie_actuelle, nom_fichier);

        printf("Données des joueurs après chargement :\n");

        printf("Joueur 1 : x: %d, y: %d, bar: %d\n",
               partie_actuelle.joueur1.x,
               partie_actuelle.joueur1.y,
               partie_actuelle.joueur1.bar);
        for (int i = 0; i < 10; i++) {
            printf("Joueur 1 : tab[%d]: x1 = %d, y1 = %d, x2 = %d, y2 = %d\n",
                   i,
                   partie_actuelle.joueur1.tab[i].x1,
                   partie_actuelle.joueur1.tab[i].y1,
                   partie_actuelle.joueur1.tab[i].x2,
                   partie_actuelle.joueur1.tab[i].y2);
        }

        printf("Joueur 2 : x: %d, y: %d, bar: %d\n",
               partie_actuelle.joueur2.x,
               partie_actuelle.joueur2.y,
               partie_actuelle.joueur2.bar);
        for (int i = 0; i < 10; i++) {
            printf("Joueur 2 : tab[%d]: x1 = %d, y1 = %d, x2 = %d, y2 = %d\n",
                   i,
                   partie_actuelle.joueur2.tab[i].x1,
                   partie_actuelle.joueur2.tab[i].y1,
                   partie_actuelle.joueur2.tab[i].x2,
                   partie_actuelle.joueur2.tab[i].y2);
        }
    } else {
        printf("Option invalide.\n");
    }
}
