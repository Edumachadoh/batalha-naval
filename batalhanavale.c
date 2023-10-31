#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// batalha naval
int main()
{
    char mat[6][6], mat2[6][6], mat3[6][6], letra1;
    int win = 0, jog1L, jog1C, random1, erros = 0, bomba = 0, acerto = 0;

    srand(time(NULL));
    for (int l = 0; l < 6; l++)
    {
        for (int c = 0; c < 6; c++)
        {
            mat[l][c] = '.';
        }
    }

    printf("Barcos: \n");
    for (int l2 = 0; l2 < 6; l2++)
    {

        for (int c2 = 0; c2 < 6; c2++)
        {
            random1 = rand() % 2 + 1;
            if (random1 == 2)
            {
                letra1 = 'x';
            }
            else
            {
                letra1 = '.';
            }
            mat2[l2][c2] = letra1;
            if (mat2[l2][c2] == 'x')
            {
                bomba += 1;
            }

            printf("%c ", mat2[l2][c2]);
        }

        printf("\n");
    }
    printf("Resultado inicial: \n");
    for (int l = 0; l < 6; l++)
    {
        for (int c = 0; c < 6; c++)
        {
            mat3[l][c] = '.';
            printf("%c ", mat3[l][c]);
        }
        printf("\n");
        
    }
    
    while (win != 1)
    {

        printf("Jogada: \n");

        printf("Linha: ");
        scanf("%d", &jog1L);

        printf("Coluna: ");
        scanf("%d", &jog1C);

        for (int l = 0; l < 6; l++)
        {
            
            for (int c = 0; c < 6; c++)
            {
                mat[jog1L - 1][jog1C - 1] = 'x';
                printf("%c ", mat[l][c]);
            }
            printf("\n");
        }

        if (mat[jog1L - 1][jog1C - 1] == 'x' && mat2[jog1L - 1][jog1C - 1] == 'x')
        {
            printf("Bomba neles!!!!\n");
            mat3[jog1L - 1][jog1C - 1] = 'O';
            acerto += 1;
        }
        else
        {
            erros += 1;
        }

        if (erros > 5)
        {
            printf("Você perdeu");
            break;
        }

        if (acerto > 8)
        {
            printf("Voce ganhou");
            break;
        }
    system("cls");
        printf("Resultado: \n");

        for (int l = 0; l < 6; l++)
        {
            for (int c = 0; c < 6; c++)
            {

                printf("%c ", mat3[l][c]);
            }
            printf("\n");
        }

        printf("\n---------------------------");
        
        printf("Nova rodada");
        printf("---------------------------\n");
        
    }



    return 0;
}
