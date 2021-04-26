#include <stdio.h>
#include <stdlib.h>

typedef struct Rena
{
    char nome[100];
    int peso;
    int idade;
    float altura;

} Rena;


int main(void)
{
    int n_testes;
    scanf("%d", &n_testes);

    for (int a = n_testes; a > 0; a--)
    {
        int total_renas, total_renas_treno;
        scanf("%d %d", &total_renas, &total_renas_treno);

        Rena renas[total_renas];

        for (int b = total_renas; b > 0; b--)
        {
            scanf("%s %d %d %f", &renas[b].nome, &renas[b].peso, &renas[b].idade, &renas[b].altura);
        }
    }
}
