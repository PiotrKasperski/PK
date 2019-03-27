#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void printTable(int table[], int lenght){
    for(int i =0 ; i < lenght; i++){
        printf("%d\n", table[i]);
    }
}
//zadanie1
void randomizeTable(int table[], int lenght){
    //ustawienie randa


    //losowe wypelnienie tablicy
    for(int i =0 ; i < lenght; i++){
        table[i]=rand()%10;
    }

}

void zadanie1(){
    printf("Zadanie 1\n");
    int table0[10];
    randomizeTable(table0, 10);
    printf("randomowa  tablica: \n");
    printTable(table0,10);
}

//zadanie 2
void rewriteTabletoTable(int table0[], int table1[], int tablesLenght){
    for(int i=0 ;i < tablesLenght;i++){
        table1[i] = table0[tablesLenght - i - 1];
    }
}

void zadanie2(){
    printf("Zadanie 2\n");
    int table0[10], table1[10];
    randomizeTable(table0, 10);
    rewriteTabletoTable(table0, table1, 10);
    printf("pierwsza tablica: \n");
    printTable(table0,10);
    printf("druga tablica: \n");
    printTable(table1,10);
}


//zadanie 4
struct find{
    int firstIndex;
    int count;
};
struct find findInTable(int table[], int query, int lenght){
    struct  find tmp ={-1,0 };
    for(int i=lenght-1 ;i >=0;i--){
     if(table[i] == query ) {
         tmp.firstIndex =i;
         tmp.count++;
     }
    }
    return tmp;
}
void zadanie4(){
    printf("zadanie4\n");
    int table[10];
    randomizeTable(table,10);
    struct find tmp= findInTable(table, 5, 10);
    printf("W tablicy: \n");
    printTable(table,10);
    printf("5 wystepuje %d razy pierwszy raz na pozycji %d\n", tmp.count, tmp.firstIndex);
}

//zadanie5
int *tableAdd(int table0[],int table1[], int lenght){
    int *tmpTable;
    tmpTable = malloc(lenght*sizeof(int));
    for(int i=0 ;i < lenght;i++){
        tmpTable[i] = table1[i] + table0[i];
    }
    return tmpTable;

}

void zadanie5(){
    printf("Zadanie 5\n");
    int table0[10], table1[10];
    randomizeTable(table0, 10);
    randomizeTable(table1,10);
    printf("pierwsza tablica: \n");
    printTable(table0,10);
    printf("druga tablica: \n");
    printTable(table1,10);
    printf("suma tych tablic: \n");
    int *tab = tableAdd(table0,table1,10);
    printTable(tab,10);
    free(tab);
}

//zadanie 9
int countLenght(char text[]){
    int i=0 ;
    while (text[i] != '\0'){
        i++;

    }
    return i-1;
}
void zadanie9(){
    printf("Zadanie 9 \n");
    char text[256];
    printf("Podaj napis\n");
    fgets(text,256,stdin);
    printf("dlugosc lancucha to: %d\n",countLenght(text));


}

//zadanie11
char *concat(char text1[], char text2[]){
    char *tmp;
    tmp =malloc((countLenght(text1)+countLenght(text2)+1)* sizeof(char));
    int i=0;
    while (text1[i] != '\0'){
        tmp[i] = text1[i];
        i++;
    }
    while (text2[i-countLenght(text1)-1] != '\0'){

        tmp[i] = text2[i-countLenght(text1)-1];
        i++;
    }
    return tmp;
}
void zadanie11(){
    printf("zadanie 11\n");
    puts(concat("123","456"));
}

//zadanie 17
void write(char word[]){
    puts(word);
};
void writeReverse(char word[]){

    puts(word);
    };
void writeMod2(char word[]){
    puts(word);
   };
void zadanie17(int argc,char** argv){
    printf("zadanie 17");
    if (argc ==0 ) return;
    enum options { WRITE =1 , WRITE_REVERSE , WRITE_MOD_2 };
    char *o = argv[1];
    enum options arg = atoi(o);

    switch(arg){
        case WRITE:
            write(argv[2]);
            break;
        case WRITE_REVERSE:
            writeReverse(argv[2]);
            break;
        case WRITE_MOD_2:
            writeMod2(argv[2]);
            break;
        default: printf("nieznana opcja");
    }

}

int main(int argc,char** argv) {
    srand(time(NULL));
    zadanie1();
    zadanie2();
    zadanie4();
    zadanie5();
    zadanie9();
    zadanie11();
    zadanie17(argc, argv);


    return 0;
}