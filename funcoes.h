double * acs(int n_colunas, int linha, int coluna, double * matriz)
{
    return matriz + linha * n_colunas + coluna;
}

/*
acessar o elemento l, c de uma matriz dada por double * matriz_x com n_colunas:
    *acs(n_colunas, l - 1, c - 1, matriz_x)
*/

void somar_matrizes(int n_linhas, int n_colunas, double * p_matriz_a, double * p_matriz_b, double * p_matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_b (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    double matriz_a[n_linhas][n_colunas];
    double matriz_b[n_linhas][n_colunas];

    for (int l = 0; l < n_linhas; l++)
    {
        for (int c = 0; c < n_colunas; c++)
        {
            matriz_a[l][c] = *acs(n_colunas, l, c, p_matriz_a);
            matriz_b[l][c] = *acs(n_colunas, l, c, p_matriz_b);
        }
    }

    double matriz_resultado[n_linhas][n_colunas];

    // código

    for (int l = 0; l < n_linhas; l++)
    {
        for (int c = 0; c < n_colunas; c++)
        {
            *acs(n_colunas, l, c, p_matriz_resultado) = matriz_resultado[l][c];
        }
    }
}

void subtracao_matrizes(int n_linhas, int n_colunas, double * matriz_a, double * matriz_b, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_b (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // código
}

void produto_escalar_matriz(int n_linhas, int n_colunas, double * matriz_a, double escalar, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // código
}

void produto_matrizes(int n_linhas, int n_colunas, int n_intermediario, double * matriz_a, double * matriz_b, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_intermediario)
    tamanho da matriz_b (n_intermediario x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // código
}

double determinante_matriz(int n, double * matriz_a)
{
    /*
    tamanho da matriz_a (n x n)
    */

    // código
}

void matriz_inversa(int n, double * matriz_a, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n x n)
    tamanho da matriz_resultado (n x n)
    */

    // código
}

void transposta_matriz(int n_linhas, int n_colunas, double * matriz_a, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_colunas x n_linhas)
    */

    // código
}

// boa sorte :D