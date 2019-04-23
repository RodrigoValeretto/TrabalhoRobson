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

void quick_sort_vol(struct Aux *l, int ini, int fim) {
    int i=ini, j;
    struct Aux aux;
    // particionamento de Loreto (pivo = l->vet[fim])
    for (j=ini; j<fim; j++)
        if (l[j].vol < l[fim].vol) {
            // troca l->vet[i] por l->vet[j]
            aux = l[i];
            l[i] = l[j];
            l[j] = aux;
            i++; // mais um elemento menor do que o pivo
        }
    aux = l[fim];
    l[fim] = l[i];
    l[i] = aux;
    if (ini < i-1)
        quick_sort_vol(l, ini, i-1); // processa metade inferior
    if (i+1 < fim)
        quick_sort_vol(l, i+1, fim); // processa metade superior
    return;
}

void quick_sort_id(struct Aux *l, int ini, int fim) {
    int i=ini, j;
    struct Aux aux;
    // particionamento de Loreto (pivo = l->vet[fim])
    for (j=fim; j>ini; j--)
        if (l[j].id > l[ini].id) {
            // troca l->vet[i] por l->vet[j]
            aux = l[i];
            l[i] = l[j];
            l[j] = aux;
            i++; // mais um elemento menor do que o pivo
        }
    aux = l[fim];
    l[fim] = l[i];
    l[i] = aux;
    if (ini < i-1)
        quick_sort_id(l, ini, i-1); // processa metade inferior
    if (i+1 < fim)
        quick_sort_id(l, i+1, fim); // processa metade superior
    return;
}

int* solucao(struct entrada *entradas, int n, int p)
{
    int *ret = (int *) malloc(p * sizeof(int));
    struct Aux l[n];
    int k;

    for (k=0; k < n; k++)
    {
        l[k].id = entradas[k].id;
        l[k].vol = (entradas[k].a * entradas[k].l * entradas[k].c);
    }

    quick_sort_vol(l,0,n-1);

    int i = 0;
    for (k = 0; k < n; k++)
    {
        if(l[k].vol < l[k+1].vol)
            {
                quick_sort_id(l,i,k);
                i=k+1;
            }

    }


    for(int x=0,k = n-1 ; k > n-1-p ; k--,x++)
        ret[x] = l[k].id;

    return ret;
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