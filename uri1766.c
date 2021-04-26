#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rena
{
    char nome[100];
    int peso;
    int idade;
    float altura;

} Rena;

void criaHeap(Rena *vet, int i, int f)
{
    Rena aux;
    aux.peso = vet[i].peso;
    aux.idade = vet[i].idade;
    aux.altura = vet[i].altura;
    strcpy(aux.nome, vet[i].nome);

    int j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            if (vet[j].peso < vet[j + 1].peso)
            {
                j = j + 1;
            }
            else if (vet[j].peso == vet[j + 1].peso)
            {
                if (vet[j].idade > vet[j + 1].idade)
                {
                    j = j + 1;
                }
            }

            else if (vet[j].peso == vet[j + 1].peso && vet[j].idade == vet[j + 1].idade)
            {
                if (vet[j].altura > vet[j + 1].altura)
                {
                    j = j + 1;
                }
            }

            else if (vet[j].peso == vet[j + 1].peso && vet[j].idade == vet[j + 1].idade && vet[j].altura == vet[j + 1].altura)
            {
                if (vet[j].nome > vet[j + 1].nome)
                {
                    j = j + 1;
                }
            }
        }
        if (aux.peso < vet[j].peso)
        {
            vet[i].peso = vet[j].peso;
            vet[i].idade = vet[j].idade;
            vet[i].altura = vet[j].altura;
            strcpy(vet[i].nome, vet[j].nome);

            i = j;
            j = 2 * i + 1;
        }

        else if (aux.peso == vet[j].peso)
        {
            if (aux.idade > vet[j].idade)
            {
                vet[i].peso = vet[j].peso;
                vet[i].idade = vet[j].idade;
                vet[i].altura = vet[j].altura;
                strcpy(vet[i].nome, vet[j].nome);

                i = j;
                j = 2 * i + 1;
            }
        }

        else if (aux.peso == vet[j].peso && aux.idade == vet[j].idade)
        {
            if (aux.altura > vet[j].altura)
            {
                vet[i].peso = vet[j].peso;
                vet[i].idade = vet[j].idade;
                vet[i].altura = vet[j].altura;
                strcpy(vet[i].nome, vet[j].nome);

                i = j;
                j = 2 * i + 1;
            }
        }

        else if (aux.peso == vet[j].peso && aux.idade == vet[j].idade && aux.altura == vet[j].altura)
        {
            if (aux.nome > vet[j].nome)
            {
                vet[i].peso = vet[j].peso;
                vet[i].idade = vet[j].idade;
                vet[i].altura = vet[j].altura;
                strcpy(vet[i].nome, vet[j].nome);

                i = j;
                j = 2 * i + 1;
            }
        }

        else
        {
            j = f + 1;
        }
    }
    vet[i].peso = aux.peso;

    vet[i].idade = aux.idade;
    vet[i].altura = aux.altura;
    strcpy(vet[i].nome, aux.nome);
}

void heapSort(Rena *vet, int n)
{
    Rena aux;
    int i;
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        criaHeap(vet, i, n - 1);
    }

    for (i = n - 1; i >= 1; i--)
    {
        aux.peso = vet[0].peso;
        aux.idade = vet[0].idade;
        aux.altura = vet[0].altura;
        strcpy(aux.nome, vet[0].nome);

        vet[0].peso = vet[i].peso;
        vet[0].idade = vet[i].idade;
        vet[0].altura = vet[i].altura;
        strcpy(vet[0].nome, vet[i].nome);

        vet[i].peso = aux.peso;
        vet[i].idade = aux.idade;
        vet[i].altura = aux.altura;
        strcpy(vet[i].nome, aux.nome);

        criaHeap(vet, 0, i - 1);
    }
}

int main(void)
{
    int n_testes;
    scanf("%d", &n_testes);

    for (int a = 1; a <= n_testes; a++)
    {
        int total_renas, total_renas_treno, cont = 1;
        scanf("%d %d", &total_renas, &total_renas_treno);
        int dif = total_renas - total_renas_treno;

        Rena renas[total_renas];

        for (int b = total_renas; b > 0; b--)
        {
            scanf("%s %d %d %f", &renas[b].nome, &renas[b].peso, &renas[b].idade, &renas[b].altura);
        }

        heapSort(&renas, total_renas);

        printf("CENARIO {%d}\n", a);
        for (int b = total_renas; b > dif; b--)
        {

            printf("%d - %s\n", cont, renas[b].nome);
            cont++;
        }
    }
}
