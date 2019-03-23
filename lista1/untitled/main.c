#include <stdio.h>
int getInteger() {
    int integer;
    printf("Prosze podac liczbe\n");
    scanf("%d", &integer);
    return integer;
}

void printInteger(int integer){
    printf("Podales liczbe: %d %o %x \n", integer, integer, integer);
}

int getBirthYear() {
    int year;
    printf("W ktorym roku sie urodziles?\n");
    scanf("%d", &year);
    return year;
}

void printAge(int year){
    printf("Masz %d %s", 2019-year, "lat!");
}

int main() {
    //printInteger(getInteger());
    printAge(getBirthYear());
    return 0;
}

