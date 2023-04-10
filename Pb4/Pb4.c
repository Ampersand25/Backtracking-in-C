#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 - determina primele n cifre din scrierea fractiei subunitare k / m = 0.c1c2c3..., pentru k si m numere naturale date");
    puts("2 - iesirea din aplicatie");
}

void citire(unsigned* ptr)
{
    scanf_s("%u", ptr);
}

void func(unsigned n, unsigned k, unsigned m)
{
    assert(k < m);
    if (!n)
        return;
    printf("Primele %u cifre din scriere fractiei subunitare %u / %u sunt: 0.", n, k, m);
    for(; n; --n)
    {
        k *= 10;
        printf("%u", k / m);
        k %= m;
    }
    printf("\n");
}

void comanda_1()
{
    unsigned n, k, m;
    printf("n = ");
    citire(&n);
    printf("k = ");
    citire(&k);
    printf("m = ");
    citire(&m);
    func(n, k, m);
}

void comanda_2()
{
    exit(0);
}

int main(void)
{
	/*
    * 4. Determina primele n cifre din scrierea fractiei subunitare
    k/m = 0.c1c2c3..., pentru k si m numere naturale date.
    */

    afisare_meniu_comenzi();
    while (1)
    {
        unsigned int cmd;
        putchar('\n');
        printf(">>>");
        scanf_s("%u", &cmd);
        if (cmd == 1)
            comanda_1();
        else if (cmd == 2)
            comanda_2();
        else puts("Comanda invalida!");
    }
}