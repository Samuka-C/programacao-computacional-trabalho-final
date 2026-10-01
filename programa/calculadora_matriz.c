#include <stdio.h>
#include <stdlib.h>
#include "input_output_matriz.h"
#include "funcoes.h"
#include "colors.h"


int pedir_op()
{
    clean_console();
    while (1)
    {
        // pedir input do usuário
        printf(
            "CALCULADORA DE MATRIZES\n"
            "operacoes possiveis:\n"
            BLUE "1" NORMAL " - adicao\n"
            BLUE "2" NORMAL " - subtracao\n"
            BLUE "3" NORMAL " - produto escalar\n"
            BLUE "4" NORMAL " - produto entre matrizes\n"
            BLUE "5" NORMAL " - calculo de determinante\n"
            BLUE "6" NORMAL " - inversa\n"
            BLUE "7" NORMAL " - transposta\n"
            BLUE "8" NORMAL" - " RED "sair" NORMAL "\n" 
        );
        int n = input_int("operacao desejada: ");

        if (n > 0 && n <= 8)
        {
            return n;
        }
        else
        {
            clean_console();
            printf(
                RED "\nAviso!" NORMAL
                " - input " YELLOW "[%d]" NORMAL " eh invalido!\n"
                "as opcoes de entrada possiveis sao:\n"
                BLUE "1, 2, 3, 4, 5, 6, 7, 8\n\n" NORMAL,
                n
            );
        }
    }
}

void adicao()
{
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    while (1)
    {
        printf( MAGENTA "A" NORMAL " + " CYAN "B" NORMAL "\n\n");

        int n_linhas_1, n_colunas_1;
        printf("tamanho de " MAGENTA "A" NORMAL ":\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        int n_linhas_2, n_colunas_2;
        printf("tamanho de " CYAN "B" NORMAL ":\n");
        input_matriz_size(&n_linhas_2, &n_colunas_2);
        printf("\n");

        if (n_linhas_1 != n_linhas_2 || n_colunas_1 != n_colunas_2)
        {
            printf( RED "Aviso!" NORMAL " - matrizes " MAGENTA "A" NORMAL " e " CYAN "B" NORMAL " devem ter o mesmo tamanho!\n");
        }
        else
        {
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_1;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf( MAGENTA "A" NORMAL ":\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            double * matriz_2 = (double *)calloc(n_linhas_2 * n_colunas_2, sizeof(double));
            printf( CYAN "B" NORMAL ":\n");
            input_matriz(n_linhas_2, n_colunas_2, matriz_2);
            printf("\n");

            somar_matrizes(n_linhas_r, n_colunas_r, matriz_1, matriz_2, matriz_resultado);

            free(matriz_1);
            free(matriz_2);
            break;
        }
    }

    printf( MAGENTA "A" NORMAL " + " CYAN "B" NORMAL ":\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void subtracao()
{
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    while (1)
    {
        printf( MAGENTA "A" NORMAL " - " CYAN "B" NORMAL "\n\n");

        int n_linhas_1, n_colunas_1;
        printf("tamanho de " MAGENTA "A" NORMAL ":\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        int n_linhas_2, n_colunas_2;
        printf("tamanho de " CYAN "B" NORMAL ":\n");
        input_matriz_size(&n_linhas_2, &n_colunas_2);
        printf("\n");

        if (n_linhas_1 != n_linhas_2 || n_colunas_1 != n_colunas_2)
        {
            printf( RED "Aviso!" NORMAL " - matrizes " MAGENTA "A" NORMAL " e " CYAN "B" NORMAL " devem ter o mesmo tamanho!\n");
        }
        else
        {
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_1;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf( MAGENTA "A" NORMAL ":\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            double * matriz_2 = (double *)calloc(n_linhas_2 * n_colunas_2, sizeof(double));
            printf( CYAN "B" NORMAL ":\n");
            input_matriz(n_linhas_2, n_colunas_2, matriz_2);
            printf("\n");

            subtracao_matrizes(n_linhas_r, n_colunas_r, matriz_1, matriz_2, matriz_resultado);

            free(matriz_1);
            free(matriz_2);
            break;
        }
    }

    printf( MAGENTA "A" NORMAL " - " CYAN "B" NORMAL ":\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void produto_entre_matrizes()
{
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    while (1)
    {
        printf( MAGENTA "A" NORMAL " x " CYAN "B" NORMAL "\n\n");

        int n_linhas_1, n_colunas_1;
        printf("tamanho de " MAGENTA "A" NORMAL ":\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        int n_linhas_2, n_colunas_2;
        printf("tamanho de " CYAN "B" NORMAL ":\n");
        input_matriz_size(&n_linhas_2, &n_colunas_2);
        printf("\n");

        if (n_colunas_1 != n_linhas_2)
        {
            printf( RED "Aviso!" NORMAL " - numero de colunas de " MAGENTA "A" NORMAL " deve ser igual ao numero de linhas de " CYAN "B" NORMAL "!\n");
        }
        else
        {
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_2;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf( MAGENTA "A" NORMAL ":\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            double * matriz_2 = (double *)calloc(n_linhas_2 * n_colunas_2, sizeof(double));
            printf( CYAN "B" NORMAL ":\n");
            input_matriz(n_linhas_2, n_colunas_2, matriz_2);
            printf("\n");

            produto_matrizes(n_linhas_r, n_colunas_r, n_colunas_1, matriz_1, matriz_2, matriz_resultado);

            free(matriz_1);
            free(matriz_2);
            break;
        }
    }

    printf( MAGENTA "A" NORMAL " x " CYAN "B" NORMAL ":\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void calculo_determinante()
{
    double determinante = 0;

    while (1)
    {
        printf( "det("MAGENTA "A" NORMAL ")\n\n");

        int n_linhas_1, n_colunas_1;
        printf("tamanho de " MAGENTA "A" NORMAL ":\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        if (n_linhas_1 != n_colunas_1)
        {
            printf( RED "Aviso!" NORMAL " - " MAGENTA "A" NORMAL " deve ser uma matriz quadrada!\n");
        }
        else
        {
            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf( MAGENTA "A" NORMAL ":\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            determinante = determinante_matriz(n_linhas_1, matriz_1);

            free(matriz_1);
            break;
        }
    }

    printf("det(" MAGENTA "A" NORMAL ") = %.2lf\n\n", determinante);
    wait();
}

void inversa()
{
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    int inversivel;

    while (1)
    {
        printf( MAGENTA "A" NORMAL "^-1\n\n");

        int n_linhas_1, n_colunas_1;
        printf("tamanho de " MAGENTA "A" NORMAL ":\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        if (n_linhas_1 != n_colunas_1)
        {
            printf( RED "Aviso!" NORMAL " - " MAGENTA "A" NORMAL " deve ser uma matriz quadrada!\n");
        }
        else
        {
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_1;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf( MAGENTA "A" NORMAL ":\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            inversivel = matriz_inversa(n_linhas_r, matriz_1, matriz_resultado);

            free(matriz_1);
            break;
        }
    }

    if (inversivel)
    {
        printf( MAGENTA "A" NORMAL "^-1:\n\n");
        output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    }
    else
    {
        printf("a matriz " MAGENTA "A" NORMAL " nao pode ser invertida!");
    }
    free(matriz_resultado);
    printf("\n");
    wait();
}

void produto_escalar()
{
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    printf( MAGENTA "A" NORMAL " * " CYAN "n" NORMAL "\n\n");

    int n_linhas_1, n_colunas_1;
    printf("tamanho de " MAGENTA "A" NORMAL ":\n");
    input_matriz_size(&n_linhas_1, &n_colunas_1);
    printf("\n");

    n_linhas_r = n_linhas_1;
    n_colunas_r = n_colunas_1;
    matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

    double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
    printf( MAGENTA "A" NORMAL ":\n");
    input_matriz(n_linhas_1, n_colunas_1, matriz_1);
    printf("\n");

    double escalar = input_double(CYAN "n" NORMAL ": ");
    printf("\n");

    produto_escalar_matriz(n_linhas_r, n_colunas_r, matriz_1, escalar, matriz_resultado);

    free(matriz_1);

    printf( MAGENTA "A" NORMAL " * " CYAN "n" NORMAL ":\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void transposta()
{
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    printf( MAGENTA "A" NORMAL "^t\n\n");

    int n_linhas_1, n_colunas_1;
    printf("tamanho de " MAGENTA "A" NORMAL ":\n");
    input_matriz_size(&n_linhas_1, &n_colunas_1);
    printf("\n");

    n_linhas_r = n_colunas_1;
    n_colunas_r = n_linhas_1;
    matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

    double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
    printf( MAGENTA "A" NORMAL ":\n");
    input_matriz(n_linhas_1, n_colunas_1, matriz_1);
    printf("\n");

    transposta_matriz(n_linhas_1, n_colunas_1, matriz_1, matriz_resultado);

    free(matriz_1);

    printf( MAGENTA "A" NORMAL "^t:\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void main()
{
    printf("Hello world");
    while (1)
    {
        int n = pedir_op();
        printf("\n");

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
            calculo_determinante();
            break;
        case 6:
            inversa();
            break;
        case 7:
            transposta();
            break;
        case 8:
            printf("obrigado por usar a CALCULADORA DE MATRIZES <3\n\n");
            return;
        }
    }
}