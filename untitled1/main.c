#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct data {
    char * line;
    int lenght;
    int isProper;
    int zeroCount;
    int oneCount;
    struct data * next;
};

struct data * openFile(char * source, struct data *list);

struct data * addDataToList(int lenght,struct data *list);

struct data * loadDataFromFile(char *source, struct data *list);

void initList(struct data *list);

int main() {
    struct data *list;
    list = NULL;
    printf("Hello, World!\n");
    list = openFile("PLIK01.txt", list);
    list = loadDataFromFile("PLIK01.txt", list);
    printf("%s", list->next->next->line);
    return 0;
}
struct data * openFile(char * source, struct data *list) {
    FILE* file;
    int lineCount=0;
    char letter;
    int lenght =0;
    char *line ="\n";

    if((file=fopen(source, "r"))!= NULL){
        while(!feof(file)){
            letter = getc(file);
            lenght++;

            if(letter== '\n' || letter == EOF){
                lineCount++;
                printf("%d: %d\n ",lineCount, lenght);
                list = addDataToList(lenght-1, list);
                lenght=0;

            };



        }

    }else{
        printf("Blad otwarcia pliku \n");
    }
    printf("liczba lini: %d\n", lineCount);
    fclose(file);
    return list;
}

struct data * addDataToList(int lenght, struct data *list) {
    struct data *end = list;
    if(end == NULL){
     struct data *tmp = (struct data*)malloc(sizeof(struct data));
     tmp->lenght = lenght;
     tmp->next = list;
     list= tmp;
    } else{
        while(end ->next !=NULL){
            end= end->next;
        };
        struct data *tmp = (struct data*)malloc(sizeof(struct data));
        tmp ->lenght =lenght;
        tmp->next = NULL;
        end->next = tmp;
    }
    return list;
}

void initList(struct data *list) {
    list = NULL;
}

struct data *loadDataFromFile(char *source, struct data *list) {
    FILE* file;
    char letter;
    int lenght =0;
    struct data *tmp = list;
  if(tmp != NULL){
      if((file=fopen(source, "r"))!= NULL){
          tmp->line = malloc(tmp->lenght* sizeof(char));
          while(!feof(file)){

              letter = getc(file);
              tmp->line[lenght] = letter;
              lenght++;
              if(letter== '\n' || letter == EOF){
                  if(tmp->next !=NULL){
                      tmp = tmp->next;
                      tmp->line = malloc(tmp->lenght* sizeof(char));
                  }

                  lenght=0;

              };



          }

          tmp->line = malloc(tmp->lenght* sizeof(char));


        fgets(tmp ->line, tmp ->lenght, file);
        while(tmp ->next!=NULL){
            tmp  = tmp ->next;
            tmp->line = malloc(tmp->lenght* sizeof(char));
            fgets(tmp ->line, tmp->lenght, file);
            printf("%s\n", tmp->line);
        }

      }else{
          printf("Blad otwarcia pliku \n");
      }

      fclose(file);
  }


    return list;
}


