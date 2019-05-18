
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


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

int getTrainWeight(struct segment *lokomotywa);

int getPassengersWeight(struct pasazer *pasazer);

void countFatAndSkiny(struct segment *lokomotywa, int *fat, int *skinny);

void deletePassengers(struct pasazer *pasazer);

void deleteTrain(struct segment *lokomotywa);


int main() {
    srand(time(NULL));
    struct segment *lokomotywa;
    lokomotywa = generuj_pociag();
    show_pociag(lokomotywa);
    int trainWeight = getTrainWeight(lokomotywa);
    int fat = 0, skinny = 0;
    int *pFat, *pSkinny;
    pFat = &fat;
    pSkinny = &skinny;

    countFatAndSkiny(lokomotywa, pFat, pSkinny);

    deleteTrain(lokomotywa);

    trainWeight = getTrainWeight(lokomotywa);
    printf("%d", trainWeight);
    //show_pociag(lokomotywa);

    //getchar();
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

int getTrainWeight(struct segment *lokomotywa) {
    if(lokomotywa!=NULL){
        int weight = lokomotywa->waga * 1000;
        weight += lokomotywa->nast->waga * 1000;
        lokomotywa = lokomotywa->nast;
        while (lokomotywa->nast != NULL) {
            weight += lokomotywa->nast->waga * 1000;
            weight += getPassengersWeight(lokomotywa->nast->p_list);
            lokomotywa = lokomotywa->nast;
        }
        printf("Waga calego skladu wynosi %d kg\n", weight);
        return weight;
    } else{
        printf("Pociag nie istnieje");
        return -1;
    }


}

int getPassengersWeight(struct pasazer *pasazer) {
    int weight;
    if (pasazer != NULL) {
        weight = pasazer->waga;
        while (pasazer->nast != NULL) {
            weight += pasazer->nast->waga;
            pasazer = pasazer->nast;
        }
    } else {
        weight = 0;
    }


    return weight;
}

void countFatAndSkiny(struct segment *lokomotywa, int *fat, int *skinny) {
    lokomotywa = lokomotywa->nast;

    while (lokomotywa->nast != NULL) {
        lokomotywa = lokomotywa->nast;
        while (lokomotywa->p_list != NULL) {
            if (lokomotywa->p_list->waga > 120) *fat += 1;
            if (lokomotywa->p_list->waga < 50) *skinny += 1;
            lokomotywa->p_list = lokomotywa->p_list->nast;
        }
    }

    printf("W pociagu jest %d grubasow i %d chuderlakow", *fat, *skinny);
}

void deletePassengers(struct pasazer *pasazer) {
    struct pasazer *tmp;
    while (pasazer != NULL) {
        tmp = pasazer;
        pasazer = pasazer->nast;
        free(tmp);

    }
}

void deleteTrain(struct segment *lokomotywa) {
    struct segment *tmp;
    while (lokomotywa != NULL) {
        tmp = lokomotywa;
        lokomotywa = lokomotywa->nast;
        if (tmp->p_list != NULL) deletePassengers(tmp->p_list);
        free(tmp);
    }

}
