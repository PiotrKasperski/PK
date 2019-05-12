#include <stdio.h>
#include <stdlib.h>
struct readedData{
int number;
struct readedData* nextData;
struct readedData* next;
};

void addToList(int i, struct readedData* tmp){
    struct readedData* end = tmp;
 while(end->nextData !=NULL) end = end->nextData;
 struct readedData *temp=(struct readedData*)malloc(sizeof(struct readedData));
 temp->number =i;
 temp->nextData = NULL;
 end->nextData = temp;
}
int readFromFile(char* filename)
{
    FILE *inputFile;
    int *readedNumber;

    struct readedData *P1, *P2, *P3;
    P1 = (struct readedData*)malloc(sizeof(struct readedData));
    P2 =(struct readedData*)malloc(sizeof(struct readedData));
    P3 = (struct readedData*)malloc(sizeof(struct readedData));

    P1->next = P2;
    P2->next =P3;
    P3->next = P1;

    readedData = (int*)malloc(sizeof(int));

    if ((inputFile = fopen(filename, "rb"))== NULL)
    {
        printf("Blad otwarcia pliku");
    }
    else
    {
        while(!feof(inputFile))
        {
            fread(readedData, sizeof(int), 1, inputFile);
            printf("%d\n", readedData[0]);
        }
        fclose(inputFile);
    }
    return 2;
}

int main()
{
    readFromFile("Z3.bin");

    return 0;
}
