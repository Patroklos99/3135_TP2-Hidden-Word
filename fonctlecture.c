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
 * Valide que le fichier existe, arrete le programme dans le cas contraire.
 *
 * @param *file pointeur vers le fichier à lire.
 * */
void valider_fichier_existe(FILE *file) {
   if (!file) {
      printf("Fichier n'existe pas\n");
      exit(0);
   }
}

/*
 * Valide le nb d'arguments, arrete le programme s'il ny pas d'argument ou s'il y en a trop.
 *
 * @param argc nb d'arguments.
 * */
void valider_fichier_args(int argc) {
   if (argc == 1) {
      printf("Argument manquant\n");
      exit(0);
   }
   if (argc > 2) {
      printf("Trop d'arguments\n");
      exit(0);
   }
}

/*
 * Lit le fichier passé en argument.
 *
 * @param argv reference vers le fichier.
 * */
void lire_fichier(char **argv, char tab_mots[150][45], char bank_mots[13][13], int argc) {
   valider_fichier_args(argc);
   FILE *file = fopen(argv[1], "r");
   valider_fichier_existe(file);
   creer_tableaux(file, tab_mots, bank_mots);
}
