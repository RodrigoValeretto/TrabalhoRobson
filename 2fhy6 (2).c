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

void quick_sort(struct AUX *l, int ini, int fim) {
    int i=ini, j;
    struct AUX aux;
    // particionamento de Loreto (pivo = l->vet[fim])
    for (j=ini; j<fim; j++) //1 + n + 1 + n 
    {
        if (l[j].inv < l[fim].inv) { // 5
            // troca l->vet[i] por l->vet[j]
            aux = l[i];
            l[i] = l[j];
            l[j] = aux;
            i++; // mais um elemento menor do que o pivo
        }else // 7
        {
            if(l[j].inv == l[fim].inv)
            {
                if(l[j].id < l[fim].id)
                {
                    aux = l[i];
                    l[i] = l[j];
                    l[j] = aux;
                    i++;
                }
            }
        }
    }
    aux = l[fim]; //1
    l[fim] = l[i];//1
    l[i] = aux;   //1
    if (ini < i-1)
        quick_sort(l, ini, i-1); // processa metade inferior
    if (i+1 < fim)
        quick_sort(l, i+1, fim); // processa metade superior
    return;
}

int bubble_sort(struct entrada *l, int h) {
    int i, cont = 0, iteracao = 0, ordenado = 0; //3 atrib
    int aux;
    while (!ordenado) {   // aprox n rodagens + n*(for)
        ordenado = 1; // assume que esta ordenado, a principio  //1 atrib
        for (i=0; i < h - iteracao - 1; i++) //1 atrib + n+1 comp + n incr + n*9
            if (l->hobbies[i] > l->hobbies[i+1]) { // 9
                // efetua troca
                ordenado = 0; // precisa de nova iteracao
                aux = l->hobbies[i];
                l->hobbies[i] = l->hobbies[i+1];
                l->hobbies[i+1] = aux;
                cont++;
            }
        iteracao++; // +1
    }
    return cont; //+1
}

int *solucao(struct entrada *entradas, int n, int h)
{
    int *ret = (int *) malloc(h * sizeof(int)); // 1 atrib
    struct AUX l[n];
    
    for (int i = 0; i < n; i++) //1 atrib + n+1 comp + n incrementos + n*(1 + B(T))
    {
        l[i].inv = bubble_sort(&entradas[i], h); // 1 atrib
        l[i].id = entradas[i].usuario_id; // 1 atrib
    }

    quick_sort(l,0,n-1); // complexidade do quick sort

    for(int i = 0; i<n ; i++) //1 atrib + n+1 comp + n incrementos
        ret[i] = l[i].id;    //n atrib

    return ret; //+1
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
