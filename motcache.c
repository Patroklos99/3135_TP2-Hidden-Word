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
