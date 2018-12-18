#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define clearbuffer(s, n) memset(s, 0, n);
const int n=262144;
int data[262144];
int asc = 1;
int dsc = 0;
double tim;


int main()
{
    clock_t start;
    int i;
    printf("\nEnter the data");
    fileRead();
    start=clock();
    sort();
    tim=(clock()-start)/(double)CLOCKS_PER_SEC;
    fileInput();
    for (i = 0;i < n;i++)
    {
        printf("%d ", data[i]);
    }
}

void fileRead()
{
    int j=0,i=0;
    FILE *file1;
    file1 = fopen("file.txt", "r");
    char characters, allocate[64];
    while(1)
    {
        characters = fgetc(file1);
        if(characters == EOF)
        {
            break;
        }
        if(characters == ',')
        {
            data[j] = atoi(allocate);
            j++;
            clearbuffer(allocate, 64);
            i = 0;
            continue;
        }
        else
        {
            allocate[i] = characters;
            i++;
        }
    }
    fclose(file1);
}


void fileInput()
{
    int i=0,j=0;
    FILE *results;
    results=fopen("result.txt","w");
    if (results == NULL)
    {
        puts("error");
        exit(1);
    }
    for ( i = 0; i <= n; i++)
    {
         printf("%d,",data[i]);
         fprintf(results,"%d,",data[i]);
    }
    printf("tim required for sorting  using gnome sort is =%f seconds\n",tim);
    fclose(results);
}


void compare(int i, int j, int order)
{
    int temp;
    if (order == (data[i] > data[j]))
    {
        temp = data[i];
        data[i] =data[j];
        data[j]=temp;
    }
}

void bitonicSubDivide(int start, int gap, int order)
{
    int k, i;
    if (gap > 1)
    {
        k = gap / 2;
        for (i = start;i < start+k ;i++)
            compare(i, i+k, order);
        bitonicSubDivide(start, k, order);
        bitonicSubDivide(start+k, k, order);
    }
}

void divideBitonic(int start, int gap, int order)
{
    int k;
    if (gap >0)
    {
        k = gap / 2;
        divideBitonic(start, k, asc);
        divideBitonic(start + k, k, dsc);
        bitonicSubDivide(start, gap, order);
    }
}


void sort()
{
    divideBitonic(0,n,asc);
}
