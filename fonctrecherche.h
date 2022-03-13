#ifndef FONCTRECHERCHE_H
#define FONCTRECHERCHE_H
#include <stdio.h>
#include <stdbool.h>  

enum dir {
    N, E, S, O
};

void trouver_premier_lettre(char tab_mots[150][45], char bank_mots[13][13]);
void rechercher_4sens(char tab_mots[150][45], char bank_mots[13][13], int *nligne, int *ncol, int *mot_numero);
bool trouver_mot(char tab[150][45], char bank_mots[13][13], int x, int y, int longueur_match, int mot_numero, enum dir dir);
void modifier_minuscule(char bank[13][13], int x, int y);
#endif

