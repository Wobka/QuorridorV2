#include <windows.h>
#include "Menu.h"
#include "stdio.h"

void nouvellePartie() {
    printf("Vous avez choisi de lancer une nouvelle partie.\n");

}

void reprendrePartie() {
    printf("Vous avez choisi de reprendre une partie sauvegardee.\n");

}

void afficherAide() {
    printf("Aide du Jeu Quoridor :\n\n");

    printf("Objectif du jeu :\n");
    printf("- Chaque joueur doit atteindre le bord oppose de sa position de depart sur le plateau\n\n");

    printf("Regles de base :\n");
    printf("- Le jeu se joue a 2 ou 4 joueurs. Chaque joueur a un certain nombre de barrieres\n");
    printf("- Le but est de ralentir les adversaires en posant des barrieres sans jamais les bloquer\n\n");

    printf("Deplacement des pions : \n");
    printf("  - Un joueur peut deplacer son pion d'une case a la fois, horizontalement ou verticalement\n");
    printf("  - Si deux pions se font face sans barriere, un joueur peut sauter par-dessus l'autre\n\n");

    printf("Placement des barrieres :\n");
    printf("  - Chaque joueur a un nombre limite de barrieres (10 pour 2 joueurs, 5 pour 4 joueurs)\n");
    printf("  - Les barrieres font 2 cases de long et doivent etre placees entre deux cases, horizontalement ou verticalement\n");
    printf("  - Il est interdit de bloquer totalement le chemin de l'adversaire vers son objectif\n\n");

    printf("Actions possibles a chaque tour :\n");
    printf("  - Deplacer le pion vers une case adjacente si elle est libre\n");
    printf("  - Poser une barriere pour ralentir un adversaire\n");
    printf("  - Passer son tour (si aucune action n'est souhaitee)\n");
    printf("  - Annuler le dernier coup (une seule annulation par partie est permise)\n\n");

    printf("Fin de partie :\n");
    printf("  - La partie se termine lorsqu'un joueur atteint le bord oppose a sa ligne de depart\n\n");

    printf("Options supplementaires :\n");
    printf("  - Sauvegarder et reprendre : Vous pouvez sauvegarder la partie et la reprendre plus tard\n");
    printf("  - Scores : Le score de chaque joueur est mis a jour et sauvegarde apres chaque partie\n\n");
}

void afficherScores() {
    printf("Affichage des scores des joueurs\n\n");
}

void quitter() {
    printf("Merci et a bientot");
}


int menu()
{
    int choix;
    do {
        printf("Menu du Jeu Quoridor\n");
        printf("1. Lancer une nouvelle partie\n");
        printf("2. Reprendre une partie sauvegardee\n");
        printf("3. Afficher l'aide\n");
        printf("4. Afficher les scores des joueurs\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix\n");
        scanf("%d", &choix);


        switch (choix) {
            case 1:
                nouvellePartie();
                return 1;  
            case 2:
                reprendrePartie();
            return 2;
            case 3:
                afficherAide();
                return 0;
            case 4:
                afficherScores();
                return 4;
            case 5:
                quitter();
                return 0;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 5 && choix != 0 && choix != 2 && choix != 4);
}

void cursor(int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;  // sert à déplacer le curseur en utilisant les coordonnées 
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
