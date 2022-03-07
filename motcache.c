#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

typedef struct {
    char *key;
    int valeur;
} positions;

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

void archiverPositions(int x, int y, positions positions1) {
    const char key[] = "a";
    positions1.key = malloc(sizeof(key));
    memcpy(positions1.key, key, sizeof(key));

    positions1.valeur = x;
    printf("%s%d ", positions1.key, positions1.valeur);
}

void identifierPositions() {

}

void modifier(char bank[13][13], int x, int y) {
    /*printf*/("Positon trouve a (%d:%d)\n", x, y);
    bank[y][x] = (char) tolower(bank[y][x]);
    /*for (int b = 0; b <= 11; b++) {
        for (int a = 0; a <= 12; a++)
            printf("%c", bank[a][b]);
    }*/
}

trouverMot(char tab[150][20], char bankMots[13][13], int x, int y, int longueurMatch, int motNumero, positions
positions1) {

    /*printf("recherche du mot: %s\n", tab[motNumero]);
    for (int b = 0; b <= 11; b++) {
        for (int a = 0; a <= 12; a++)
            printf("%c", bankMots[a][b]);
    }*/
    int longueurMot = (int) strlen(tab[motNumero]) - 1;
    if (longueurMot == longueurMatch) {
        identifierPositions();
        /*for (int b = 0; b <= 11; b++) {
            for (int a = 0; a <= 12; a++)
                printf("%c", bankMots[a][b]);
        }*/
        return true;
    }
    if (x < 0 || y < 0 || x >= 13 || y >= 13)
        return false;

    if ((bankMots[y][x] | 0x20) == (tab[motNumero][longueurMatch] | 0x20)) {
        //archiverPositions(x, y, positions1);
        printf("recherche de lettre %c\n", bankMots[y][x]);
        modifier(bankMots, x, y);
        // marké comme visité
        //char temp = tab[x][y];
        //tab[x][y] = '#';
        bool answer = trouverMot(tab, bankMots, x - 1, y, (longueurMatch + 1), motNumero, positions1) |
                      trouverMot(tab, bankMots, x + 1, y, (longueurMatch + 1), motNumero, positions1) |
                      trouverMot(tab, bankMots, x, y - 1, (longueurMatch + 1), motNumero, positions1) |
                      trouverMot(tab, bankMots, x, y + 1, (longueurMatch + 1), motNumero, positions1);
        //tab[x][y] = temp;
        return answer;
    } else
        return false;
}

void trouverPremierLettre(char tab[150][20], char bankMots[13][13], positions positions1) {
    int w = 0;
    int longueurMatch = 0;
    for (int nligne = 0; nligne <= 11; nligne++) {
        for (int ncol = 0; ncol <= 12; ncol++) {
            if ((tab[w][0] | 0x20) == (bankMots[ncol][nligne] | 0x20)) {
                if (trouverMot(tab, bankMots, nligne, ncol, longueurMatch, w, positions1)) {
                    printf("mot trouve -> %s", tab[w]);
                    w++;
                    ncol = -1;
                    nligne = 0;
                }
            }
        }
    }
}

void rechercheMots(char tab[150][20], char bankMots[13][13], positions positions1) {
    trouverPremierLettre(tab, bankMots, positions1);
}

void lireFichier(char **argv, char tab[150][20], positions positions1) {
    FILE *file = fopen(argv[1], "r");
    int compteur = 0;
    char bankMots[13][13];


    while (file && compteur <= 33) {
        //line[i][strlen(line[i]) - 1] = '\0';
        compteur <= 12 ? creerTabMots(bankMots, file, (int *) &compteur) : obtenirMots(tab, file, (int *) &compteur);
        compteur++;
    }
    fclose(file);
    rechercheMots(tab, bankMots, positions1);
    for (int b = 0; b <= 11; b++) {
        for (int a = 0; a <= 12; a++)
            printf("%c", bankMots[a][b]);
    }
    for (int b = 0; b <= 11; b++) {
       for (int a = 0; a <= 12; a++)
            if (isupper(bankMots[a][b])) {
                printf("%c", bankMots[a][b]);
            }
    }
}

int main(int argc, char *argv[]) {
    char tab[150][20];
    positions pos1 = {0};
    lireFichier(argv, tab, pos1);
    /*for (int w = 0; w <= 20; ++w) {
        printf("%s", tab[w]);
    }*/
    return 0;
} 
