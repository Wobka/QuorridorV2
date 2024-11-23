#include <stdio.h>
#include <string.h>

#define MAX_JOUEURS 2
#define TAILLE_NOM 50

typedef struct {
    char nom[TAILLE_NOM];
    int score;
} Joueur;

int charger_scores(const char *scores, Joueur joueurs[], int *nb_joueurs) {
    FILE *fichier = fopen(scores, "r");
    if (fichier == NULL) {
        printf("Aucun fichier trouvé. Un nouveau fichier sera créé.\n");
        return 0;
    }

    while (fscanf(fichier, "%s %d", joueurs[*nb_joueurs].nom, &joueurs[*nb_joueurs].score) == 2) {
        (*nb_joueurs)++;
    }

    fclose(fichier);
    return 1;
}


void sauvegarder_scores(const char *nom_fichier, Joueur joueurs[], int nb_joueurs) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier pour écrire.\n");
        return;
    }

    for (int i = 0; i < nb_joueurs; i++) {
        fprintf(fichier, "%s %d\n", joueurs[i].nom, joueurs[i].score);
    }

    fclose(fichier);
}

int trouver_joueur(Joueur joueurs[], int nb_joueurs, const char *nom) {
    for (int i = 0; i < nb_joueurs; i++) {
        if (strcmp(joueurs[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}
