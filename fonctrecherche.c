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
 * Cherche le mot à trouver dans les 4 sens.
 *
 * @param tab_mots tableau ou les mots à chercher seront placés.
 * @param bank_mots tableau ou la grille 12x12 sera placé.
 * @param nligne position de la ligne ou la premiere lettre a été trouvée.
 * @param ncol positon de la colonne ou la premiere lettre a été trouvée.
 * */
void rechercher_4sens(char tab_mots[150][45], char bank_mots[13][13], int *nligne, int *ncol, int *mot_numero) {
   int longueur_match = 0;
   int nligne1 = *nligne;
   int ncol1 = *ncol;
   int mot_numero1 = *mot_numero;
   if (trouver_mot(tab_mots, bank_mots, nligne1, ncol1, longueur_match, mot_numero1, E)
       || (trouver_mot(tab_mots, bank_mots, nligne1, ncol1, longueur_match, mot_numero1, O))
       || trouver_mot(tab_mots, bank_mots, nligne1, ncol1, longueur_match, mot_numero1, N)
       || trouver_mot(tab_mots, bank_mots, nligne1, ncol1, longueur_match, mot_numero1, S)) {
      ++*mot_numero;
      *ncol = 0;
      *nligne = -1;
   }
}

/*
 * Recherche de facon recursive le mot dans tous les sens, dépendant de la direction donnée.
 *
 * @param tab_mots tableau ou les mots à chercher seront placés.
 * @param tab_bankmots tableau ou la grille 12x12 sera placé.
 * @param x position de la ligne ou la premiere lettre a été trouvée.
 * @param y positon de la colonne ou la premiere lettre a été trouvée.
 * @param longueur_match longueur du mot recherché.
 * @param mot_numero position du mot recherché dans le tableau de mots recherchés.
 *
 * */
bool trouver_mot(char tab_mots[150][45], char tab_bankmots[13][13], int x, int y, int longueur_match, int mot_numero, enum dir
        dir) {
   int longueur_mot = (int) strlen(tab_mots[mot_numero]) - 1;
   if (longueur_mot == longueur_match)
      return true;
   if (x < 0 || y < 0 || x >= 13 || y >= 13)
      return false;
   if ((tab_bankmots[y][x] | 0x20) == (tab_mots[mot_numero][longueur_match] | 0x20)) {
      bool answer;
      switch (dir) {
         case N:
            answer = trouver_mot(tab_mots, tab_bankmots, x + 1, y,
                                 (longueur_match + 1), mot_numero, N);
            break;
         case S:
            answer = trouver_mot(tab_mots, tab_bankmots, x - 1, y,
                                 (longueur_match + 1), mot_numero, S);
            break;
         case O:
            answer = trouver_mot(tab_mots, tab_bankmots, x, y - 1,
                                 (longueur_match + 1), mot_numero, O);
            break;
         case E:
            answer = trouver_mot(tab_mots, tab_bankmots, x, y + 1,
                                 (longueur_match + 1), mot_numero, E);
            break;
      }
      if (answer)
         modifier_minuscule(tab_bankmots, x, y);
      return answer;
   } else
      return false;
}

/*
 * Cherche la première lettre du mot n à trouver dans la bank_mots.
 *
 * @param tab_mots tableau ou les mots à chercher seront placés.
 * @param bank_mots tableau ou la grille 12x12 sera placé.
 * */
void trouver_premier_lettre(char tab_mots[150][45], char bank_mots[13][13]) {
   int mot_numero = 0;
   for (int nligne = 0; nligne <= 11; nligne++) {
      for (int ncol = 0; ncol <= 12; ncol++) {
         if ((tab_mots[mot_numero][0] | 0x20) == (bank_mots[ncol][nligne] | 0x20)) {
            rechercher_4sens(tab_mots, bank_mots, &nligne, &ncol, &mot_numero);
         }
      }
   }
}

/*
 * Modifie la lettre n à la positon x,y en minuscule.
 *
 * @param bank_mots tableau ou la grille 12x12 sera placé.
 * @param x position de la ligne ou la premiere lettre a été trouvée.
 * @param y positon de la colonne ou la premiere lettre a été trouvée.
 * */
void modifier_minuscule(char bank_mots[13][13], int x, int y) {
   bank_mots[y][x] = (char) tolower(bank_mots[y][x]);
}
