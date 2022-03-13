#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "fonctlecture.h"
#include "fonctcreertab.h"
#include "fonctrecherche.h"
#include "fonctaffichage.h"
#include "motcache.h"

/*
 * Rempli le tableau bankmots avec chaque char correspondant à la grille dans le fichier à lire.
 *
 * @param tab_bankmots tableau ou les mots à chercher seront placés.
 * @param *file pointeur vers le fichier à lire.
 * @param *compt qui sera modifié à 12 dû aux 12 lignes lus pour la grille dans le fichier.
 * */
void creer_tab_bankmots(char tab_bankmots[13][13], FILE *file, int *compt) {
   int c;
   int a = 0;
   int b = 0;
   int compter = 0;
   while ((c = getc(file)) && compter <= 155) {
      compter++;
      if (a < 13 && b < 12)
         tab_bankmots[a][b] = (char) c;
      a++;
      if (a >= 13) {
         a = 0;
         b++;
      }
   }
   *compt = 12;
}

/*
 * Rempli le tableau de mots à chercher avec chaque ligne(mot) du fichier à lire.
 *
 * @param tab_bankmots tableau ou les mots à chercher seront placés.
 * @param *file pointeur vers le fichier à lire.
 * @param *compt compteur qui permet continuellement d'initialiser i à la position correcte du mot.
 * */
void creer_tab_motrecherche(char tab_bankmots[150][45], FILE *file, const int *compt) {
   int i = *compt;
   i = i - 13;
   (fgets(tab_bankmots[i], 14, file));
}

/*
 * Segmentate le fichier à lire en 2 parties correspondates aux tableaux visés.
 *
 * @param *file le pointeur vers le debut du fichier à lire.
 * @param tab_mots tableau ou les mots à chercher seront placés.
 * @param bank_mots tableau ou la grille 12x12 sera placé.
 * */
void creer_tableaux(FILE *file, char tab_mots[150][45], char bank_mots[13][13]) {
   int compt = 0;
   while (file && compt <= 45) {
      compt <= 12 ? creer_tab_bankmots(bank_mots, file, (int *) &compt) : creer_tab_motrecherche(tab_mots, file, (int *)&compt);
      compt++;
   }
   fclose(file);
}

