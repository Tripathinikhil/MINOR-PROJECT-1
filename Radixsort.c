#include<stdio.h>
#include<time.h>
#define clearbuffer(s, n) memset(s, 0, n);
int bigNum(int arr[], int n) {

    int big = arr[0];
    int i;
    for (i = 1; i < n; i++)
    if (arr[i] > big)
    big = arr[i];
    return big;

}
void countSort(int arr[], int n, int exp) {


    int output[n];
    int i, count[10] = { 0 };
      for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

          for (i = 1; i < 10; i++)

                    count[i] += count[i - 1];

                           for (i = n - 1; i >= 0; i--) {

                                  output[count[(arr[i] / exp) % 10] - 1] = arr[i];

                                             count[(arr[i] / exp) % 10]--;

    }



                                           for (i = 0; i < n; i++)

                                                     arr[i] = output[i];

}

void radixsort(int arr[], int n) {

    int m = bigNum(arr, n);
    int exp;

    for (exp = 1; m / exp > 0; exp *= 10)

        countSort(arr, n, exp);

}


int main()
{
   clock_t start;
    double d;
       FILE *file1 ,*results;
         char characters, allocate[64];
	       int i = 0, integers[200000], j = 0;
              file1 = fopen("file1.txt", "r");

                while(1){
                  characters = fgetc(file1);
                    if(characters == EOF){
                break;
		      }
         if(characters == ','){
              integers[j] = atoi(allocate);
                 j++;
                    clearbuffer(allocate, 64);
                                      i = 0;
                             continue;
                            }
		              else{
                   allocate[i] = characters;
              i++;
           }
	     }
results=fopen("result.txt","w");
           if (results == NULL)
             {
                 puts("error");
                        exit(1);
                           }
                           start=clock();

        radixsort(integers,200000);

                   d=(clock()-start)/(double)CLOCKS_PER_SEC;

                   for ( i = 0; i <= 200000; i++)
                       {


                               printf("%d,",integers[i]);
                                        fprintf(results,"%d,",integers[i]);
                                         }
                                          printf("Time required for sorting  using Radix sort sort is =%f seconds\n",d);
            fclose(file1);
           fclose(results);





}



