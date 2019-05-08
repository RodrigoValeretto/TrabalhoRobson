#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int id;
    int a, l, c;
};

struct Aux {
    int vol;
    int id;
};

void quick_sort_vol(struct Aux *l, int ini, int fim) {   //Essa [REDACTED] que nós temos que analisar.
    int i=ini, j;
    struct Aux aux;
    for (j=ini; j<fim; j++)    // for que roda do inicio até o fim então é n + 1 vezes se tamanho do vet = n e n incrementos, 1 atrib;
        if (l[j].vol < l[fim].vol) { // Valor do if : 1 comp + 3 atrib + 1 incremento = 5;
            // troca l->vet[i] por l->vet[j]
            aux = l[i];
            l[i] = l[j];
            l[j] = aux;
            i++; // mais um elemento menor do que o pivo
        }
        else //Total else = 7;
        {
            if(l[j].vol == l[fim].vol)  // 1 comp
            {
                if(l[j].id > l[fim].id) // 1 comp + 3 atrib + 1 incr;
                {
                    aux = l[i];
                    l[i] = l[j];
                    l[j] = aux;
                    i++;
                }
            }
        }
    aux = l[fim]; // 1 atrib
    l[fim] = l[i]; // 1 atrib
    l[i] = aux; // 1 atrib
    if (ini < i-1) // 1 comp
        quick_sort_vol(l, ini, i-1); // processa metade inferior // chamada quicksort = x
    if (i+1 < fim) // 1 comp
        quick_sort_vol(l, i+1, fim); // processa metade superior // chamada quicksort = x
    return; // 1 retorno
}

int* solucao(struct entrada *entradas, int n, int p)
{
    int *ret = (int *) malloc(p * sizeof(int));
    struct Aux l[n];
    int k;

    for (k=0; k < n; k++) // n+1 comp, n incrementos, 1 atrib, roda n vezes?
    {
        l[k].id = entradas[k].id; // 1 atrib
        l[k].vol = (entradas[k].a * entradas[k].l * entradas[k].c); // 2 multiplicações, 1 atrib
    }

    quick_sort_vol(l,0,n-1); // Custo total quicksort = medio, pesado

    for(int x=0,k = n-1 ; k > n-1-p ; k--,x++) // n+1 + 1 + 1 + n + n + n
        ret[x] = l[k].id; // 1 atrib

    return ret; // 1 retorno
}

int main()
{
    int *ret;
    int t, i, j;
    int T, N, P, ID, A, L, C;

    scanf("%d", &T);

    for (t = 0; t < T; t++) {

        scanf("%d %d", &N, &P);

        struct entrada *entradas = (struct entrada *) malloc(N * sizeof(struct entrada));
        for (i = 0; i < N; i++) {
            scanf("%d %d %d %d", &entradas[i].id, &entradas[i].a, &entradas[i].l, &entradas[i].c);
        }
        
        ret = solucao(entradas, N, P);

        for (i = 0; i < P; i++)
            if (i + 1 < P)
                printf("%d ", ret[i]);
            else
                printf("%d\n", ret[i]);
    }

    return 0;
}