#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a;
    int tab[4] = {4, 3, 2}; // tableau des coefficients, tab[3], non initialisé,  va contenir la somme des coefficiens
    float *sommeNotes = (float *)calloc(1, sizeof(float));
    float *sommeMoyennePartielCoef = (float *)calloc(1, sizeof(float));
    float moyenne;
    char nom[20];
    float **p;
    // initialisation des 3 lignes du tableau de pointeur p
    p = (float **)malloc(3 * sizeof(float *));
    // initialisation des 2 colones du tableau de pointeur p
    for (int i = 0; i < 3; i++)
    {
        p[i] = (float *)calloc(2, sizeof(float));
    }

    printf("Veuiller entrer votre nom :\t");
    scanf("%s", &nom);
    printf("\n\n");
    printf("Donnez votre première note en informatique :\t");
    if (scanf("%f", &p[0][0]) != 1 || p[0][0] < 0 || p[0][0] > 20)
    {
        printf("LA note est un nombre compris entre 0 et 20 \n");
        printf(" Enter la note à nouveau :\t");
        scanf("%f", &p[0][0]);
    }
    printf("Donnez votre seconde note en informatique :\t");
    if (scanf("%f", &p[0][1]) != 1 || p[0][1] < 0 || p[0][1] > 20)
    {
        printf("LA note est un nombre compris entre 0 et 20 \n");
        printf(" Enter la note à nouveau :\t");
        scanf("%f", &p[0][1]);
    }
    printf("\n\n");

    printf("Donnez votre première note en francais :\t");
    if (scanf("%f", &p[1][0]) != 1 || p[1][0] < 0 || p[1][0] > 20)
    {
        printf("LA note est un nombre compris entre 0 et 20 \n");
        printf(" Enter la note à nouveau :\t");
        scanf("%f", &p[1][0]);
    }
    printf("Donnez votre seconde note en francais : \t");
    if (scanf("%f", &p[1][1]) != 1 || p[1][1] < 0 || p[1][1] > 20)
    {
        printf("LA note est un nombre compris entre 0 et 20 \n");
        printf(" Enter la note à nouveau :\t");
        scanf("%f", &p[1][1]);
    }
    printf("\n\n");

    printf("Donnez votre première note en gèographie :\t");
    if (scanf("%f", &p[2][0]) != 1 || p[2][0] < 0 || p[2][0] > 20)
    {
        printf("LA note est un nombre compris entre 0 et 20 \n");
        printf(" Enter la note à nouveau :\t");
        scanf("%f", &p[2][0]);
    }
    printf("Donnez votre seconde note en gèographie :\t");
    if (scanf("%f", &p[2][1]) != 1 || p[2][1] < 0 || p[2][1] > 20)
    {
        printf("LA note est un nombre compris entre 0 et 20 \n");
        printf(" Enter la note à nouveau :\t");
        scanf("%f", &p[2][1]);
    }
    printf("\n\n");
    // calcule de la somme des coefficients
    for (int i = 0; i < 3; i++)
    {
        tab[3] += tab[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            *sommeNotes += p[i][j];
            if (j == 1)
            {
                // calcule de la somme des moyennes de chaque matière multipliée par leur coefficient :
                *sommeMoyennePartielCoef += (*sommeNotes / 2) * tab[i];
            }
        }
    }

    // calcule moyenne générale
    moyenne = *sommeMoyennePartielCoef / tab[3];

    // vérification du niveau
    if (moyenne >= 0 && moyenne <= 10)
    {
        printf("%s votre moyenne est : %.2f\n", nom, moyenne);
        printf("Désolé mais votre niveau est médiocre \n\n\n");
    }
    else if (moyenne > 10 && moyenne <= 12)
    {
        printf("%s votre moyenne est :%.2f\n ", nom, moyenne);
        printf("votre niveau est passable \n\n\n");
    }
    else if (moyenne > 12 && moyenne <= 14)
    {
        printf("%s votre moyenne est : %.2f\n", nom, moyenne);
        printf("Félicitation niveau est Trés bien \n\n\n");
    }
    else if (moyenne > 14 && moyenne <= 20)
    {
        printf("%s votre moyenne est : %.2f \n", nom, moyenne);
        printf("Félicitation niveau estExcellent \n\n\n");
    }

    for (int i = 0; i < 3; i++) // libération des espace alloués au tableau
    {
        free(p[i]);
    }
    free(sommeNotes);
    free(sommeMoyennePartielCoef);

    return 0;
}
