#include <stdio.h>
#include <stdlib.h>
#include "input_output_matriz.h"
#include "funcoes.h"

// funcao que pergunta ao usuario qual operacao realizar
int pedir_op()
{
    while (1)
    {
        // pedir input do usuario
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
        int n = input_int("operacao desejada: ");

        // se a resposta estiver entre as opcoes, retornar o numero correspondente, se nao, perguntar de novo
        if (n > 0 && n <= 8)
        {
            return n;
        }
        else
        {
            clean_console();
            printf(
                "\nAviso! - input [%d] eh invalido!\n"
                "as opcoes de entrada possiveis sao:\n"
                "1, 2, 3, 4, 5, 6, 7, 8\n\n",
                n
            );
        }
    }
}

// funcoes que pedem os dados de entrada, realizam as operacoes usando as funcoes do funcoes.h e depois mostram o resultado:

void adicao()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    // while usado para pedir novos dados de entrada caso os dados de entrada sejam incopativeis com a operacao
    while (1)
    {
        printf("A + B\n\n");

        // pedir o tamanho das matrizes A e B
        int n_linhas_1, n_colunas_1;
        printf("tamanho de A:\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        int n_linhas_2, n_colunas_2;
        printf("tamanho de B:\n");
        input_matriz_size(&n_linhas_2, &n_colunas_2);
        printf("\n");

        // condicao para poder somar:
        // matrizes tem que ser do mesmo tamanho
        if (n_linhas_1 != n_linhas_2 || n_colunas_1 != n_colunas_2)
        {
            printf("Aviso! - matrizes A e B devem ter o mesmo tamanho!\n");
        }
        else
        {
            // definir tamanho da matriz resultado e criar espaco para a matriz resultado
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_1;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            // criar espaco para matriz A e B e pedir os elementos para ambas
            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf("A:\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            double * matriz_2 = (double *)calloc(n_linhas_2 * n_colunas_2, sizeof(double));
            printf("B:\n");
            input_matriz(n_linhas_2, n_colunas_2, matriz_2);
            printf("\n");

            // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input e sair do loop
            somar_matrizes(n_linhas_r, n_colunas_r, matriz_1, matriz_2, matriz_resultado);
            free(matriz_1);
            free(matriz_2);
            break;
        }
    }

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    printf("A + B:\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void subtracao()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    // while usado para pedir novos dados de entrada caso os dados de entrada sejam incopativeis com a operacao
    while (1)
    {
        printf("A - B\n\n");

        // pedir o tamanho das matrizes A e B
        int n_linhas_1, n_colunas_1;
        printf("tamanho de A:\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        int n_linhas_2, n_colunas_2;
        printf("tamanho de B:\n");
        input_matriz_size(&n_linhas_2, &n_colunas_2);
        printf("\n");

        // condicao para poder subtrair:
        // matrizes tem que ser do mesmo tamanho
        if (n_linhas_1 != n_linhas_2 || n_colunas_1 != n_colunas_2)
        {
            printf("Aviso! - matrizes A e B devem ter o mesmo tamanho!\n");
        }
        else
        {
            // definir tamanho da matriz resultado e criar espaco para a matriz resultado
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_1;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            // criar espaco para matriz A e B e pedir os elementos para ambas
            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf("A:\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            double * matriz_2 = (double *)calloc(n_linhas_2 * n_colunas_2, sizeof(double));
            printf("B:\n");
            input_matriz(n_linhas_2, n_colunas_2, matriz_2);
            printf("\n");

            // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input e sair do loop
            subtracao_matrizes(n_linhas_r, n_colunas_r, matriz_1, matriz_2, matriz_resultado);
            free(matriz_1);
            free(matriz_2);
            break;
        }
    }

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    printf("A - B:\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void produto_entre_matrizes()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    // while usado para pedir novos dados de entrada caso os dados de entrada sejam incopativeis com a operacao
    while (1)
    {
        printf("A x B\n\n");

        // pedir o tamanho das matrizes A e B
        int n_linhas_1, n_colunas_1;
        printf("tamanho de A:\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        int n_linhas_2, n_colunas_2;
        printf("tamanho de B:\n");
        input_matriz_size(&n_linhas_2, &n_colunas_2);
        printf("\n");

        // condicao para poder multiplicar:
        // numero de colunas da primeira tem que ser igual ao numero de linhas da segunda
        if (n_colunas_1 != n_linhas_2)
        {
            printf("Aviso! - numero de colunas de A deve ser igual ao numero de linhas de B!\n");
        }
        else
        {
            // definir tamanho da matriz resultado e criar espaco para a matriz resultado
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_2;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            // criar espaco para matriz A e B e pedir os elementos para ambas
            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf("A:\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            double * matriz_2 = (double *)calloc(n_linhas_2 * n_colunas_2, sizeof(double));
            printf("B:\n");
            input_matriz(n_linhas_2, n_colunas_2, matriz_2);
            printf("\n");

            // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input e sair do loop
            produto_matrizes(n_linhas_r, n_colunas_r, n_colunas_1, matriz_1, matriz_2, matriz_resultado);
            free(matriz_1);
            free(matriz_2);
            break;
        }
    }

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    printf("A x B:\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void calculo_determinante()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    double determinante = 0;

    // while usado para pedir novos dados de entrada caso os dados de entrada sejam incopativeis com a operacao
    while (1)
    {
        printf( "det(" "A)\n\n");

        // pedir o tamanho da matriz A
        int n_linhas_1, n_colunas_1;
        printf("tamanho de A:\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        // condicao para poder tirar determinante:
        // matriz tem que ser quadrada
        if (n_linhas_1 != n_colunas_1)
        {
            printf("Aviso! - A deve ser uma matriz quadrada!\n");
        }
        else
        {
            // criar espaco para matriz A e pedir os elementos para ela
            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf("A:\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input e sair do loop
            determinante = determinante_matriz(n_linhas_1, matriz_1);
            free(matriz_1);
            break;
        }
    }

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    printf("det(A) = %.2lf\n\n", determinante);
    wait();
}

void inversa()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    int inversivel; // variavel usada para saber se a matriz pode ser invertida

    // while usado para pedir novos dados de entrada caso os dados de entrada sejam incopativeis com a operacao
    while (1)
    {
        printf("A^-1\n\n");

        // pedir o tamanho da matriz A
        int n_linhas_1, n_colunas_1;
        printf("tamanho de A:\n");
        input_matriz_size(&n_linhas_1, &n_colunas_1);
        printf("\n");

        // condicao para poder achar inversa:
        // matriz tem que ser quadrada
        if (n_linhas_1 != n_colunas_1)
        {
            printf("Aviso! - A deve ser uma matriz quadrada!\n");
        }
        else
        {
            // definir tamanho da matriz resultado e criar espaco para a matriz resultado
            n_linhas_r = n_linhas_1;
            n_colunas_r = n_colunas_1;
            matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

            // criar espaco para matriz A e pedir os elementos para ela
            double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
            printf("A:\n");
            input_matriz(n_linhas_1, n_colunas_1, matriz_1);
            printf("\n");

            // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input e sair do loop
            inversivel = matriz_inversa(n_linhas_r, matriz_1, matriz_resultado);
            free(matriz_1);
            break;
        }
    }

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    if (inversivel)
    {
        printf("A^-1:\n\n");
        output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    }
    else
    {
        // se nao puder ser invertida a funcao deixa claro e segue  sem mostrar uma matriz como resultado
        printf("a matriz A nao pode ser invertida!");
    }
    free(matriz_resultado);
    printf("\n");
    wait();
}

void produto_escalar()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    printf("A * n\n\n");

    // pedir o tamanho da matriz A
    int n_linhas_1, n_colunas_1;
    printf("tamanho de A:\n");
    input_matriz_size(&n_linhas_1, &n_colunas_1);
    printf("\n");

    // definir tamanho da matriz resultado e criar espaco para a matriz resultado
    n_linhas_r = n_linhas_1;
    n_colunas_r = n_colunas_1;
    matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

    // criar espaco para matriz A e pedir os elementos para ela
    double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
    printf("A:\n");
    input_matriz(n_linhas_1, n_colunas_1, matriz_1);
    printf("\n");

    double escalar = input_double( "n: ");
    printf("\n");

    // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input
    produto_escalar_matriz(n_linhas_r, n_colunas_r, matriz_1, escalar, matriz_resultado);
    free(matriz_1);

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    printf("A * n:\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void transposta()
{
    // criar variaveis que vao ser usadas para mostrar o resultado
    int n_linhas_r, n_colunas_r;
    double * matriz_resultado;

    printf("A^t\n\n");

    // pedir o tamanho da matriz A
    int n_linhas_1, n_colunas_1;
    printf("tamanho de A:\n");
    input_matriz_size(&n_linhas_1, &n_colunas_1);
    printf("\n");

    // definir tamanho da matriz resultado e criar espaco para a matriz resultado
    n_linhas_r = n_colunas_1;
    n_colunas_r = n_linhas_1;
    matriz_resultado = (double *)calloc(n_linhas_r * n_colunas_r, sizeof(double));

    // criar espaco para matriz A e pedir os elementos para ela
    double * matriz_1 = (double *)calloc(n_linhas_1 * n_colunas_1, sizeof(double));
    printf("A:\n");
    input_matriz(n_linhas_1, n_colunas_1, matriz_1);
    printf("\n");

    // realizar opercao usando funcao do funcoes.h e liberar espaco dedicado as matrizes input
    transposta_matriz(n_linhas_1, n_colunas_1, matriz_1, matriz_resultado);
    free(matriz_1);

    // escrever resultado, liberar espaco dedicado a matriz resultado, e esperar o usuario para sair da funcao
    printf("A^t:\n\n");
    output_matriz(n_linhas_r, n_colunas_r, matriz_resultado);
    free(matriz_resultado);
    printf("\n");
    wait();
}

void main()
{
    // loop infinito até o usuario selecionar para sair
    while (1)
    {
        // pedir uma operacao para o usuario
        int n = pedir_op();
        printf("\n");

        // usar o switch case para realizar a operacao desejada
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
            // a "opercao" 8 faz a funcao main parar atravez do return;
            printf("obrigado por usar a CALCULADORA DE MATRIZES <3\n\n");
            return;
        }
        
        clean_console();
    }
}