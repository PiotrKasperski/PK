#include <stdio.h>
#include <math.h>

struct func {
    int a;
    int b;
    int c;
};

double delta(struct func squareFunction) {
    return (squareFunction.b * squareFunction.b) - (4 * squareFunction.a * squareFunction.c);
}

struct func loadFunction() {
    struct func squareFunction;
    printf("podaj a\n");
    scanf("%d", &squareFunction.a);
    printf("podaj b\n");
    scanf("%d", &squareFunction.b);
    printf("podaj c\n");
    scanf("%d", &squareFunction.c);
    return squareFunction;
}


void calculateSquareFunction() {
    struct func sqare = loadFunction();
    if (sqare.a == 0) printf("Funkcja nie jest kwadratowa");
    if (delta(sqare) > 0) {
        printf("miejsca zerowe funkci to: %f %f \n", (((0 - sqare.b) - sqrt(delta(sqare)))) / (2 * sqare.a),
               (((0 - sqare.b) + sqrt(delta(sqare)))) / (2 * sqare.a));
    };
    if (delta(sqare) == 0) {
        double x1;
        x1 = -sqare.b / (2 * sqare.a);
        printf("Funkcja ma jedno miejsce zerowe X1=%f\n", x1);
    };
    if (delta(sqare) < 0) {
        printf("Funkcja nie ma pierwiastkow rzeczywistych\n");

    };
}

void ClrScr() {
    printf("\033[2J\033[H");
}

int menu() {
    ClrScr();
    int i;
    printf("1-oblicz funkcje kwadratowa\n0-wyjdz\n");
    scanf("%d", &i);
    switch (i) {
        case 1 : {
            calculateSquareFunction();
            return 1;
        };
        case 0: {
            return 0;
        }
        default: {
            printf("Bledny wybor");
            return 1;
        }
    }

}

void loop() {
    while (menu() == 1) {

    }
}

int main() {

    loop();
    return 0;
}


//2,2,-12