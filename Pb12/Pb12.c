#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "functii.h"

void afisare_meniu_comenzi()
{
	puts("Meniu comenzi aplicatie:");
	puts("1 - determina valoarea x^n (x este un numar real dat, n este un numar natural dat)");
	puts("2 - iesirea din aplicatie");
}

float citire_float()
{
	float a;
	scanf_s("%f", &a);
	return a;
}

unsigned citire_unsigned()
{
	unsigned a;
	scanf_s("%u", &a);
	return a;
}

void comanda_1()
{
	printf("x = ");
	float x = citire_float();
	printf("n = ");
	unsigned n = citire_unsigned();
	printf("%.2f\n", generic_power(x, n, power4));
}

void comanda_2()
{
	exit(0);
}

int main(void)
{
	/*
	* 12. Determina valoarea x^n (x este un numar real dat, n este un numar natural 
	dat), utilizand operatii de inmultire si de ridicare la patrat.
	*/

	afisare_meniu_comenzi();
	while (1)
	{
		unsigned cmd;
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