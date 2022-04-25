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
 * Affiche le mot caché dans le grille 12x12.
 *
 * @param bank_mots contient la grille 12x12.
 * */
void afficher_mot(char bank_mots[13][13]) {
   for (int b = 0; b <= 11; b++) {
      for (int a = 0; a <= 12; a++)
         if (isupper(bank_mots[a][b]))
            printf("%c", bank_mots[a][b]);
   }
	printf("\n");
}

