#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define clearbuffer(s, n) memset(s, 0, n);
const int n=262144;
const int RUN = 262144;
int arr[262144];
double tim;
int main()
{
    int i=0;
    clock_t start;
    fileRead();
    start=clock();
    timSort();
    tim=(clock()-start)/(double)CLOCKS_PER_SEC;
    fileInput();
    for (i = 0;i < n;i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
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
            arr[j] = atoi(allocate);
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
         printf("%d,",arr[i]);
         fprintf(results,"%d,",arr[i]);
    }
    printf("tim required for sorting  using gnome sort is =%f seconds\n",tim);
    fclose(results);
}

void insertionSort( int left, int right)
{
    int i;
    for ( i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


void merge( int l, int m, int r)
{
    int p;
    int o;
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (p = 0; p < len1; p++)
        left[p] = arr[l + p];
    for (o  = 0; o < len2; l++)
        right[o] = arr[m + 1 + o];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}


void timSort()
{
    int i;
    for (i = 0; i < n; i+=RUN)
      insertionSort( i, min((i+RUN-1), (n-1)));
    int size;
    for ( size = RUN; size < n; size = 2*size)
    {
        int left;
        for (left = 0; left < n; left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));
            merge( left, mid, right);
        }
    }
}

int min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;

}


