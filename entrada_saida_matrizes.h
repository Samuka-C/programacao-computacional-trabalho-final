#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

#define ENOUGH 256
#define ANSI_COLOR_RESET  "\x1b[0m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE   "\x1b[34m"

enum 
{
    FALSE,
    TRUE
};

void clear_input_buffer()
{
    while ( getchar() != '\n' );
}

void esperar()
{
    printf("\n\naperte qualquer coisa para continuar...\n");
    getchar();
    clear_input_buffer();
}

int pedir_int(char * string_pedir_input)
{
    while (1)
    {
        char * resposta = (char *)calloc(ENOUGH, sizeof(char));

        printf("%s", string_pedir_input);
        scanf("%[^\n]s", resposta);
        clear_input_buffer();

        int len = strlen(resposta);

        int negative = FALSE;

        int numbers[ENOUGH];
        int len_num = 0;

        int erro = FALSE;

        if (len == 0)
        {
            printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - entrada vazia!\n"
            );
            erro = TRUE;
        }

        for (int i = 0; i < len; i++)
        {
            char resposta_char_i = resposta[i];
            int is_number = FALSE;
            int number = -1;
            int is_minus = FALSE;

            if (resposta_char_i - '0' >= 0 && resposta_char_i - '0' < 10)
            {   
                is_number = TRUE;
                number = resposta_char_i - '0';
            }
            else if (resposta_char_i == '-')
            {
                is_minus = TRUE;
            }

            if (!(is_number || is_minus))
            {
                printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - caractere "ANSI_COLOR_YELLOW"[%c]"ANSI_COLOR_RESET" em "ANSI_COLOR_YELLOW"[%s]"ANSI_COLOR_RESET" eh invalido\n",
                    resposta_char_i, resposta
                );
                erro = TRUE;
                break;
            }
            else if (is_minus && i > 0)
            {
                printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - caractere "ANSI_COLOR_YELLOW"[%c]"ANSI_COLOR_RESET" em "ANSI_COLOR_YELLOW"[%s]"ANSI_COLOR_RESET" nao pode vir no meio do numero\n",
                    resposta_char_i, resposta
                );
                erro = TRUE;
                break;
            }
            else if (is_minus)
            {
                negative = TRUE;
            }
            else 
            {
                numbers[len_num] = number;
                len_num++;
            }
        }

        free(resposta);

        if (!erro)
        {
            int valor = 0;

            for (int i = 0; i < len_num; i++)
            {
                valor += numbers[i] * pow(10, (len_num - 1 - i));
            }

            if (negative)
            {
                valor *= -1;
            }

            return valor;
        }

        printf("\n\n");
    }
}

double pedir_double(char * string_pedir_input)
{
    while (1)
    {
        char * resposta = (char *)calloc(ENOUGH, sizeof(char));

        printf("%s", string_pedir_input);
        scanf("%[^\n]s", resposta);
        clear_input_buffer();

        int len = strlen(resposta);

        int negative = FALSE;

        int numbers_before_dot[ENOUGH];
        int numbers_after_dot[ENOUGH];
        int len_num_bf_dot = 0;
        int len_num_af_dot = 0;

        int after_dot = FALSE;

        int erro = FALSE;

        if (len == 0)
        {
            printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - entrada vazia!\n"
            );
            erro = TRUE;
        }

        for (int i = 0; i < len; i++)
        {
            char resposta_char_i = resposta[i];
            int is_number = FALSE;
            int number = -1;
            int is_dot = FALSE;
            int is_minus = FALSE;

            if (resposta_char_i - '0' >= 0 && resposta_char_i - '0' < 10)
            {   
                is_number = TRUE;
                number = resposta_char_i - '0';
            }
            else if (resposta_char_i == '.')
            {
                is_dot = TRUE;
            }
            else if (resposta_char_i == '-')
            {
                is_minus = TRUE;
            }

            if (!(is_number || is_dot || is_minus))
            {
                printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - caractere "ANSI_COLOR_YELLOW"[%c]"ANSI_COLOR_RESET" em "ANSI_COLOR_YELLOW"[%s]"ANSI_COLOR_RESET" eh invalido\n",
                    resposta_char_i, resposta
                );
                erro = TRUE;
                break;
            }
            else if (is_minus && i > 0)
            {
                printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - caractere "ANSI_COLOR_YELLOW"[%c]"ANSI_COLOR_RESET" em "ANSI_COLOR_YELLOW"[%s]"ANSI_COLOR_RESET" nao pode vir no meio do numero\n",
                    resposta_char_i, resposta
                );
                erro = TRUE;
                break;
            }
            else if (is_minus)
            {
                negative = TRUE;
            }
            else if (is_dot && after_dot)
            {
                printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - caractere "ANSI_COLOR_YELLOW"[%c]"ANSI_COLOR_RESET" em "ANSI_COLOR_YELLOW"[%s]"ANSI_COLOR_RESET" nao pode existir depois de outro ponto\n",
                    resposta_char_i, resposta
                );
                erro = TRUE;
                break;
            }
            else if (is_dot && i <= 1 && ((i > 0) == (is_minus)))
            {
                printf(
                    "\n" ANSI_COLOR_RED "Aviso!" ANSI_COLOR_RESET
                    " - caractere "ANSI_COLOR_YELLOW"[%c]"ANSI_COLOR_RESET" em "ANSI_COLOR_YELLOW"[%s]"ANSI_COLOR_RESET" nao pode vir antes de algum numero\n",
                    resposta_char_i, resposta
                );
                erro = TRUE;
                break;
            }
            else if (is_dot)
            {
                after_dot = TRUE;
            }
            else 
            {
                if (after_dot)
                {
                    numbers_after_dot[len_num_af_dot] = number;
                    len_num_af_dot++;
                }
                else
                {
                    numbers_before_dot[len_num_bf_dot] = number;
                    len_num_bf_dot++;
                }
            }
        }

        free(resposta);

        if (!erro)
        {
            double valor = 0;

            for (int i = 0; i < len_num_bf_dot; i++)
            {
                valor += numbers_before_dot[i] * pow(10, (len_num_bf_dot - 1 - i));
            }
            for (int i = 0; i < len_num_af_dot; i++)
            {
                valor += numbers_after_dot[i] * pow(10, -(i + 1));
            }

            if (negative)
            {
                valor *= -1;
            }

            return valor;
        }

        printf("\n\n");
    }
}

void pedir_tamanho(int * tamanho)
{
    int n_linhas, n_colunas;
    while (1)
    {
        n_linhas = pedir_int("numero de linhas: ");
        if (n_linhas > 0)
        {
            break;
        }
        printf("o numero de linhas, " ANSI_COLOR_YELLOW "[%d]" ANSI_COLOR_RESET "nao pode ser zero ou negativo!\n", n_linhas);
    }
    while (1)
    {
        n_colunas = pedir_int("numero de colunas: ");
        if (n_colunas > 0)
        {
            break;
        }
        printf("o numero de linhas, " ANSI_COLOR_YELLOW "[%d]" ANSI_COLOR_RESET "nao pode ser zero ou negativo!\n", n_colunas);
    }

    tamanho[0] = n_linhas;
    tamanho[1] = n_colunas;
}

void escrever_matriz(int n_linhas, int n_colunas, double * matriz)
{
    int max[n_colunas];
    int sizes[n_linhas][n_colunas];

    for (int c = 0; c < n_colunas; c++)
    {
        max[c] = 0;
        for (int l = 0; l < n_linhas; l++)
        {
            char numero[ENOUGH];

            double valor = *acs(n_colunas, l, c, matriz);
            sprintf(numero, "%.2lf", valor);
            int len = strlen(numero);

            sizes[l][c] = len;
            if (len > max[c])
            {
                max[c] = len;
            }
        }
    }

    for (int l = 0; l < n_linhas; l++)
    {
        for (int c = 0; c < n_colunas; c++)
        {
            if (c > 0)
            {
                printf(" ");
            }

            double valor = *acs(n_colunas, l, c, matriz);
            printf("%.2lf", valor);
            for (int i = 0; i < max[c] - sizes[l][c]; i++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void pedir_matriz(int n_linhas, int n_colunas, double * matriz_retorno)
{
    for (int l = 1; l <= n_linhas; l++)
    {
        for (int c = 1; c <= n_colunas; c++)
        {
            char string_pedir_input[ENOUGH];
            sprintf(string_pedir_input, "digite um valor para o elemento %d, %d: ", l, c);

            double valor = pedir_double(string_pedir_input);
            *acs(n_colunas, l, c, matriz_retorno) = valor;
            printf("valor na matriz_retorno (%d, %d): %.2lf\n", l, c, *acs(n_colunas, l, c, matriz_retorno));
        }
    }
}