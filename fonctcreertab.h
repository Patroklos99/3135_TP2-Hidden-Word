#ifndef FONCTCREERTAB_H
#define FONCTCREERTAB_H
#include <stdio.h>

void creer_tableaux(FILE *file, char tab[150][45], char bankMots[13][13]);
void creer_tab_motrecherche(char tab[150][45], FILE *file, const int *compt);
void creer_tab_bankmots(char tab[13][13], FILE *file, int *compt);
#endif
