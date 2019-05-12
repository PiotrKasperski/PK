#include <stdio.h>
#include <stdlib.h>

int readFromFile(char* filename){
FILE *inputFile;
int *readedData;
readedData = (int*)malloc(sizeof(int));

if ((inputFile = fopen(filename, "rb"))== NULL){
    printf("Blad otwarcia pliku");
} else {
 while(!feof(inputFile)){
    fread(readedData, sizeof(int), 1, inputFile);
    printf("%d\n", readedData[0]);
 }
 fclose(inputFile);
}
return 2;
}

int main()
{
    readFromFile("Z2.bin");
    
    return 0;
}
