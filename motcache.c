/**
 *  Auteur: Renzo Arturo Salcedo
 *  Code Permanent: SALR02089408
 *  Cours: INF3135 TP2 UQAM
 *  Session: Hiver 2022
 *
 *  Classe motcache.c
 *  Represente la classe main, de plusieurs autres classes, contenant le main.
 *  Ce projet execute la lecture d'un fichier comme argument et fait l'affichage d'un mot caché à l'intérieur de ce fichier.
 */

#include "fonctrecherche.h"
#include "fonctlecture.h"
#include "fonctcreertab.h"
#include "fonctaffichage.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   char tab_mots[150][45];
   char bank_mots[13][13];
   lire_fichier(argv, tab_mots,bank_mots,argc);
   trouver_premier_lettre(tab_mots, bank_mots);
   afficher_mot(bank_mots);
   return 0;
}
