#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 - tiparste triunghiul lui Pascal");
    puts("2 - iesirea din aplicatie");
}

typedef unsigned long long ullong;

ullong combs(unsigned m, unsigned k)
{
    if (k > m - k)
        k = m - k;
    ullong prod = 1;
    for (ullong i = 1; i <= k; ++i)
        prod = prod * (m - k + i) / i;
    return prod;
}

void triunghiPascalFrumos(unsigned n)
{
    printf("\nTriunghiul lui Pascal cu %u nivele este:\n", n);
    for (unsigned m = 0, sp = n; m < n; ++m, --sp)
    {
        for (unsigned i = 0; i < sp; putchar(' '), ++i);
        for (unsigned k = 0; k <= m; ++k)
            printf("%4llu", combs(m, k));
        putchar('\n');
    }
}

void triunghiPascalClasic(unsigned n)
{
    printf("\nTriunghiul lui Pascal cu %u nivele este:\n", n);
    for (unsigned m = 0; m != n; ++m)
    {
        for (unsigned k = 0; k <= m; ++k)
            printf("%4llu", combs(m, k));
        printf("\n");
    }
}

void triunghiPascal(unsigned n, void (*f)(unsigned))
{
    f(n);
}

void comanda_1()
{
    unsigned n;
    printf("n = ");
    scanf_s("%u", &n);
    triunghiPascal(n, triunghiPascalFrumos);
}

void comanda_2()
{
    exit(0);
}

int main(void)
{
	/*
	* 6. Tiparste triunghiul lui Pascal, cu toate combinarile C(m,k) de m obiecte
	luate cite k, k = 0, 1, ..., m, in linia m, pentru m = 1, 2, ..., n.
	*/

    afisare_meniu_comenzi();
    while (1)
    {
        unsigned cmd;
        putchar('\n');
        printf(">>>");
        scanf_s("\n%u", &cmd);
        if (cmd == 1)
            comanda_1();
        else if (cmd == 2)
            comanda_2();
        else printf("Comanda invalida!\n");
    }
}