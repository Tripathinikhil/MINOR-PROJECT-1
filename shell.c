#include <stdio.h>
#include <time.h>
#define setvalue(s, n) memset(s, 0, n);
void shellsort(int sort[], int size)
{  int i , gap,j,t;
    gap=size/2;
          loop:
            j=gap;
            while(j<size)
            {
                for(i=j-gap;i>=0;i=i-gap){
                           if(sort[i]>sort[i+gap])
                              {
                                 t=sort[i];
                                 sort[i]=sort[i+gap];
                                 sort[i+gap]=t;
                             }
                              else
                                 break;

                            }

                            j++;
                          }
                 gap=gap/2;
        if(gap>0)
           {
               goto loop;
           }
    }



int main(){
    clock_t start;
    double d;
       FILE *minor2 ,*result2;
;
         char characters, allocate[64];
	       int i = 0, integers[200000], j = 0;
              minor2 = fopen("file1.txt", "r");

                while(1){
                  characters = fgetc(minor2);
                    if(characters == EOF){
                break;
		      }
        else if(characters == ','){
              integers[j] = atoi(allocate);
                 j++;
                    setvalue(allocate, 64);
                                      i = 0;
                             continue;
                            }
		              else{
                   allocate[i] = characters;
              i++;
           }
	     }
	     result2=fopen("result2.txt","w");
           if (result2 == NULL)
             {
                 puts("error");
                        exit(1);
                           }
                            start=clock();

                   shellsort(integers, 200000);

                                         d=(clock()-start)/(double)CLOCKS_PER_SEC;


                      for ( i = 0; i <= 200000; i++)
                       {       printf("%d,",integers[i]);
                               fprintf(result2,"%d,",integers[i]);
                                         }
                                          printf("\nTime required for integers using shell sort sort is =%f seconds\n",d);
                          fclose(minor2);
                         fclose(result2);
              }
