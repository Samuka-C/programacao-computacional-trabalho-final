#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "colors.h"

#define INPUT_LENGHT 256

enum 
{
    FALSE,
    TRUE
};

// limpar a tela ou dar um espaco para a proxima operacao
void clean_console()
{
    printf("\e[1;1H\e[2J");
}

// limpar o buffer de entrada do C para evitar erros quando usar o scanf
void clear_input_buffer()
{
    while ( getchar() != '\n' );
}

// funcao faz o programa esperar por um enter antes de continuar
void wait()
{
    printf("pressione [" YELLOW "ENTER" NORMAL "] para prosseguir...");
    char * input = (char *)calloc(INPUT_LENGHT, sizeof(char));
    scanf("%[^\n]s", input);
    clear_input_buffer();
    free(input);
}

// funcao escreve uma mensagem, pede um input se o input for um numero inteiro, retorna o numero, se nao, pede novamente
int input_int(char * string_pedir_input)
{
    while (1)
    {
        // escrever string que pede o input e deixar a cor da letra azul se USAR_CODES estiver ativo
        printf("%s" BLUE, string_pedir_input);

        // alocar espaço na memoria para receber o input e criar um ponteiro para esse local na memoria
        char * input = (char *)calloc(INPUT_LENGHT, sizeof(char));

        // pegar input e colocar na memoria alocada, e limpar o buffer de entrada
        scanf("%[^\n]s", input);
        clear_input_buffer();
        
        // voltar a cor ao normal se USAR_CODES estiver ativo
        printf(NORMAL);

        // variavel responsavel por verificar que houve algum erro na hora de converter o input para int
        int erro = FALSE;

        // conseguir o tamanho do input e dar erro se for 0
        int len = strlen(input);
        if (len == 0)
        {
            printf(
                RED "\nAviso!" NORMAL " - entrada vazia\n\n"
            );
            erro = TRUE;
        }

        int negativo = FALSE;

        int * algarismos = (int *)calloc(len, sizeof(int));
        int len_algarismos = 0;

        // rodar cada caractere do input
        for (int i = 0; i < len; i++)
        {
            char input_i = *(input + i);

            if (input_i == '-')
            {
                if (i == 0) {
                    negativo = TRUE;
                }
                else
                {
                    printf(
                        RED "\nAviso!" NORMAL " - " YELLOW "[%c]" NORMAL " em " YELLOW "[%s]" NORMAL " so pode vir no comeco do numero!\n\n",
                        input_i, input
                    );
                    erro = TRUE;
                }
            }
            else if (input_i - '0' >= 0 && input_i - '0' < 10)
            {
                *(algarismos + len_algarismos) = (int)(input_i - '0');
                len_algarismos++;
            }
            else
            {
                printf(
                    RED "\nAviso!" NORMAL " - " YELLOW "[%c]" NORMAL " em " YELLOW "[%s]" NORMAL " eh invalido!\n\n",
                    input_i, input
                );
                erro = TRUE;
            }

            if (erro)
            {
                break;
            }
        }

        free(input);
        
        // se nao tiver erros, montar o numero baseado nos algarismos e outros sinais
        if (!erro)
        {
            int inteiro = 0;

            for (int i = 0; i < len_algarismos; i++)
            {
                int alagismo_i = *(algarismos + i);
                inteiro += alagismo_i * pow(10, len_algarismos - i - 1);
            }

            if (negativo)
            {
                inteiro *= -1;
            }

            free(algarismos);
            return inteiro;
        }

        free(algarismos);
    }
}

// funcao escreve uma mensagem, pede um input se o input for um numero real, retorna o numero, se nao, pede novamente
double input_double(char * string_pedir_input)
{
    while (1)
    {
        // escrever string que pede o input e deixar a cor da letra azul
        printf("%s" BLUE, string_pedir_input);

        // alocar espaço na memoria para receber o input e criar um ponteiro para esse local na memoria
        char * input = (char *)calloc(INPUT_LENGHT, sizeof(char));

        // pegar input e colocar na memoria alocada, e limpar o buffer de entrada
        scanf("%[^\n]s", input);
        clear_input_buffer();

        // voltar a cor ao normal se USAR_CODES estiver ativo
        printf(NORMAL);

        // variavel responsável por verificar que houve algum erro na hora de converter o input para int
        int erro = FALSE;

        // conseguir o tamanho do input e dar erro se for 0
        int len = strlen(input);
        if (len == 0)
        {
            printf(
                RED "\nAviso!" NORMAL " - entrada vazia\n\n"
            );
            erro = TRUE;
        }

        int negativo = FALSE;
        int passou_do_ponto = FALSE;

        int * algarismos_antes_ponto = (int *)calloc(len, sizeof(int));
        int len_algarismos_antes_ponto = 0;

        int * algarismos_depois_ponto = (int *)calloc(len, sizeof(int));
        int len_algarismos_depois_ponto = 0;

        // rodar cada algarismo do input
        for (int i = 0; i < len; i++)
        {
            char input_i = *(input + i);

            if (input_i == '-')
            {
                if (i == 0) {
                    negativo = TRUE;
                }
                else
                {
                    printf(
                        RED "\nAviso!" NORMAL " - " YELLOW "[%c]" NORMAL " em " YELLOW "[%s]" NORMAL " so pode vir no comeco do numero!\n\n",
                        input_i, input
                    );
                    erro = TRUE;
                }
            }
            else if (input_i == '.')
            {
                if (passou_do_ponto)
                {
                    printf(
                        RED "\nAviso!" NORMAL " - " YELLOW "[%c]" NORMAL " em " YELLOW "[%s]" NORMAL " nao pode vir depois de outro ponto!\n\n",
                        input_i, input
                    );
                    erro = TRUE;
                }
                else
                {
                    passou_do_ponto = TRUE;
                }
            }
            else if (input_i - '0' >= 0 && input_i - '0' < 10)
            {
                if (passou_do_ponto)
                {
                    *(algarismos_depois_ponto + len_algarismos_depois_ponto) = (int)(input_i - '0');
                    len_algarismos_depois_ponto++;
                }
                else
                {
                    *(algarismos_antes_ponto + len_algarismos_antes_ponto) = (int)(input_i - '0');
                    len_algarismos_antes_ponto++;
                }
            }
            else
            {
                printf(
                    RED "\nAviso!" NORMAL " - " YELLOW "[%c]" NORMAL " em " YELLOW "[%s]" NORMAL " eh invalido!\n\n",
                    input_i, input
                );
                erro = TRUE;
            }

            if (erro)
            {
                break;
            }
        }

        free(input);

        // se nao tiver erros, montar o numero baseado nos algarismos e outros sinais
        if (!erro)
        {
            double real = 0;

            for (int i = 0; i < len_algarismos_antes_ponto; i++)
            {
                int alagismo_i = *(algarismos_antes_ponto + i);
                real += alagismo_i * pow(10, len_algarismos_antes_ponto - i - 1);
            }

            for (int i = 0; i < len_algarismos_depois_ponto; i++)
            {
                int alagismo_i = *(algarismos_depois_ponto + i);
                real += alagismo_i * pow(10, - i - 1);
            }

            if (negativo)
            {
                real *= -1;
            }

            free(algarismos_antes_ponto);
            free(algarismos_depois_ponto);
            return real;
        }

        free(algarismos_antes_ponto);
        free(algarismos_depois_ponto);
    }
}
