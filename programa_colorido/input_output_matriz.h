#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_int_double.h"

#define STRING_LENGTH 256

// funcao alternativa para acessar matrizes atraves do ponteiro do primeiro elemento
double * acs_alt(int n_colunas, int linha, int coluna, double * matriz)
{
    return matriz + linha * n_colunas + coluna;
}

// funcao que escreve uma matriz na tela
void output_matriz(int n_linhas, int n_colunas, double * matriz)
{
    int max[n_colunas];
    int sizes[n_linhas][n_colunas];

    // achar o maior numero de cada coluna e o tamanho de cada numero
    for (int c = 0; c < n_colunas; c++)
    {
        max[c] = 0;
        for (int l = 0; l < n_linhas; l++)
        {
            double valor = *acs_alt(n_colunas, l, c, matriz);

            char numero[STRING_LENGTH];
            sprintf(numero, "%.2lf", valor);
            int len = strlen(numero);

            sizes[l][c] = len;
            if (len > max[c])
            {
                max[c] = len;
            }
        }
    }

    // escrever cada linha e colocar espacos nos locais certos para deixar todos os numeros alinhados
    for (int l = 0; l < n_linhas; l++)
    {
        for (int c = 0; c < n_colunas; c++)
        {
            if (c > 0)
            {
                printf(" ");
            }

            for (int i = 0; i < max[c] - sizes[l][c]; i++)
            {
                printf(" ");
            }

            double valor = *acs_alt(n_colunas, l, c, matriz);
            printf("%.2lf", valor);
        }
        printf("\n");
    }
}

// pedir o tamanho de uma matriz
void input_matriz_size(int * p_n_linhas, int * p_n_colunas)
{
    int n_linhas = input_int("numero de linhas: ");
    while (n_linhas <= 0)
    {
        printf( RED "Aviso!" NORMAL " - numero de linhas deve ser positivo|\n");
        n_linhas = input_int("numero de linhas: ");
    }
    
    int n_colunas = input_int("numero de colunas: ");
    while (n_colunas <= 0)
    {
        printf( RED "Aviso!" NORMAL " - numero de colunas deve ser positivo|\n");
        n_colunas = input_int("numero de colunas: ");
    }

    *p_n_linhas = n_linhas;
    *p_n_colunas = n_colunas;
}

// pedir uma matriz
void input_matriz(int n_linhas, int n_colunas, double * matriz)
{
    for (int l = 0; l < n_linhas; l++)
    {
        for (int c = 0; c < n_colunas; c++)
        {
            char input_string[STRING_LENGTH];
            sprintf(input_string, "elemento %d, %d: ", l + 1, c + 1);

            double valor = input_double(input_string);
            *acs_alt(n_colunas, l, c, matriz) = valor;
        }
    }
}