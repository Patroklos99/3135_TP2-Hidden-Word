#ifndef FONCTLECTURE_H
#define FONCTLECTURE_H
#include <stdio.h>

void lire_fichier(char **argv, char tab_mots[150][45], char bank_mots[13][13], int argc);
void valider_fichier_args(int argc);
void valider_fichier_existe(FILE *file);

#endif
