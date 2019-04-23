#include <stdio.h>
#include <stdlib.h>

int solucao(int *arr, int n)
{
    // Implemente aqui sua solução

    int ret = 0; // Atribua aqui o número de inversões
    return ret;
}

int main()
{
    int t, i;
    int T, N, C;

    scanf("%d", &T);

    for (t = 1; t <= T; t++) {

        scanf("%d", &N);
        int *municao = (int *) malloc(N * sizeof(int));

        for (i = 0; i < N; i++) {
            scanf(" %d", &municao[i]);
        }
        
        int trocas = solucao(municao, N);

        if (trocas % 2 == 0) 
            printf("Total de trocas %d. Silva vai distribuir as caixas.\n", trocas);
        else
            printf("Total de trocas %d. Pereira vai distribuir as caixas.\n", trocas);
    }

    return 0;
}