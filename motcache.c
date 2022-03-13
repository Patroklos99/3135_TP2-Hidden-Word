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

void modifier(char bank[13][13], int x, int y) {
   bank[y][x] = (char) tolower(bank[y][x]);
}

bool trouver_mot(char tab[150][45], char bankMots[13][13], int x, int y, int longueurMatch, int motNumero, enum dir 
        dir) {
   int longueurMot = (int) strlen(tab[motNumero]) - 1;
   if (longueurMot == longueurMatch)
      return true;
   if (x < 0 || y < 0 || x >= 13 || y >= 13)
      return false;
   if ((bankMots[y][x] | 0x20) == (tab[motNumero][longueurMatch] | 0x20)) {
      bool answer;
      switch (dir) {
         case N:
            answer = trouver_mot(tab, bankMots, x + 1, y,
                                 (longueurMatch + 1), motNumero, N);
            break;
         case S:
            answer = trouver_mot(tab, bankMots, x - 1, y,
                                 (longueurMatch + 1), motNumero, S);
            break;
         case O:
            answer = trouver_mot(tab, bankMots, x, y - 1,
                                 (longueurMatch + 1), motNumero, O);
            break;
         case E:
            answer = trouver_mot(tab, bankMots, x, y + 1,
                                 (longueurMatch + 1), motNumero, E);
            break;
      }
      if (answer)
         modifier(bankMots, x, y);
      return answer;
   } else
      return false;
}

void trouver_premier_lettre(char tab[150][45], char bankMots[13][13]) {
   int motNumero = 0;
   int longueurMatch = 0;
   for (int nligne = 0; nligne <= 11; nligne++) {
      for (int ncol = 0; ncol <= 12; ncol++) {
         if ((tab[motNumero][0] | 0x20) == (bankMots[ncol][nligne] | 0x20)) {
            if (trouver_mot(tab, bankMots, nligne, ncol, longueurMatch, motNumero, E)
                || (trouver_mot(tab, bankMots, nligne, ncol, longueurMatch, motNumero, O))
                || trouver_mot(tab, bankMots, nligne, ncol, longueurMatch, motNumero, N)
                || trouver_mot(tab, bankMots, nligne, ncol, longueurMatch, motNumero, S)) {
               motNumero++;
               ncol = 0;
               nligne = -1;
            }
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
   char tab[150][45];
   char bankMots[13][13];
   FILE *file = fopen(argv[1], "r");
   creer_tableaux(file, tab, bankMots);
   recherche_mots(tab, bankMots);
   afficher_mot(bankMots);
}

int main(int argc, char *argv[]) {
   valider_fichier(argc);
   lire_fichier(argv);
   return 0;
}

