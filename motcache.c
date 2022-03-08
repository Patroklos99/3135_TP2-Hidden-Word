#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

enum dir {
    N, E, S, O
};

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

void obtenirMots(char tab[150][45], FILE *file, const int *compt) {
    int i = *compt;
    i = i - 13;
    (fgets(tab[i], 14, file));
}

void modifier(char bank[13][13], int x, int y) {
    //printf("Positon trouve a (%d:%d)\n", x, y);
    bank[y][x] = (char) tolower(bank[y][x]);
}

bool trouverMot(char tab[150][45], char bankMots[13][13], int x, int y, int longueurMatch, int motNumero, enum dir dir) {
    int longueurMot = (int) strlen(tab[motNumero]) - 1;
    if (longueurMot == longueurMatch)
        return true;
    if (x < 0 || y < 0 || x >= 13 || y >= 13)
        return false;
    if ((bankMots[y][x] | 0x20) == (tab[motNumero][longueurMatch] | 0x20)) {
        bool answer;
        switch (dir) {
            case N:
                answer = trouverMot(tab, bankMots, x + 1, y,
                                    (longueurMatch + 1), motNumero,N);
                break;
            case S:
                answer = trouverMot(tab, bankMots, x - 1, y,
                                    (longueurMatch + 1), motNumero,S);
                break;
            case E:
                answer = trouverMot(tab, bankMots, x, y - 1,
                                    (longueurMatch + 1), motNumero,E);
                break;
            case O:
                answer = trouverMot(tab, bankMots, x, y + 1,
                                    (longueurMatch + 1), motNumero,O);
                break;
        }
        if (answer) {
            modifier(bankMots, x, y);
        }
        return answer;
    } else
        return false;
}

void trouverPremierLettre(char tab[150][45], char bankMots[13][13]) {
    int w = 0;
    int longueurMatch = 0;
    for (int nligne = 0; nligne <= 11; nligne++) {
        for (int ncol = 0; ncol <= 12; ncol++) {
            if ((tab[w][0] | 0x20) == (bankMots[ncol][nligne] | 0x20)) {
                printf("recherche du mot: %s", tab[w]);
                if (trouverMot(tab, bankMots, nligne, ncol, longueurMatch, w, O)
                    || trouverMot(tab, bankMots, nligne, ncol, longueurMatch, w, N)
                    || trouverMot(tab, bankMots, nligne, ncol, longueurMatch, w, S)
                    || (trouverMot(tab, bankMots, nligne, ncol, longueurMatch, w, E))) {
                    w++;
                    ncol = 0;
                    nligne = -1;
                }
            }
        }
    }
}

void rechercheMots(char tab[150][45], char bankMots[13][13]) {
    trouverPremierLettre(tab, bankMots);
}

void lireFichier(char **argv, char tab[150][45]) {
    FILE *file = fopen(argv[1], "r");
    int compteur = 0;
    char bankMots[13][13];

    while (file && compteur <= 45) {
        compteur <= 12 ? creerTabMots(bankMots, file, (int *) &compteur) : obtenirMots(tab, file, (int *) &compteur);
        compteur++;
    }
    fclose(file);
    rechercheMots(tab, bankMots);
    printf("\n");
    for (int b = 0; b <= 11; b++) {
        for (int a = 0; a <= 12; a++)
            if (isupper(bankMots[a][b])) {
                printf("%c", bankMots[a][b]);
            }
    }

}

int main(int argc, char *argv[]) {
    clock_t begin = clock();
    char tab[150][45];
    lireFichier(argv, tab);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed: %f seconds", time_spent);
    return 0;
}

