#ifndef SCORE_H
#define SCORE_H

#endif //SCORE_H
#ifndef CHARGER_SCORE_H
#define CHARGER_SCORE_H

#endif
typedef struct {
    char nom[50];
    int score;
} Joueur;
int charger_scores();
void sauvegarder_scores();
int trouver_joueur();
void score(int gagnant);
