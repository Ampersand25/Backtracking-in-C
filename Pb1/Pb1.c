#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

unsigned char* alocare(unsigned n)
{
    unsigned char* mem = (unsigned char*)calloc(n, sizeof(unsigned char));
    if (mem == NULL)
    {
        perror("Nu s-a putut aloca memorie pe heap!");
        exit(-1);
    }
    return mem;
}

void dezalocare(void* mem)
{
    free(mem);
}

void precalculareCiur(unsigned char* compus, unsigned lim)
{
    for(unsigned long long i = 3; i < lim; i += 2)
        if (!compus[i])
        {
            unsigned long long div = 2;
            while (i * div < lim)
            {
                compus[i * div] = 1;
                ++div;
            }
        }
}

void precalculareCiurOptimizat(unsigned char* compus, unsigned lim)
{
    for (unsigned long long i = 3; i * i < lim; i += 2)
        if (!compus[i])
            for (unsigned long long p = i * i; p < lim; p += i)
                compus[p] = 1;
}

void afisare_meniu_comenzi()
{
	puts("Meniu comenzi aplicatie:");
	puts("1 - genereaza numere prime mai mici decat un numar natural dat");
	puts("2 - iesirea din aplicatie");
}

unsigned char eprim(unsigned el, unsigned char* compus)
{
    if (el == 2)
        return 1;
    if (el <= 1 || !(el % 2))
        return 0;
    return !compus[el];
}

void numerePrime(unsigned n, unsigned char* compus)
{
    for (unsigned i = 2; i < n; i = (i == 2 ? 3 : i + 2))
        if (eprim(i, compus))
            printf("%u,", i);
    puts("\b.");
}

void comanda_1(unsigned char* compus)
{
    unsigned n;
    printf("n = ");
    scanf_s("%u", &n);
    if (n <= 2)
        printf("Nu exista numere prime mai mici strict decat %u\n", n);
    else {
        printf("Numerele prime mai mici strict decat %u sunt: ", n);
        numerePrime(n, compus);
    }
}

void comanda_2(unsigned char* compus)
{
    dezalocare(compus);
    exit(0);
}

int main()
{
	/*
	* 1. Genereaza numere prime mai mici decat un numar natural dat.
	*/

    afisare_meniu_comenzi();
    #define lim 1e+5
    unsigned char* compus = alocare((unsigned)lim);
    precalculareCiur(compus, (unsigned)lim);
    while (1)
    {
        unsigned cmd;
        printf("\n>>>");
        scanf_s("%u", &cmd);
        if (cmd == 1)
        {
            comanda_1(compus);
            continue;
        }
        if (cmd == 2)
        {
            comanda_2(compus);
            continue;
        }
        puts("Comanda invalida!");
    }
}