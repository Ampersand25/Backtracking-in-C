#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 - citeste un sir de numere naturale nenule terminat cu 0 si determina numarul cifrelor 0 in care se termina numarul produs al numerelor citite.");
    puts("2 - iesirea din aplicatie");
}

unsigned long long produsElementeSir(unsigned* arr)
{
    unsigned long long produs = *arr; // produs = arr[0]; sau produs = 0[arr];
    for (unsigned i = 1; i[arr]; produs *= arr[i++]);
    return produs;
}

unsigned short noLeadingZeros(unsigned long long n)
{
    unsigned short cont = 0;
    while (!(n % 10))
    {
        n /= 10;
        ++cont;
    }
    return cont;
}

unsigned* alocare_memorie()
{
    unsigned* arr = (unsigned*)calloc(1e+8, sizeof(unsigned));
    // unsigned* arr = (unsigned*)malloc(1e8 * sizeof(unsigned));
    if (arr == NULL)
    {
        perror("Heap Overflow: Nu s-a putut aloca memorie in mod dinamic pe heap!");
        exit(1);
    }
    return arr;
}

void dezalocare_memorie(void* arr) // void dezalocare_memorie(unsigned* arr)
{
    free(arr);
}

void comanda_1()
{
    unsigned* arr = alocare_memorie();
    for (unsigned i = 0; ; ++i)
    {
        scanf_s("%u", arr + i); // scanf_s("%u", &arr[i]);
        if (!(*(arr + i))) // if(!arr[i])
            break;
    }
    // for (unsigned i = 0; *(arr + i); printf("%u ", i[arr++]));
    unsigned long long prod = produsElementeSir(arr);
    printf("Produsul termenilor din vectorul citit este egal cu %llu\n", prod);
    printf("Aceasta valoare se termina in %hu zerouri (valori de 0)!\n", noLeadingZeros(prod));
    dezalocare_memorie(arr);
}

void comanda_2()
{
    exit(0);
}

int main()
{
    /*
    * 9. Citeste un sir de numere naturale nenule terminat cu 0 si determina
    numarul cifrelor 0 in care se termina numarul produs al numerelor citite.
    */

    afisare_meniu_comenzi();
    while (!0)
    {
        unsigned short cmd;
        printf("\n>>>");
        scanf_s("%hu", &cmd);
        switch (cmd)
        {
            case 1:
                comanda_1();
                break;
            case 2:
                comanda_2();
                break;
            default:
                puts("Comanda invalida!");
        }
    }
}