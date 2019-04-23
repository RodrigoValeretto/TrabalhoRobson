#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int usuario_id;
    int *hobbies;
};

struct AUX
{
	int inv;
	int id;
};


int bubble_sort(struct entrada *l, int h) {
    int i, cont = 0, iteracao = 0, ordenado = 0;
    int aux;
    while (!ordenado) {
        ordenado = 1; // assume que esta ordenado, a principio
        for (i=0; i < h - iteracao - 1; i++)
            if (l->hobbies[i] > l->hobbies[i+1]) {
                // efetua troca
                ordenado = 0; // precisa de nova iteracao
                aux = l->hobbies[i];
                l->hobbies[i] = l->hobbies[i+1];
                l->hobbies[i+1] = aux;
                cont++;
            }
        iteracao++;
    }
    return cont;
}

int *solucao(struct entrada *entradas, int n, int h)
{
    int *ret = (int *) malloc(h * sizeof(int));
    struct AUX l[n];
    
    for (int i = 0; i < n; i++)
    {
    	l[i].inv = bubble_sort(&entradas[i], h);
    	l[i].id = entradas[i].usuario_id;
    }

	for(int i = 0; i<n ; i++)
		ret[i] = l[i].id;    

    return ret;
}

int main()
{
    int *ret;
    int t, i, j;
    int T, N, H;

    scanf("%d", &T);

    for (t = 0; t < T; t++) {

        scanf("%d %d", &N, &H);
        
        struct entrada *entradas = (struct entrada *) malloc(N * sizeof(struct entrada));

        for (i = 0; i < N; i++) {
            entradas[i].hobbies = (int *) malloc(H * sizeof(int));
            scanf("%d", &entradas[i].usuario_id);
            for (j = 0; j < H; j++)
                scanf(" %d", &entradas[i].hobbies[j]);
        }

        ret = solucao(entradas, N, H);

        for (i = 0; i < N; i++)
            if (i + 1 < N)
                printf("%d ", ret[i]);
            else
                printf("%d\n", ret[i]);
    }

    return 0;
}
