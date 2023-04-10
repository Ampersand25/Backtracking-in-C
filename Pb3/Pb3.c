#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 - determina toate reprezentarile posibile a unui numar natural ca suma de numere naturale consecutive");
    puts("2 - iesirea din aplicatie");
}

unsigned char descompunereSumaConsecutive(int n)
{
    assert(n >= 0);
    int lim = n / 2 - !(n % 2);
    unsigned char gasit = 0;
    for (int i = 1; i <= lim; ++i)
    {
        int j = i + 1, sum = i;
        for (; sum < n && j <= n / 2; sum += j++);
        if (sum == n)
        {
            if (!gasit)
            {
                gasit = 1;
                printf("Descompunerile numarului %d in sume de numere consecutive sunt:\n", n);
            }
            for (int k = i; k <= j - 1; printf("%d+", k++));
            printf("\b \n");
        }
    }
    return gasit;
}

void comanda_1()
{
    int n;
    printf("n = ");
    scanf_s("%d", &n);
    unsigned char exista = descompunereSumaConsecutive(n);
    if (!exista)
        printf("Numarul %d nu poate fi descompus intr-o suma de numere consecutive!\n", n);
}

void comanda_2()
{
    exit(0);
}

int main(void)
{
    /*
    * 3. Determina toate reprezentarile posibile a unui numar natural ca suma
    de numere naturale consecutive.
    */

    afisare_meniu_comenzi();
    while (1)
    {
        int cmd;
        printf("\n>>>");
        scanf_s("%d", &cmd);
        if (cmd == 1)
        {
            comanda_1();
            continue;
        }
        if (cmd == 2)
        {
            comanda_2();
            continue;
        }
        puts("Comanda invalida!");
    }
}