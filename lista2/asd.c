#include <stdio.h>
#include <stdlib.h>

struct idNumber
{
    int number;
    struct idNumber* next;
};
/*
void dodaj_na_poczatek(int i)
{
 struct dana *temp=(struct dana*)malloc(sizeof(struct dana));
 temp->i = i;
 temp->nast = poczatek;
 poczatek = temp;
}

*/

void writeToList(struct idNumber *numberList)
{
    FILE *inputFile;
    int *elementCount, *numbers;
    int i;

    elementCount = (int*)malloc(sizeof(int));



    if ((inputFile = fopen("NrDO.bin", "rb"))== NULL)
    {
        printf("blad otwierania pliku\n");
    }
    else
    {
        fread(elementCount, sizeof(int), 1, inputFile);
        numbers = malloc(elementCount[0]*sizeof(int));
        fread(numbers, sizeof(int), elementCount[0], inputFile);
        printf("%d", elementCount[0]);

        for (i=0; i < elementCount[0]; i++){
             printf("%d: %d\n",i , numbers[i]);
        struct idNumber
        }

    }

}

int main()
{

    struct idNumber *numberList;
    numberList = NULL;
    writeToList(numberList);


    return 0;

}
