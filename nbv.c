#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char buffer[80];
    int tab[5] = {1234, 2345, 3456, 4567, 5678}, n = 0, j = 0, code;
    printf("Veillez saisir votre code : ");
    scanf("%[^\n]", &buffer);
    // printf("text : %s\n",buffer);

   
    while (n < 3)
    {
         bool isCorrect = true;
        size_t length = strlen(buffer);
        for (int i = 0; i < length; i++)
        {
            if (!isdigit(buffer[i]))
            {
                isCorrect = false;
            }
        }

        if (isCorrect)
        {
            code = atoi(buffer);

            

            while (j < 5)
            {
                if (code == tab[j])
                {
                    printf("code correct \n\n\n");
                    return 0;
                }
                j++;
            }
            j = 0;

            if (n == 0)
            {
                printf("code incorrect \n");
                printf("saisir à nouveau le code: ");
                
            }
            else if (n == 1)
            {
                 printf("code incorrect \n");
                printf("Derniére tentative\n");
                 printf("saisir à nouveau le code: ");
                
            }
            else
            {
                printf("code incorrect \n Fin des tentatives \n");
                return 0;
            }
            scanf("%s", &buffer);
        }
        else
        {

            if (n == 0)
            {
                printf("il faut saisir un entier : ");
            }
            else if (n == 1)
            {
                printf("Derniére tentative, saisir un entier :");
            }
            else
            {
                printf("Fin Tentative! ");
                return 0;
            }
            scanf("%s", &buffer);
        }
        n++;
    }

    return 0;
}
