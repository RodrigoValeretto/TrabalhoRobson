#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int *itens;
    int *consultas;
};


void merge_sort(struct entrada *l, int ini, int fim) {
    int l1, l2, lc;
    int meio;
    int aux[10000];
    if (ini == fim) // criterio de parada
        return; // vetor com um soh elemento
    // ordena metades inferior e superior
    meio = ini + (fim-ini)/2;
    merge_sort(l,ini,meio); // metade inferior
    merge_sort(l,meio+1,fim); // metade superior
    // faz o merge das listas
    l1 = lc = ini;
    l2 = meio+1;
    while ( l1 <= meio && l2 <= fim)
        aux[lc++] = (l->itens[l1] < l->itens[l2]) ? l->itens[l1++] : l->itens[l2++];
    for (; l1 <= meio; l1++, lc++)
        aux[lc] = l->itens[l1];
    for (; l2 <= fim; l2++, lc++)
        aux[lc] = l->itens[l2];
    // passa a copia ordenada sobre o vetor original
    for (lc=ini; lc<=fim; lc++) {
        l->itens[lc] = aux[lc];
    }
    return;
}


int buscabinaria(struct entrada l, int ini, int fim, int x)
{	
	if(fim >= 0)
	{
		int meio = (ini + fim)/2;

		if (l.itens[meio] == x)
			return meio;
		
		if(l.itens[meio] > x)
			return buscabinaria(l, 0, meio - 1, x);
		if(meio + 1 <= fim)	
			return buscabinaria(l, meio + 1, fim, x);
	}

	return (-1);
}


int* solucao(struct entrada entrada, int n, int c)
{
    int *ret = (int *) malloc(c * sizeof(int));
    
    merge_sort(&entrada, 0, n-1);

    for(int i = 0; i < c; i++)
    	ret[i] = buscabinaria(entrada, 0, n-1, entrada.consultas[i]);

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