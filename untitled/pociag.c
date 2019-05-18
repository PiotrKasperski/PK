#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct segment {
    int waga;
    struct segment *nast;
    struct pasazer *p_list;
};

struct pasazer {
    int waga;
    struct pasazer *nast;

};


struct segment *generuj_pociag();

void show_pociag(struct segment *glowa);

struct pasazer *generuj_pasazerow(int ile);


int main() {
    srand(time(NULL));
    struct segment *lokomotywa;
    lokomotywa = generuj_pociag();
    show_pociag(lokomotywa);

    getchar();
    return 0;

}

struct pasazer *generuj_pasazerow(int ile) {

    struct pasazer *glowa, *pom;
    glowa = malloc(sizeof(struct pasazer));
    pom = glowa;
    pom->waga = rand() % 200 + 30;
    pom->nast = NULL;
    for (int i = 1; i < ile; i++) {
        pom->nast = malloc(sizeof(struct pasazer));
        pom = pom->nast;
        pom->waga = rand() % 200 + 30;
        pom->nast = NULL;


    };


    return glowa;
};

struct segment *generuj_pociag() {
    int ile = rand() % 20;
    printf("Pociag bedzie mial %d wagonow \n\n\n", ile);
    struct segment *lokomotywa, *pom;

    lokomotywa = malloc(sizeof(struct segment));
    pom = lokomotywa;
    pom->waga = 120;
    pom->p_list = NULL;
    pom->nast = malloc(sizeof(struct segment));
    pom = pom->nast;
    pom->waga = rand() % 40 + 40;
    pom->p_list = NULL;
    pom->nast = NULL;


    for (int i = 0; i < ile; i++) {
        pom->nast = malloc(sizeof(struct segment));
        pom = pom->nast;
        pom->waga = 5 + rand() % 20;
        pom->p_list = generuj_pasazerow(pom->waga * 8);
        pom->nast = NULL;


    };


    return lokomotywa;
};

void show_pociag(struct segment *lokomotywa) {
    int licznik = 0;
    struct segment *pom = NULL;
    if (lokomotywa != NULL) {
        pom = lokomotywa;
        while (pom != NULL) {
            licznik++;
            if (licznik == 1) {
                printf("\n\n\nLokomotywa %d T\n", pom->waga);
                printf("         ____ \n");
                printf("  ][_n_i_| (  \n");
                printf(" (__________|_\n");
                printf("   0--0--0    \n");
            }
            if (licznik == 2) {
                printf("\n\n\nSklad Wegla %d T\n", pom->waga);
                printf(" ooo___  \n");
                printf("|wwwwww|  \n");
                printf("[______]_\n");
                printf(" 0    0 \n");
            }
            if (licznik > 2) {
                printf("\n\n\nPasazerski %d T\n", pom->waga);
                printf("_________________\n");
                printf("|               |\n");
                printf("|               |\n");
                printf("|_______________|_\n");
                printf("   0        0\n");
            }

            pom = pom->nast;
        }
    };


}