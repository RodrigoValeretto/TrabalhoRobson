#include <stdio.h>
#include <stdlib.h>

int merge_sort_recursivo(int *l, int ini, int fim) {
    int l1, l2, lc;
    int meio;
    int cont=0;
    int aux[fim + 1];
    if (ini == fim) // criterio de parada
        return 0; // vetor com um soh elemento
    // ordena metades inferior e superior
    meio = ini + (fim-ini)/2;
    cont += merge_sort_recursivo(l,ini,meio); // metade inferior
    cont += merge_sort_recursivo(l,meio+1,fim); // metade superior
    // faz o merge das listas
    l1 = lc = ini;
    l2 = meio+1;
    while ( l1 <= meio && l2 <= fim)
        //aux[lc++] = (l[l1] < l[l2]) ? l[l1++] : l[l2++];
        {
        	if (l[l1] <= l[l2]) {
                aux[lc] = l[l1];
                l1++;
            } else {
                aux[lc] = l[l2];
                l2++;

                cont += meio - l1 + 1;
            }
            lc++;
        }

    for (; l1 <= meio; l1++, lc++)
        aux[lc] = l[l1];
    for (; l2 <= fim; l2++, lc++)
        aux[lc] = l[l2];
    // passa a copia ordenada sobre o vetor original
    for (lc=ini; lc<=fim; lc++) {
        l[lc] = aux[lc]; 
    }

    return cont;
}

int solucao(int *arr, int n)
{

	int ret = merge_sort_recursivo(arr, 0 , n-1);

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