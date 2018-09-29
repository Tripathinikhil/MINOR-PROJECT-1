#include <stdio.h>
#include<time.h>
#define clearbuffer(s, n) memset(s, 0, n);
int main(){
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

        gnomesort(integers,200000);

                   d=(clock()-start)/(double)CLOCKS_PER_SEC;

                   for ( i = 0; i <= 200000; i++)
                       {


                               printf("%d,",integers[i]);
                                        fprintf(results,"%d,",integers[i]);
                                         }
                                          printf("Time required for sorting  using gnome sort is =%f seconds\n",d);
            fclose(file1);
           fclose(results);



}
void gnomesort(int *gnome, int size){
   int i=1, t;

   do{
         if(gnome[i-1] <= gnome[i])
                     {
                         ++i;
                     }
                else{
                        t = gnome[i];
                        gnome[i] = gnome[i-1];
                         gnome[i-1] = t;
                          --i;
                      if(i == 0)
                    {i = 1;}

                  }
                }while(i<size);
}

