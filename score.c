#include "score.h"
#include <stdio.h>
#include <string.h>

#define MAX_JOUEURS 2
#define TAILLE_NOM 50



int charger_scores(const char *scores, Joueur joueurs[], int *nb_joueurs) { 
    FILE *fichier = fopen(scores, "r"); //"r" car on est en mode lecture
    if (fichier == NULL) {
        printf("Aucun fichier trouvé. Un nouveau fichier sera créé.\n");
        return 0;
    }

    while (fscanf(fichier, "%s %d", joueurs[*nb_joueurs].nom, &joueurs[*nb_joueurs].score) == 2) { //lit une ligne du fichier tant que nom et score sont corrects
        (*nb_joueurs)++;
    }

    fclose(fichier);
    return 1;
}


void sauvegarder_scores(const char *nom_fichier, Joueur joueurs[], int nb_joueurs) {
    FILE *fichier = fopen(nom_fichier, "w"); //"w" car on est en mode écriture
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier pour écrire.\n");
        return;
    }

    for (int i = 0; i < nb_joueurs; i++) {
        fprintf(fichier, "%s %d\n", joueurs[i].nom, joueurs[i].score); //écriture du nom et du score de chaque joueur
    }

    fclose(fichier);
}

int trouver_joueur(Joueur joueurs[], int nb_joueurs, const char *nom) {
    for (int i = 0; i < nb_joueurs; i++) {
        if (strcmp(joueurs[i].nom, nom) == 0) { //comparer pour voir si un joueur a déjà joué
            return i;
        }
    }
    return -1;
}

void score (int gagnant) {
    Joueur joueurs[MAX_JOUEURS];
    int nb_joueurs = 0;
    char fichier[] = "scores.txt"; 
    charger_scores(fichier, joueurs, &nb_joueurs);

    char nom_joueur1[TAILLE_NOM], nom_joueur2[TAILLE_NOM];
    char rejouer;

    printf("Bienvenue au gestionnaire de scores de jeu !\n");

    printf("\nEntrez le nom du joueur 1 : ");
    scanf("%s", nom_joueur1);
    printf("\nEntrez le nom du joueur 2 : ");
    scanf("%s", nom_joueur2);

    int indice1 = trouver_joueur(joueurs, nb_joueurs, nom_joueur1);
    if (indice1 == -1) {
        strcpy(joueurs[nb_joueurs].nom, nom_joueur1);
        joueurs[nb_joueurs].score = 0;
        indice1 = nb_joueurs++;
    }

    int indice2 = trouver_joueur(joueurs, nb_joueurs, nom_joueur2);
    if (indice2 == -1) {
        strcpy(joueurs[nb_joueurs].nom, nom_joueur2);
        joueurs[nb_joueurs].score = 0;
        indice2 = nb_joueurs++;
    }


    if (gagnant == 1) {
        joueurs[indice1].score += 5;
    } else if (gagnant == 2) {
        joueurs[indice2].score += 5;
    }


    printf("\n-----Scores :-----\n");
    printf("%s : %d points\n", joueurs[indice1].nom, joueurs[indice1].score);
    printf("%s : %d points\n", joueurs[indice2].nom, joueurs[indice2].score);

    sauvegarder_scores(fichier, joueurs, nb_joueurs);



    printf("\nMerci d'avoir joue ! Les scores finaux ont ete sauvegardes dans '%s'.\n", fichier);
}
