#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 - determina toate numerele naturale mai mici decat un numar naturtal nenul dat n si care sunt relativ prime cu n");
    puts("2 - iesirea din aplicatie");
}

unsigned gcd(unsigned a, unsigned b)
{
    /*
    if (!b)
        return a;
    return gcd(b, a % b);
    */

    #define ternary(a, b, c) ((a) ? (b) : (c))
    return ternary(!b, a, gcd(b, a % b)); // return (!b) ? a : gcd(b, a % b);
    #undef ternary
}

unsigned gcd_2(unsigned a, unsigned b)
{
    // Varianta iterativa
    while (a != b)
        if (a > b)
            a -= b;
        else b -= a;
    return a; // return b;

    // Varianta recursiva (recurenta)
    /*
    if (a == b)
        return a; // return b;

    // return (a > b) ? gcd_2(a - b, b) : gcd_2(a, b - a);
    
    if (a > b)
        return gcd_2(a - b, b);
    return gcd_2(a, b - a);
    */
}

unsigned generic_gcd(unsigned a, unsigned b, unsigned (*cmmdc)(unsigned, unsigned))
{
    return cmmdc(a, b);
}

typedef enum { false, true } bool;

bool suntCoprime(unsigned a, unsigned b)
{
    return generic_gcd(a, b, gcd) == 1;
}

void coprime(unsigned n)
{
    printf("Numerele coprime (relativ prime) cu numarul %u sunt: ", n);
    for (unsigned i = 1; n != 1 ? i < n : i <= 1; i += (!(n % 2) ? 2 : 1))
        if (suntCoprime(n, i)) // if(suntCoprime(n, i) == true) sau if(suntCoprime(n, i) == 1)
                               // if(suntCoprime(n, i) != false) sau if(suntCoprime(n, i) != 0)
            printf("%u,", i);
    printf("\b \n");
}

void comanda_1()
{
    unsigned n;
    printf("n = ");
    scanf_s("%u", &n);
    assert(n != 0); // assert(n);
    coprime(n);
}

void comanda_2()
{
    exit(0);
}

int main(void)
{
    /*
    * 16. Determina toate numerele naturale mai mici decat un numar naturtal
    nenul dat n si care sunt relativ prime cu n.
    */

    afisare_meniu_comenzi();
    while (1)
    {
        printf("\n>>>");
        unsigned short cmd;
        scanf_s("%hu", &cmd);
        if (cmd == 1)
            comanda_1();
        else if (cmd == 2)
            comanda_2();
        else printf("Comanda invalida!\n");
    }
}