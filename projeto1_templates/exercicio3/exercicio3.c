#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int x, y, z, w;
};

int *solucao(struct entrada *entradas, int m, int n_teams)
{
    int *ret = (int *) malloc(n_teams * sizeof(int));

    // Implemente aqui sua solução

    return ret;
}

int main()
{
    int *ret;
    int t, i, j;
    int T, N;

    scanf("%d", &T);

    for (t = 0; t < T; t++) {

        scanf("%d", &N);

        int m = (int) (N * (N - 1)/2);
        struct entrada *entradas = (struct entrada *) malloc(m * sizeof(struct entrada));
        for (i = 0; i < m; i++) {
            scanf("%d %d %d %d", &entradas[i].x, &entradas[i].y, &entradas[i].z, &entradas[i].w);
        }

        ret = solucao(entradas, m, N);

        printf("Caso de teste %d\n", t);
        for (i = 0; i < N; i++)
            if (i + 1 < N)
                printf("%d ", ret[i]);
            else
                printf("%d\n", ret[i]);
    }

    return 0;
}
