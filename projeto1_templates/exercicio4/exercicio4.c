#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int *itens;
    int *consultas;
};

int* solucao(struct entrada entrada, int n, int c)
{
    int *ret = (int *) malloc(c * sizeof(int));
    
    // Implemente aqui sua solução
    // Para as consultas, caso o item não exista, retorne -1

    return ret;
}

int main()
{
    int *ret;
    int t, i;
    int T, N, C;

    scanf("%d", &T);

    for (t = 1; t <= T; t++) {

        scanf("%d %d", &N, &C);

        struct entrada entrada;
        entrada.itens = (int *) malloc(N * sizeof(int));
        entrada.consultas = (int *) malloc(C * sizeof(int));

        scanf("%d", &entrada.itens[0]);
        for (i = 1; i < N; i++) {
            scanf(" %d", &entrada.itens[i]);
        }
        
        scanf("%d", &entrada.consultas[0]);
        for (i = 1; i < C; i++) {
            scanf(" %d", &entrada.consultas[i]);
        }

        ret = solucao(entrada, N, C);

        for (i = 0; i < C; i++) {
            if (ret[i] >= 0) 
                printf("Caso %d, item %d na posicao %d.\n", t, entrada.consultas[i], ret[i]);
            else
                printf("Caso %d, item %d nao existe.\n", t, entrada.consultas[i]);

        }
    }

    return 0;
}