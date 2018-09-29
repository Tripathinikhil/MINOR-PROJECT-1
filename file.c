#include <stdio.h>
int main()
{
      int  number[200000];
          FILE *minor;
                int  i=0,num;
                     int  k=10;
                        int p=1;
    minor = fopen("file1.txt", "w");


                               if (minor == NULL)
                               {
                                    puts("error");
                                             exit(1);
                                                         }

                for(p=1;p<=200000;p++)
                                {
                               k = rand()+10;
                                      number[i] = k;
                                         fprintf(minor,"%d,", number[i]);
                                               printf("%d,", number[i]);
                                                            i=i+1;
                                               }


                      fclose(minor);
                 return 0;
}

