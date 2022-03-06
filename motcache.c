#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
    char tabPointeur[13];
    size_t nbPtr;
    int compt;
} mots;

void creerTabMots(char tab[13][13], FILE *file, int *compt) {
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

void obtenirMots(char tab[150][20], FILE *file, const int *compt) {
    int i = *compt;
    i = i - 13;
    (fgets(tab[i], 13, file));
}

/*bool horizontal(char tab[150][20], char bankMots[13][13]) {
    bool reponse = true;
    int w = 0;
    int b = 0;
    int a;
    for (a = 0; a <= strlen(tab[w]) - 1; a++) {
        for (w = 0; w <= strlen(tab[w]) - 1; ++w) {
            if (tab[0][w] != bankMots[a][b]) {
                reponse = false;
                break;
            }
            a++;
        }
    }
    return reponse;
}*/

bool trouverMot(char tab[150][20], char bankMots[13][13], int x, int y, int longueurMatch, int motNumero) {
    int longueurMot = (int) strlen(tab[motNumero]) - 1;
    if (longueurMot == longueurMatch)
        return true;

    if (x < 0 || y < 0 || x >= 12 || y >= 12){
        return false;}

    if (bankMots[y][x] == tab[motNumero][longueurMatch]) {
        char temp = tab[x][y];

        bool reponse =trouverMot(tab, bankMots, x - 1, y, (longueurMatch + 1), motNumero) |
                      trouverMot(tab, bankMots, x + 1, y, (longueurMatch + 1), motNumero) |
                      trouverMot(tab, bankMots, x, y - 1, (longueurMatch + 1), motNumero) |
                      trouverMot(tab, bankMots, x, y + 1, (longueurMatch + 1), motNumero);
        tab[x][y] = temp;

        return reponse;
    } else 
        return false;
}

void trouverPremierLettre(char tab[150][20], char bankMots[13][13]) {
    int w = 0;
        int longueurMatch = 0;
        for (int nligne = 0; nligne <= 11; nligne++) {
            for (int ncol = 0; ncol <= 12; ncol++) {
                if (tab[w][0] == bankMots[ncol][nligne]) {
                    if (trouverMot(tab, bankMots, nligne, ncol, longueurMatch, w)) {
                        printf("mot trouve -> %s \n", tab[w]);
                        w++;
                        ncol = 0;
                        nligne = 0;
                    }
                }
            }
        }
}

void rechercheMots(char tab[150][20], char bankMots[13][13]) {
    trouverPremierLettre(tab, bankMots);
}

void lireFichier(char **argv, mots mot1, char tab[150][20]) {
    FILE *file = fopen(argv[1], "r");
    int compteur = 0;
    char bankMots[13][13];

    while (file && compteur <= 33) {
        //line[i][strlen(line[i]) - 1] = '\0';
        compteur <= 12 ? creerTabMots(bankMots, file, (int *) &compteur) : obtenirMots(tab, file, (int *) &compteur);
        compteur++;
    }
    for (int b = 0; b <= 11; b++) {
        for (int a = 0; a <= 12; a++)
            printf("%c", bankMots[a][b]);
    }
    fclose(file);
    rechercheMots(tab, bankMots);
}

int main(int argc, char *argv[]) {
    char tab[150][20];
    mots mot1 = {{0}, 2, 0};
    lireFichier(argv, mot1, tab);
    /*for (int w = 0; w <= 20; ++w) {
        printf("%s", tab[w]);
    }*/
    return 0;
}

