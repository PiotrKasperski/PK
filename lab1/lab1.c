#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
int x;
int y;
};

struct figure {
struct point a;
struct point b;
struct point c;
struct point d;
};

struct figure loadFigure() {
    struct figure tmpFigure;

    printf("podaj wspolrzedne punktu a\n");
    scanf("%d", &tmpFigure.a.x);
    scanf("%d", &tmpFigure.a.y);

    printf("podaj wspolrzedne punktu b\n");
    scanf("%d", &tmpFigure.b.x);
    scanf("%d", &tmpFigure.b.y);

    printf("podaj wspolrzedne punktu c\n");
    scanf("%d", &tmpFigure.c.x);
    scanf("%d", &tmpFigure.c.y);

    printf("podaj wspolrzedne punktu d\n");
    scanf("%d", &tmpFigure.d.x);
    scanf("%d", &tmpFigure.d.y);
   return tmpFigure;
};

double lenght(struct point a, struct point b){

    return sqrt(((a.x - b.x)*(a.x - b.x))+((a.y - b.y)*(a.y - b.y)));
}
int isSideEqual(struct figure tmp){
   if((lenght(tmp.a, tmp.b) == lenght(tmp.b, tmp.c)) &&
       (lenght(tmp.c, tmp.d) == lenght(tmp.d, tmp.a) )&&
        (lenght(tmp.b, tmp.c) == lenght(tmp.c, tmp.d) )&&
        (lenght(tmp.a, tmp.d) == lenght(tmp.a, tmp.b) )
        )return 1; else return 0;

}
int isDiagonalEqual(struct figure tmp){
    if((lenght(tmp.a, tmp.c) == lenght(tmp.b, tmp.d) ) )return 1; else return 0;
}
double squareField(struct figure square){
    return (lenght(square.a, square.b) * lenght(square.a, square.b));
}
double diamondField(struct figure diamond){
  return ((lenght(diamond.a, diamond.c)*lenght(diamond.b, diamond.d))/2);
}

void checkFigure(){
    struct figure tmpFigure = loadFigure();
    if(isSideEqual(tmpFigure) == 1){
            printf("Boki figury sa rowne.\n");
        if(isDiagonalEqual(tmpFigure)){
            printf("Przekatne figury sa rowne. \n Jest to kwadrat o polu rownym %f \n", squareField(tmpFigure));
        } else {
          printf("Przekatne figury sa rozne. \n Jest to romb o polu rownym %f\n" , diamondField(tmpFigure));
        }
    } else printf("Boki figury nie sa rowne \n");

}

int menu() {
    int i;
    printf("1-sprawdz figure\n0-wyjdz\n");
    scanf("%d", &i);
    switch (i) {
        case 1 : {
           checkFigure();
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
int main()
{
   loop();
    return 0;
}
