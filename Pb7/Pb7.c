#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void afisare_meniu_comenzi()
{
    puts("Meniu comenzi aplicatie:");
    puts("1 -  calculeaza o valoare aproximativa a radacinii patrate a unui numar real pozitiv, cu o precizie data");
    puts("2 - iesirea din aplicatie");
}

long double divideEtImpera(long double x, long double left, long double right, long double epsilon)
{
    if (fabs(left - right) < epsilon) // trivial problem
        return left; // return right
    long double mid = (left + right) / 2; // divide
    // long double mid = (left + right) / 2.0;
    if (mid * mid < x)
        return divideEtImpera(x, mid, right, epsilon); // conquer (impera)
    if (mid * mid > x)
        return divideEtImpera(x, left, mid, epsilon); // conquer (impera)
    return divideEtImpera(x, mid, mid, epsilon); // conquer (impera)
}

long double square_root(long double x, long double epsilon)
{
    return divideEtImpera(x, 0, x, epsilon);
}

void comanda_1()
{
    long double x, epsilon;
    printf("Dati numarul: ");
    scanf_s("%Lf", &x);
    epsilon = 1e-15;
    printf("Dati precizia radacinii patrate: ");
    scanf_s("%Lf", &epsilon);
    printf("Radacina patrata a numarului %Lf cu o precizie de %.16Lf este %Lf\n", x, epsilon, square_root(x, epsilon));
}

void comanda_2()
{
    exit(0);
}

int main(void)
{
    /*
    * 7. Calculeaza o valoare aproximativa a radacinii patrate a unui numar
    real pozitiv, cu o precizie data.
    */

    afisare_meniu_comenzi();
    while (1)
    {
        unsigned short cmd;
        puts("");
        printf(">>>");
        scanf_s("%hu", &cmd);
        if (cmd == 1)
            comanda_1();
        else if (cmd == 2)
            comanda_2();
        else puts("Comanda invalida!");
    }
}