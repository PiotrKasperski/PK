#include <stdio.h>
#include <stdlib.h>



int silnia(int n)
{
    if (n ==1) return 1;
    else
    {
        return n*(silnia(n-1));
    }

}
void zadanie1()
{
    unsigned int x;
    printf("Podaj N silni: \n");
    scanf("%o", &x);


    printf("%d", silnia(x));
}
double **zadanie2(int n)
{

    int i,j;


    double **tab2;
    tab2=(double**)malloc(n*sizeof(double *));
    for( i=0; i<n; i++)
    {
        tab2[i]=(double*)malloc(n*sizeof(double));
        for (  j = 0; j < n; ++j)
            tab2[i][j]=(i+j)/10.0;
    }

    for ( i = 0; i < n; ++i, printf("\n") )
        for ( j = 0; j < n; ++j)
          tab2[i][j] = (i+1)*(j+1);



     return tab2;

}

void makeSpaces(int height)
{
    int i=0;
    for(i=0; i < height; i++)
    {
        printf(" ");
    }


}
void makeStart(int count)
{
    int i=0;
    for (i=0; i < count; i++)
    {
        printf("*");
    }


}
void zadanie4(int height)
{
    makeSpaces(height);
    makeStart(1);
    printf("\n");
    int i=0;
    for (i=1; i < height; i++)
    {
        makeSpaces(height-i);
        makeStart((i*2)+1);
        printf("\n");
    }
    makeSpaces(height);
    makeStart(1);
    printf("\n");

}
void zadanie5(char napis[])
{
    napis[0]='\0';
}
int main()
{

    zadanie2(10);
    return 0;
}
