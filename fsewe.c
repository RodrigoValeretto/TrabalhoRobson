#include <stdio.h>
#include <stdlib.h>

int merge_sort_recursivo(int *l, int ini, int fim) {
    int l1, l2, lc;
    int meio;
    int cont=0; //1 atrib
    int aux[fim + 1]; //1 op
    if (ini == fim) // criterio de parada //1 comp
        return 0; // vetor com um soh elemento //1 ret
    // ordena metades inferior e superior
    meio = ini + (fim-ini)/2; //1 atrib + 2 op
    cont += merge_sort_recursivo(l,ini,meio); // metade inferior // 1 op e 1 atrib + T(n/2)
    cont += merge_sort_recursivo(l,meio+1,fim); // metade superior // 1 op e 1 atrib + T(n/2)
    // faz o merge das listas
    l1 = lc = ini; //2 atrib
    l2 = meio+1; //1 atrib e 1 op
    while ( l1 <= meio && l2 <= fim) //2 comp roda aproximadamente n/2 vezes
        //aux[lc++] = (l[l1] < l[l2]) ? l[l1++] : l[l2++];
        {
            if (l[l1] <= l[l2]) { //1 comp + 1 atrib + 1 incremento
                aux[lc] = l[l1];
                l1++;
            } else { // 1 atrib e 1 incr
                aux[lc] = l[l2];
                l2++;

                cont += meio - l1 + 1; // 1 atrib + 3 op 
            }
            lc++; //1 incr
        }

    for (; l1 <= meio; l1++, lc++) //roda aprox n/2 vezes = n/2+1 comp + n/2 incr + n/2 inc  
        aux[lc] = l[l1]; //n/2 atrib
    for (; l2 <= fim; l2++, lc++) //roda aprox n/2 vezes = n/2+1 comp + n/2 incr + n/2 inc
        aux[lc] = l[l2]; //n/2 atrib
    // passa a copia ordenada sobre o vetor original
    for (lc=ini; lc<=fim; lc++) { //n+1 comp + 1 atrib + n inc
        l[lc] = aux[lc]; //n atrib
    }

    return cont; //1 ret
}

int solucao(int *arr, int n)
{

    int ret = merge_sort_recursivo(arr, 0 , n-1); // 1 atrib + T(n)

    return ret; 1 ret
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