#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 - descompune in factori primi un numar natural nenul dat");
    puts("2 - iesirea din aplicatie");
}

void descompunereFactoriPrimi(unsigned n)
{
    assert(n); // assert(n != 0);
    unsigned d = 2;
    printf("\nDescompunerea lui %u in factori primi este:\n%u = ", n, n);
    while (n != 1)
    {
        unsigned p = 0;
        while (!(n % d))
        {
            n /= d;
            ++p;
        }
        if (p)
        {
            printf("(%u ^ %u)", d, p);
            if (n != 1)
                printf(" * ");
        }
        d = (d == 2 ? 3 : d + 2);
    }
    puts("");
}

void comanda_1()
{
    unsigned n;
    printf("n = ");
    scanf_s("%u", &n);
    descompunereFactoriPrimi(n);
}

void comanda_2()
{
    exit(0);
}

int main(void)
{
    /*
    * 13. Descompune in factori primi un numar natural nenul dat.
    */

    afisare_meniu_comenzi();
    while (1)
    {
        unsigned char cmd;
        putchar('\n');
        printf(">>>");
        scanf_s("\n%c", &cmd);
        if (cmd == '1')
            comanda_1();
        else if (cmd == '2')
            comanda_2();
        else puts("Comanda invalida!");
    }
}