#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

enum dir {
    N, E, S, O
};

void creer_tab_mots(char tab[13][13], FILE *file, int *compt) {
   int c;
   int a = 0;
   int b = 0;
   int compter = 0;
   while ((c = getc(file)) && compter <= 155) {
      compter++;
      if (a < 13 && b < 12)
         tab[a][b] = (char) c;
      a++;
      if (a >= 13) {
         a = 0;
         b++;
      }
   }
   *compt = 12;
}

void obtenir_mots(char tab[150][45], FILE *file, const int *compt) {
   int i = *compt;
   i = i - 13;
   (fgets(tab[i], 14, file));
}

void modifier_minuscule(char bank[13][13], int x, int y) {
   bank[y][x] = (char) tolower(bank[y][x]);
}

bool trouver_mot(char tab[150][45], char bank_mots[13][13], int x, int y, int longueur_match, int mot_numero, enum dir
        dir) {
   int longueur_mot = (int) strlen(tab[mot_numero]) - 1;
   if (longueur_mot == longueur_match)
      return true;
   if (x < 0 || y < 0 || x >= 13 || y >= 13)
      return false;
   if ((bank_mots[y][x] | 0x20) == (tab[mot_numero][longueur_match] | 0x20)) {
      bool answer;
      switch (dir) {
         case N:
            answer = trouver_mot(tab, bank_mots, x + 1, y,
                                 (longueur_match + 1), mot_numero, N);
            break;
         case S:
            answer = trouver_mot(tab, bank_mots, x - 1, y,
                                 (longueur_match + 1), mot_numero, S);
            break;
         case O:
            answer = trouver_mot(tab, bank_mots, x, y - 1,
                                 (longueur_match + 1), mot_numero, O);
            break;
         case E:
            answer = trouver_mot(tab, bank_mots, x, y + 1,
                                 (longueur_match + 1), mot_numero, E);
            break;
      }
      if (answer)
         modifier_minuscule(bank_mots, x, y);
      return answer;
   } else
      return false;
}

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

void afficher_mot(char bankMots[13][13]) {
   for (int b = 0; b <= 11; b++) {
      for (int a = 0; a <= 12; a++)
         if (isupper(bankMots[a][b]))
            printf("%c", bankMots[a][b]);
   }
}

void recherche_mots(char tab[150][45], char bankMots[13][13]) {
   trouver_premier_lettre(tab, bankMots);
}

void valider_fichier_existe(FILE *file) {
   if (!file) {
      printf("Fichier n'existe pas\n");
      exit(0);
   }
}

void creer_tableaux(FILE *file, char tab[150][45], char bankMots[13][13]) {
   int compt = 0;
   valider_fichier_existe(file);
   while (file && compt <= 45) {
      compt <= 12 ? creer_tab_mots(bankMots, file, (int *) &compt) : obtenir_mots(tab, file, (int *) &compt);
      compt++;
   }
   fclose(file);
}

void valider_fichier(int argc) {
   if (argc == 1) {
      printf("Argument manquant\n");
      exit(0);
   }
   if (argc > 2) {
      printf("Trop d'arguments\n");
      exit(0);
   }
}

void lire_fichier(char **argv) {
   char tab_mots[150][45];
   char bank_mots[13][13];
   FILE *file = fopen(argv[1], "r");
   creer_tableaux(file, tab_mots, bank_mots);
   recherche_mots(tab_mots, bank_mots);
   afficher_mot(bank_mots);
}

int main(int argc, char *argv[]) {
   valider_fichier(argc);
   lire_fichier(argv);
   return 0;
}
