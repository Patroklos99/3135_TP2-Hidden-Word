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

void obtenirMots(mots mot1, char tab[150][20], FILE *file, const int *compt) {
    int i = *compt;
    i = i - 13;
    (fgets(tab[i], 13, file));
}

void lireFichier(char **argv, mots mot1, char tab[150][20]) {
    FILE *file = fopen(argv[1], "r");
    int compteur = 0;

    while (file && compteur <= 33) {
        //line[i][strlen(line[i]) - 1] = '\0';
        compteur <= 12 ? (fgets(tab[compteur], sizeof(*tab), file)) : obtenirMots(mot1, tab, file, (int *) &compteur);
        compteur++;
    }
    fclose(file);
};

int main(int argc, char *argv[]) {
    char tab[150][20];
    mots mot1 = {{0}, 2, 0};
    lireFichier(argv, mot1, tab);
    for (int w = 0; w < 20; ++w) {
        printf(" %s", tab[w]);
    }

    return 0;
}

