#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "entrada_saida_matrizes.h"

#define ENOUGH 256
#define ANSI_COLOR_RESET  "\x1b[0m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE   "\x1b[34m"

void clean_console()
{
    printf("\e[1;1H\e[2J");
}

int pedir_op()
{
    while (1)
    {
        // pedir input do usuário
        char resposta[ENOUGH];
        printf(
            "CALCULADORA DE MATRIZES\n"
            "operacoes possiveis:\n"
            "1 - adicao\n"
            "2 - subtracao\n"
            "3 - produto escalar\n"
            "4 - produto entre matrizes\n"
            "5 - calculo de determinante\n"
            "6 - inversa\n"
            "7 - transposta\n"
            "8 - sair\n"
        );
        int n = pedir_int("operacao desejada: ");

        if (n > 0 && n <= 8)
        {
            return n;
        }
        else
        {
            clean_console();
            printf(
                ANSI_COLOR_RED "Aviso!\n" ANSI_COLOR_RESET
                "input " ANSI_COLOR_YELLOW "[%d]" ANSI_COLOR_RESET " eh invalido\n"
                "as opcoes de entrada possiveis sao:\n"
                ANSI_COLOR_BLUE "1, 2, 3, 4, 5, 6, 7, 8\n\n" ANSI_COLOR_RESET,
                n
            );
        }
    }
}

void adicao()
{
    int n_linhas, n_colunas;
    double * p_matriz_resultado;

    while (1)
    {
        printf(ANSI_COLOR_RED "A" ANSI_COLOR_RESET " + " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET "\n");

        printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
        int tamanho1[2];
        pedir_tamanho(tamanho1);
        int n_linhas1 = tamanho1[0];
        int n_colunas1 = tamanho1[1];

        printf("\ndimensoes da matriz " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET ":\n");
        int tamanho2[2];
        pedir_tamanho(tamanho2);
        int n_linhas2 = tamanho2[0];
        int n_colunas2 = tamanho2[1];

        if (n_linhas1 != n_linhas2 || n_colunas1 != n_colunas2)
        {
            printf( ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET " - para somar duas matrizes, estas precisam ter o mesmo tamanho!\n");
        }
        else
        {
            n_linhas = n_linhas1;
            n_colunas = n_colunas1;
            p_matriz_resultado = (double *)malloc(n_linhas * n_colunas * sizeof(double));

            printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
            double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
            pedir_matriz(n_linhas1, n_colunas1, matriz_a);

            printf("\nelementos da matriz " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET ":\n");
            double * matriz_b = (double *)malloc(n_linhas2 * n_colunas2 * sizeof(double));
            pedir_matriz(n_linhas2, n_colunas2, matriz_b);

            somar_matrizes(n_linhas, n_colunas, matriz_a, matriz_b, p_matriz_resultado);
            free(matriz_a);
            free(matriz_b);
            break;
        }
        printf("\n\n");
    }

    printf("\n\nresultado:\n\n");
    escrever_matriz(n_linhas, n_colunas, p_matriz_resultado);
    free(p_matriz_resultado);
    esperar();
}

void subtracao()
{
    int n_linhas, n_colunas;
    double * p_matriz_resultado;

    while (1)
    {
        printf(ANSI_COLOR_RED "A" ANSI_COLOR_RESET " - " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET "\n");

        printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
        int tamanho1[2];
        pedir_tamanho(tamanho1);
        int n_linhas1 = tamanho1[0];
        int n_colunas1 = tamanho1[1];

        printf("\ndimensoes da matriz " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET ":\n");
        int tamanho2[2];
        pedir_tamanho(tamanho2);
        int n_linhas2 = tamanho2[0];
        int n_colunas2 = tamanho2[1];

        if (n_linhas1 != n_linhas2 || n_colunas1 != n_colunas2)
        {
            printf( ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET " - para subtrair duas matrizes, estas precisam ter o mesmo tamanho!\n");
        }
        else
        {
            n_linhas = n_linhas1;
            n_colunas = n_colunas1;
            p_matriz_resultado = (double *)malloc(n_linhas * n_colunas * sizeof(double));

            printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
            double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
            pedir_matriz(n_linhas1, n_colunas1, &matriz_a[0]);

            printf("\nelementos da matriz " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET ":\n");
            double * matriz_b = (double *)malloc(n_linhas2 * n_colunas2 * sizeof(double));
            pedir_matriz(n_linhas2, n_colunas2, &matriz_b[0]);

            subtracao_matrizes(n_linhas, n_colunas, matriz_a, matriz_b, p_matriz_resultado);
            free(matriz_a);
            free(matriz_b);
            break;
        }
        printf("\n\n");
    }
    
    printf("\n\nresultado:\n\n");
    escrever_matriz(n_linhas, n_colunas, p_matriz_resultado);
    free(p_matriz_resultado);
    esperar();
}

void produto_escalar()
{
    int n_linhas, n_colunas;
    double * p_matriz_resultado;

    printf(ANSI_COLOR_YELLOW "n" ANSI_COLOR_RESET " * "ANSI_COLOR_RED "A" ANSI_COLOR_RESET "\n");

    printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
    int tamanho1[2];
    pedir_tamanho(tamanho1);
    int n_linhas1 = tamanho1[0]; 
    int n_colunas1 = tamanho1[1];

    n_linhas = n_linhas1;
    n_colunas = n_colunas1;
    p_matriz_resultado = (double *)malloc(n_linhas * n_colunas * sizeof(double));

    printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
    double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
    pedir_matriz(n_linhas1, n_colunas1, &matriz_a[0]);
    
    double escalar = pedir_double("\nvalor escalar " ANSI_COLOR_YELLOW "n" ANSI_COLOR_RESET ": ");

    produto_escalar_matriz(n_linhas1, n_colunas1, matriz_a, escalar, p_matriz_resultado);
    free(matriz_a);
    
    printf("\n\nresultado:\n\n");
    escrever_matriz(n_linhas, n_colunas, p_matriz_resultado);
    free(p_matriz_resultado);
    esperar();
}

void produto_entre_matrizes()
{
    int n_linhas, n_colunas;
    double * p_matriz_resultado;

    while (1)
    {
        printf(ANSI_COLOR_RED "A" ANSI_COLOR_RESET " x " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET "\n");

        printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
        int tamanho1[2];
        pedir_tamanho(tamanho1);
        int n_linhas1 = tamanho1[0]; 
        int n_colunas1 = tamanho1[1];

        printf("\ndimensoes da matriz " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET ":\n");
        int tamanho2[2];
        pedir_tamanho(tamanho2);
        int n_linhas2 = tamanho2[0];
        int n_colunas2 = tamanho2[1];

        if (n_colunas1 != n_linhas2)
        {
            printf( ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET " - para multiplcar duas matrizes, o numero de colunas da primeira tem que ser igual ao numero de linhas da segunda!\n");
        }
        else
        {
            n_linhas = n_linhas1;
            n_colunas = n_colunas2;
            p_matriz_resultado = (double *)malloc(n_linhas * n_colunas * sizeof(double));

            printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
            double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
            pedir_matriz(n_linhas1, n_colunas1, &matriz_a[0]);

            printf("\nelementos da matriz " ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET ":\n");
            double * matriz_b = (double *)malloc(n_linhas2 * n_colunas2 * sizeof(double));
            pedir_matriz(n_linhas2, n_colunas2, &matriz_b[0]);

            produto_matrizes(n_linhas, n_colunas, n_colunas1, matriz_a, matriz_b, p_matriz_resultado);
            free(matriz_a);
            free(matriz_b);
            break;
        }
        printf("\n\n");
    }
    
    printf("\n\nresultado:\n\n");
    escrever_matriz(n_linhas, n_colunas, p_matriz_resultado);
    free(p_matriz_resultado);
    esperar();
}

void calculo_de_determinante()
{
    double determinante;

    while (1)
    {
        printf("det" ANSI_COLOR_RED "A" ANSI_COLOR_RESET "\n");

        printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
        int tamanho1[2];
        pedir_tamanho(tamanho1);
        int n_linhas1 = tamanho1[0];
        int n_colunas1 = tamanho1[1];

        if (n_linhas1 != n_colunas1)
        {
            printf( ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET " - apenas se pode calcular a determinante de matrizses quadradadas!\n");
        }
        else
        {
            printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
            double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
            pedir_matriz(n_linhas1, n_colunas1, matriz_a);

            determinante = determinante_matriz(n_linhas1, matriz_a);
            free(matriz_a);
            break;
        }
        printf("\n\n");
    }
    
    printf("\n\n");
    printf("determinante: %.2lf\n", determinante);
    esperar();
}

void inversa()
{
    int n_linhas, n_colunas;
    double * p_matriz_resultado;

    while (1)
    {
        printf(ANSI_COLOR_RED "A" ANSI_COLOR_RESET "^-1\n");

        printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
        int tamanho1[2];
        pedir_tamanho(tamanho1);
        int n_linhas1 = tamanho1[0];
        int n_colunas1 = tamanho1[1];

        if (n_linhas != n_colunas)
        {
            printf( ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET " - apenas da para calcular inversa de matrizes quadradas!\n");
        }
        else
        {
            n_linhas = n_linhas1;
            n_colunas = n_colunas1;
            p_matriz_resultado = (double *)malloc(n_linhas * n_colunas * sizeof(double));

            printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
            double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
            pedir_matriz(n_linhas1, n_colunas1, matriz_a);

            matriz_inversa(n_linhas1, matriz_a, p_matriz_resultado);
            free(matriz_a);
            break;
        }
        printf("\n\n");
    }
    
    printf("\n\nresultado:\n\n");
    escrever_matriz(n_linhas, n_colunas, p_matriz_resultado);
    free(p_matriz_resultado);
    esperar();
}

void transposta()
{
    int n_linhas, n_colunas;
    double * p_matriz_resultado;

    printf(ANSI_COLOR_RED "A" ANSI_COLOR_RESET "^t\n");

    printf("\ndimensoes da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
    int tamanho1[2];
    pedir_tamanho(tamanho1);
    int n_linhas1 = tamanho1[0];
    int n_colunas1 = tamanho1[1];

    n_linhas = n_colunas1;
    n_colunas = n_linhas1;
    p_matriz_resultado = (double *)malloc(n_linhas * n_colunas * sizeof(double));

    printf("\nelementos da matriz " ANSI_COLOR_RED "A" ANSI_COLOR_RESET ":\n");
    double * matriz_a = (double *)malloc(n_linhas1 * n_colunas1 * sizeof(double));
    pedir_matriz(n_linhas1, n_colunas1, matriz_a);

    transposta_matriz(n_linhas1, n_colunas1, matriz_a, p_matriz_resultado);
    free(matriz_a);
    
    printf("\n\n");
    escrever_matriz(n_linhas, n_colunas, p_matriz_resultado);
    free(p_matriz_resultado);
    esperar();
}

void main ()
{
    while (1)
    {
        clean_console();
        int n = pedir_op();
        
        switch (n)
        {
        case 1:
            adicao();
            break;
        case 2:
            subtracao();
            break;
        case 3:
            produto_escalar();
            break;
        case 4:
            produto_entre_matrizes();
            break;
        case 5:
            calculo_de_determinante();
            break;
        case 6:
            inversa();
            break;
        case 7:
            transposta();
            break;
        case 8:
            printf("Obrigado por usar a CALCULADORA DE MATRIZES <3\n");
            return;
        }
    }
}