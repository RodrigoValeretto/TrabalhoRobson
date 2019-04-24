#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int x, y, z, w;
};

struct AUX{
    int insc;
    int pontos;
    int cestasfeitas;
    int cestastomadas;
    float media;
};

void quick_sort(struct AUX *l, int ini, int fim) {
    int i=ini, j;
    struct AUX aux;
    // particionamento de Loreto (pivo = l->vet[fim])
    for (j=ini; j<fim; j++)
    {
        if (l[j].pontos > l[fim].pontos) {
            // troca l->vet[i] por l->vet[j]
            aux = l[i];
            l[i] = l[j];
            l[j] = aux;
            i++; // mais um elemento menor do que o pivo
        }else
        {
            if(l[j].pontos == l[fim].pontos)
            {
                if(l[j].media > l[fim].media)
                {
                    aux = l[i];
                    l[i] = l[j];
                    l[j] = aux;
                    i++;
                }else
                {
                    if(l[j].media == l[fim].media)
                    {
                        if(l[j].cestasfeitas > l[fim].cestastomadas)
                        {
                            aux = l[i];
                            l[i] = l[j];
                            l[j] = aux;
                            i++;
                        }
                    }else
                    {
                        if(l[j].cestasfeitas == l[j].cestastomadas)
                        {
                            if(l[j].insc < l[fim].insc)
                            {
                                aux = l[i];
                                l[i] = l[j];
                                l[j] = aux;
                                i++;
                            }
                        }
                    }

                }
            }
        }
    }
    aux = l[fim];
    l[fim] = l[i];
    l[i] = aux;
    if (ini < i-1)
        quick_sort(l, ini, i-1); // processa metade inferior
    if (i+1 < fim)
        quick_sort(l, i+1, fim); // processa metade superior
    return;
}

int *solucao(struct entrada *entradas, int m, int n_teams)
{
    int *ret = (int *) malloc(n_teams * sizeof(int));
    int i = 0, j = 0;
    struct AUX *aux = (struct AUX *)calloc(n_teams,sizeof(struct AUX));

   for(j=0 ;j < m; j++)
    {
        aux[(entradas[j].x)-1].insc = entradas[j].x;
        aux[(entradas[j].x)-1].cestasfeitas = entradas[j].y;
        aux[(entradas[j].x)-1].cestastomadas = entradas[j].w;

        aux[(entradas[j].z)-1].insc = entradas[j].z;
        aux[(entradas[j].z)-1].cestasfeitas = entradas[j].w; 
        aux[(entradas[j].z)-1].cestastomadas = entradas[j].y; 

        if(entradas[j].y > entradas[j].w)
        {
            aux[(entradas[j].x)-1].pontos += 2;
            aux[(entradas[j].z)-1].pontos += 0; 
        }

        if(entradas[j].y < entradas[j].w)
        {
            aux[(entradas[j].x)-1].pontos += 0;
            aux[(entradas[j].z)-1].pontos += 2; 
        }

        if(entradas[j].y == entradas[j].w)
        {
            aux[(entradas[j].x)-1].pontos += 0;
            aux[(entradas[j].z)-1].pontos += 0;
        }
    }

    for(j = 0; j < n_teams; j++)
    {
        if(aux[j].cestastomadas)
            aux[j].media = aux[j].cestasfeitas/aux[j].cestastomadas;
        else
            aux[j].media = aux[j].cestasfeitas;

    }

    quick_sort(aux,0,n_teams-1);

    for(j = 0; j < n_teams; j++)
        ret[j] = aux[j].insc;

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
