#include <stdio.h>

enum 
{
    False,
    True
};

// funcao que acessa valores de uma matriz a partir do ponteiro do primeiro elemento
double * acs(int n_colunas, int linha, int coluna, double * matriz)
{
    return matriz + linha * n_colunas + coluna;
}

/*
acessar o elemento l, c de uma matriz dada por double * matriz_x com n_colunas:
    *acs(n_colunas, l, c, matriz_x)
*/

double somar_matrizes(int n_linhas, int n_colunas, double * p_matriz_a, double * p_matriz_b, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_b (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // Declaracao das variaveis
    double matriz_a[n_linhas][n_colunas];
    double matriz_b[n_linhas][n_colunas];
    double soma[n_linhas][n_colunas];
    
    //Laco que le o ponteiro da matriz externa e escreve os valores em matrizes locais
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
            matriz_a[l][c] = *acs(n_colunas, l, c, p_matriz_a);
            matriz_b[l][c] = *acs(n_colunas, l, c, p_matriz_b);
        }
    }

    //Laco que realiza a soma
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
			soma[l][c] = matriz_a[l][c] + matriz_b[l][c];
        }
    }

    //Laco que escreve o resultado no ponteiro da matriz externa
    for (int l = 0; l < n_linhas; l++)
    {
    	for(int c = 0; c < n_colunas; c++)
		{
            *acs(n_colunas, l, c, p_matriz_resultado) = soma[l][c];
        }
	}
}

void subtracao_matrizes(int n_linhas, int n_colunas, double * p_matriz_a, double * p_matriz_b, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_b (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // Declaracao das variaveis
    double matriz_a[n_linhas][n_colunas];
    double matriz_b[n_linhas][n_colunas];
    double subtracao[n_linhas][n_colunas];

    //Laco que le o ponteiro da matriz externa e escreve os valores em matrizes locais
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
            matriz_a[l][c] = *acs(n_colunas, l, c, p_matriz_a);
            matriz_b[l][c] = *acs(n_colunas, l, c, p_matriz_b);
        }
    }

    //Laco que realiza a subtracao
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
			subtracao[l][c] = matriz_a[l][c] - matriz_b[l][c];
        }
    }

    //Laco que escreve o resultado no ponteiro da matriz externa
    for (int l = 0; l < n_linhas; l++)
    {
    	for(int c = 0; c < n_colunas; c++)
		{
            *acs(n_colunas, l, c, p_matriz_resultado) = subtracao[l][c];
        }
	}
}

void produto_escalar_matriz(int n_linhas, int n_colunas, double * p_matriz_a, double escalar, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // Declaracao das variaveis
    double matriz_a[n_linhas][n_colunas];
    double produto_e[n_linhas][n_colunas];

    //Laco que le o ponteiro da matriz externa e escreve os valores em matrizes locais
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
            matriz_a[l][c] = *acs(n_colunas, l, c, p_matriz_a);
        }
    }

    //Laco que realiza a multiplicacao
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
			produto_e[l][c] = matriz_a[l][c] * escalar;
        }
    }

    //Laco que escreve o resultado no ponteiro da matriz externa
    for (int l = 0; l < n_linhas; l++)
    {
    	for(int c = 0; c < n_colunas; c++)
		{
            *acs(n_colunas, l, c, p_matriz_resultado) = produto_e[l][c];
        }
	}
}

void produto_matrizes(int n_linhas, int n_colunas, int n_intermediario, double * p_matriz_a, double * p_matriz_b, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_intermediario)
    tamanho da matriz_b (n_intermediario x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // Declaracao das variaveis
    double matriz_a[n_linhas][n_intermediario];
    double matriz_b[n_intermediario][n_colunas];
    double produto[n_linhas][n_colunas];

    //Laco que le o ponteiro da matriz externa e escreve os valores em matrizes locais
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_intermediario; c++)
		{
            matriz_a[l][c] = *acs(n_intermediario, l, c, p_matriz_a);
        }
    }
    
    for (int l = 0; l < n_intermediario; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
            matriz_b[l][c] = *acs(n_colunas, l, c, p_matriz_b);
        }
    }

    //Laco que realiza a multiplicacao das matrizes
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
			double ponte = 0;
			
			for (int x = 0; x < n_intermediario; x++)
			{
				ponte += matriz_a[l][x] * matriz_b[x][c];
			}
			
			produto[l][c] = ponte;
		}
	}

    //Laco que escreve o resultado no ponteiro da matriz externa
    for (int l = 0; l < n_linhas; l++)
    {
    	for(int c = 0; c < n_colunas; c++)
		{
            *acs(n_colunas, l, c, p_matriz_resultado) = produto[l][c];
        }
	}
}

double determinante_matriz(int n, double * p_matriz_a)
{
    /*
    tamanho da matriz_a (n x n)
    */

    // Declaracao das variaveis
    double matriz_a[n][n];

    //Laco que le o ponteiro da matriz externa e escreve os valores em matrizes locais
    for (int l = 0; l < n; l++)
	{ 
        for (int c = 0 ; c < n; c++)
		{
            matriz_a[l][c] = *acs(n, l, c, p_matriz_a);
        }
    }

    // reducao gaussina
    for (int c = 0; c < n; c++)
    {
        if (matriz_a[c][c] == 0)
        {
            if (c == n - 1)
            {
                return 0;
            }

            int coluna_de_zero = True;
            
            for (int l = c + 1; l < n; l++)
            {
                if (matriz_a[l][c] != 0)
                {
                    for (int x = 0; x < n; x++)
                    {
                        matriz_a[c][x] += matriz_a[l][x];
                    }
                    coluna_de_zero = False;
                    break;
                }
            }
    
            if (coluna_de_zero)
            {
                return 0;
            }
        }
        
        for (int l = c + 1; l < n; l++)
        {
            double fator = matriz_a[l][c] / matriz_a[c][c];

            for (int x = 0; x < n; x++)
            {
                matriz_a[l][x] -= matriz_a[c][x] * fator;
            }
        }
    }

	// fazer produto da diagonal principal
    double determinante = 1;

    for (int l = 0; l < n; l++)
    {
        determinante *= matriz_a[l][l];
    }

    return determinante;
}

int matriz_inversa(int n, double * p_matriz_a, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n x n)
    tamanho da matriz_resultado (n x n)
    */

    // Declaracao das variaveis
    double matriz_a[n][n];
    double inversa[n][n];

    //Laco que le o ponteiro da matriz externa e escreve os valores em matrizes locais
    for (int l = 0; l < n; l++)
	{ 
        for (int c = 0 ; c < n; c++)
		{
            matriz_a[l][c] = *acs(n, l, c, p_matriz_a);
        }
    }

    // preencher a inversa com 1 na diagonal principal para transformar em uma matriz indentidade
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            if (l == c)
            {
                inversa[l][c] = 1;
            }
            else
            {
                inversa[l][c] = 0;
            }
        }
    }

    // reducao gaussina
    for (int c = 0; c < n; c++)
    {
        if (matriz_a[c][c] == 0)
        {
            if (c == n - 1)
            {
                return False;
            }

            int coluna_de_zero = True;
            for (int l = c + 1; l < n; l++)
            {
                if (matriz_a[l][c] != 0)
                {
                    for (int x = 0; x < n; x++)
                    {
                        matriz_a[c][x] += matriz_a[l][x];

                        inversa[c][x] += inversa[l][x];
                    }
                    coluna_de_zero = False;
                    break;
                }
            }
    
            if (coluna_de_zero)
            {
                return False;
            }
        }
        
        for (int l = c + 1; l < n; l++)
        {
            double fator = matriz_a[l][c] / matriz_a[c][c];

            for (int x = 0; x < n; x++)
            {
                matriz_a[l][x] -= matriz_a[c][x] * fator;

                inversa[l][x] -= inversa[c][x] * fator;
            }
        }
    }

    // reducao gauss-jordan
    for (int c = n - 1; c >= 0; c--)
    {
        double fator = 1 / matriz_a[c][c];

        for (int x = 0; x < n; x++)
        {
            matriz_a[c][x] *= fator;

            inversa[c][x] *= fator;
        }

        for (int l = c - 1; l >= 0; l--)
        {
            fator = matriz_a[l][c] / matriz_a[c][c];
            
            for (int x = 0; x < n; x++)
            {
                matriz_a[l][x] -= matriz_a[c][x] * fator;

                inversa[l][x] -= inversa[c][x] * fator;
            }
        }
    }
    
    //Laco que escreve o resultado no ponteiro da matriz externa
    for (int l = 0; l < n; l++)
    {
    	for(int c = 0; c < n; c++)
		{
            *acs(n, l, c, p_matriz_resultado) = inversa[l][c];
        }
	}

    return True;
}

void transposta_matriz(int n_linhas, int n_colunas, double * p_matriz_a, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_colunas x n_linhas)
    */

    // Declaracao das variaveis
    double matriz_a[n_linhas][n_colunas];
    double transposta[n_colunas][n_linhas];

    //Laco que recebe os valores e os escreve em matrizes locais
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
            matriz_a[l][c] = *acs(n_colunas, l, c, p_matriz_a);
        }
    }
    
    //Laco que realiza a operacao achar a transposta
    for (int l = 0; l < n_linhas; l++)
	{ 
        for (int c = 0 ; c < n_colunas; c++)
		{
			transposta[c][l] = matriz_a[l][c];
		}
	}

    //Laco que escreve o resultado no ponteiro da matriz externa
    for (int l = 0; l < n_colunas; l++)
    {
    	for(int c = 0; c < n_linhas; c++)
		{
            *acs(n_linhas, l, c, p_matriz_resultado) = transposta[l][c];
        }
	}
}
