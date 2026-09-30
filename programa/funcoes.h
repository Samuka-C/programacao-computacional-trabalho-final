#include <stdio.h>

enum 
{
    False,
    True
};

double * acs(int n_colunas, int linha, int coluna, double * matriz)
{
    return matriz + linha * n_colunas + coluna;
}

/*
acessar o elemento l, c de uma matriz dada por double * matriz_x com n_colunas:
    *acs(n_colunas, l, c, matriz_x)
*/

/*
void output_matriz_alt(int n_linhas, int n_colunas, double * matriz)
{
    int max[n_colunas];
    int sizes[n_linhas][n_colunas];

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
*/

double somar_matrizes(int n_linhas, int n_colunas, double * matriz_a, double * matriz_b, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_b (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_linhas x n_colunas)
    */
    // código

    // Declaração das variaveis
    int j=0;
    double Soma[n_linhas][n_colunas];
    double Matriz1[n_linhas][n_colunas];
    double Matriz2[n_linhas][n_colunas];
    //Laço que recebe os valores e os escreve em matrizes locais
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
            Matriz2[i][j] = *acs(n_colunas, i, j, matriz_b);
        }
        j++;
    }
    int i=0;
    j=0;

    //Laço que realiza a soma
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Soma[i][j] = Matriz1[i][j]+Matriz2[i][j];
        }
        j++;
    }

    //Laço que retorna o valor para o vetor resultado
    j=0;
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            *acs(n_colunas, i, j, matriz_resultado)=Soma[i][j];
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

    // Declaração das variaveis
    int j=0;
    int i=0;
    double Matriz1[n_linhas][n_colunas];
    double Matriz2[n_linhas][n_colunas];
    double ResultadoSubtracao[n_linhas][n_colunas];

    //Laço que recebe os valores e os escreve em matrizes locais
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
            Matriz2[i][j] = *acs(n_colunas, i, j, matriz_b);
        }
        j++;
    }
    i=0;
    j=0;

    //Laço que realiza a subtração
    while(j<n_colunas){
        for(i=0;i<n_linhas;i++){
            ResultadoSubtracao[i][j] = (Matriz1[i][j])-(Matriz2[i][j]);
        }
        j++;
    }
    j=0;

    //Laço que retorna o valor para o vetor resultado
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            *acs(n_colunas, i, j, matriz_resultado)=ResultadoSubtracao[i][j];
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
    // Declaração das variaveis
    int j=0;
    double Matriz1[n_linhas][n_colunas];
    double Matriz2[n_linhas][n_colunas];
    double ResultadoMultiEscalar[n_linhas][n_colunas];

    //Laço que recebe os valores e os escreve em matrizes locais
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
    j=0;

    //Laço que retorna o valor para o vetor resultado
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            *acs(n_colunas, i, j, matriz_resultado)=ResultadoMultiEscalar[i][j];
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
    // Declaração das variaveis
    double ponte=0;
    int j=0;
    int colunas=0;
    double Matriz1[n_linhas][n_intermediario];
    double Matriz2[n_intermediario][n_colunas];
    double Resultado[n_linhas][n_colunas];

    //Laço que recebe os valores e os escreve em matrizes locais
    while(j<n_intermediario){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_intermediario, i, j, matriz_a);
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
    //Variaveis de controle
    int x = 0;
    int i = 0;
    j =0;

    //Laço que realiza a multiplicação das matrizes
    while(i<n_colunas || j<n_colunas){
        for(x=0;x<n_intermediario;x++){
            ponte += Matriz1[i][x] * Matriz2[x][j];  
            /* Apenas para testes
            if(j==0){  
                printf("%.2lf \n",ponte);
            };
            */
        }
        //Imprime o valor de cada elemento no resultado
        Resultado[i][j] = ponte;
        ponte=0;

        //Realiza o controle do laço
        if(j==n_colunas){
            i++;
            j=0;
        }else{
            j++;
        }
        
    }
    j=0;

    //Laço que retorna o valor para o vetor resultado
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            *acs(n_colunas, i, j, matriz_resultado)=Resultado[i][j];
        }
        j++;
    }
    



}

double determinante_matriz(int n, double * p_matriz_a)
{
    /*
    tamanho da matriz_a (n x n)
    */

    // preencher a matriz_a
    double matriz_a[n][n];
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            matriz_a[l][c] = *acs(n, l, c, p_matriz_a);
        }
    }

    // redução gaussina
    for (int c = 0; c < n; c++)
    {
        /*
        printf( MAGENTA "A:\n\n");
        output_matriz_alt(n, n, &(matriz_a[0][0]));
        printf( CYAN "\n");
        printf("I:\n\n");
        output_matriz_alt(n, n, &(matriz_i[0][0]));
        printf(NORMAL "\n");
        */

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
                    for (int c2 = 0; c2 < n; c2++)
                    {
                        matriz_a[c][c2] += matriz_a[l][c2];
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

            for (int c2 = 0; c2 < n; c2++)
            {
                matriz_a[l][c2] -= matriz_a[c][c2] * fator;
            }
        }
    }

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

    // preencher a matriz_a
    double matriz_a[n][n];
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            matriz_a[l][c] = *acs(n, l, c, p_matriz_a);
        }
    }

    // criar uma matriz indentidade
    double matriz_i[n][n];
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            if (l == c)
            {
                matriz_i[l][c] = 1;
            }
            else
            {
                matriz_i[l][c] = 0;
            }
        }
    }

    // redução gaussina
    for (int c = 0; c < n; c++)
    {
        /*
        printf( MAGENTA "A:\n\n");
        output_matriz_alt(n, n, &(matriz_a[0][0]));
        printf( CYAN "\n");
        printf("I:\n\n");
        output_matriz_alt(n, n, &(matriz_i[0][0]));
        printf(NORMAL "\n");
        */

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
                    for (int c2 = 0; c2 < n; c2++)
                    {
                        matriz_a[c][c2] += matriz_a[l][c2];

                        matriz_i[c][c2] += matriz_i[l][c2];
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

            for (int c2 = 0; c2 < n; c2++)
            {
                matriz_a[l][c2] -= matriz_a[c][c2] * fator;

                matriz_i[l][c2] -= matriz_i[c][c2] * fator;
            }
        }
    }

    // redução gauss-jordan
    for (int c = n - 1; c >= 0; c--)
    {
        /*
        printf( MAGENTA "A:\n\n");
        output_matriz_alt(n, n, &(matriz_a[0][0]));
        printf( CYAN "\n");
        printf("I:\n\n");
        output_matriz_alt(n, n, &(matriz_i[0][0]));
        printf(NORMAL "\n");
        */

        double fator = 1 / matriz_a[c][c];

        for (int c2 = 0; c2 < n; c2++)
        {
            matriz_a[c][c2] *= fator;

            matriz_i[c][c2] *= fator;
        }

        for (int l = c - 1; l >= 0; l--)
        {
            fator = matriz_a[l][c] / matriz_a[c][c];
            
            for (int c2 = 0; c2 < n; c2++)
            {
                matriz_a[l][c2] -= matriz_a[c][c2] * fator;

                matriz_i[l][c2] -= matriz_i[c][c2] * fator;
            }
        }
    }

    // escrever o resultado
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            *acs(n, l, c, p_matriz_resultado) = matriz_i[l][c];
        }
    }

    return True;
}

void transposta_matriz(int n_linhas, int n_colunas, double * matriz_a, double * matriz_resultado)
{
    /*
    tamanho da matriz_a (n_linhas x n_colunas)
    tamanho da matriz_resultado (n_colunas x n_linhas)
    */

    // código
    //Declaração de variaveis
    int i = 0, j=0;
    double Matriz1[n_linhas][n_colunas];
    double MatrizResultado[n_colunas][n_linhas];

    //Laço que recebe os valores e os escreve em matrizes locais
    while(j<n_colunas){
        for(int i=0;i<n_linhas;i++){
            Matriz1[i][j] = *acs(n_colunas, i, j, matriz_a);
        }
        j++;
    }
    j=0,i=0;
    //Laço que realiza a operação de trasporte
    for(i=0;i<n_linhas;i++){
        for(j=0;j<n_colunas;j++){
            MatrizResultado[j][i] = Matriz1[i][j];
        }
    }

    j=0,i=0;

    //Laço que retorna o valor para o vetor resultado
    while(j<n_linhas){
        for(int i=0;i<n_colunas;i++){
            *acs(n_colunas, i, j, matriz_resultado)=MatrizResultado[i][j];
        }
        j++;
    }

}

// boa sorte :D