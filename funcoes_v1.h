double * acs(int n_colunas, int linha, int coluna, double * matriz)
{
    return matriz + linha - n_colunas + coluna;
}

/*
acessar o elemento l, c de uma matriz dada por double * matriz_x com n_colunas:
    *acs(n_colunas, l, c, matriz_x)
*/

void somar_matrizes(int n_linhas, int n_colunas, double * matriz_a, double * matriz_b, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_b (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */
   //Soma[c][l]=*acs(n_colunas, l, c, matriz_a)+*acs(n_colunas, l, c, matriz_b);
    // código
    int j=0;
    double Soma[n_linhas][n_colunas];
    double Matriz1[n_linhas][n_colunas];
    double Matriz2[n_linhas][n_colunas];
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
            Matriz2[i][j] = *acs(n_colunas, i, j, matriz_b);
        }
        j++;
    }
    int *i=0;
    j=0;
    //Laço que realiza a soma
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Soma[i][j] = Matriz1[i][j]+Matriz2[i][j];
        }
        j++;
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
    int j=0;
    int i=0;
    double Matriz1[n_linhas][n_colunas];
    double Matriz2[n_linhas][n_colunas];
    double ResultadoSubtracao[n_linhas][n_colunas];
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
            Matriz2[i][j] = *acs(n_colunas, i, j, matriz_b);
        }
        j++;
    }
    i=0;
    j=0;
    //Laço que realiza a soma
    while(j<n_colunas){
        for(i=0;i<n_linhas;i++){
            ResultadoSubtracao[i][j] = Matriz1[i][j]-Matriz2[i][j];
        }
        j++;
    }
    
}

void produto_escalar_matriz(int n_linhas, int n_colunas, double * matriz_a, double escalar, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // código
    int j=0;
    double Matriz1[n_linhas][n_colunas];
    double Matriz2[n_linhas][n_colunas];
    double ResultadoMultiEscalar[n_linhas][n_colunas];
    
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
        }
        j++;
    }
    j=0;
    int i=0;
    //Laço que realiza a multiplicação
    while(j<n_colunas){
        for(i=0;i<n_linhas;i++){
            ResultadoMultiEscalar[i][j] = (Matriz1[i][j])*escalar;
        }
        j++;
    }


}

void produto_matrizes(int n_linhas, int n_colunas, int n_intermediario, double * matriz_a, double * matriz_b, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_intermediario)
    tamanho da matriz_b (n_intermediario x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */

    // código
    double ponte=0;
    int j=0;
    int colunas=0;
    double Matriz1[n_linhas][n_intermediario];
    double Matriz2[n_intermediario][n_colunas];
    double Resultado[n_linhas][n_colunas];
    //Trans
    while(j<n_intermediario){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
        }
        j++;
    }
    j=0;

    while(j<n_colunas){
        for(int i=0;i<n_intermediario;i++){
            Matriz2[i][j] = *acs(n_colunas, i, j, matriz_b);
        }
        j++;
    }
    //Acaba aqui
    //Varia coluna e linha
    /*
    A[2][3] 2 2 2
            2 2 2

    A[2][3] 2 2 
            2 2
            3 3
    */
    
    int x = 0;
    int i = 0;
    j =0;
    while(i<n_colunas || j<n_colunas){
        for(x=0;x<n_intermediario||x<n_intermediario;x++){
            ponte += Matriz1[i][x] * Matriz2[x][j];    
        }
        Resultado[i][j]= ponte;
        j++;
        if(j==n_colunas){
            i++;
            j=0;
        }
    }
    



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