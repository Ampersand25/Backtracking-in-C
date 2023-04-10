#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <assert.h>
#include <windows.h>

typedef enum{false, true} bool; // tip de data enumerat cu doua nume simbolice de constante: false (0) si true (1)
typedef struct {
	unsigned a, b; // a, b - campurile/componetele structurii (descriu proprietatile/atributele entitatii)
} pereche; // tip de data structurat cu structura fixa care incapsuleaza doua atribute de tip intreg fara semn (unsigned), ci anume campurile a si b

bool ePrim(unsigned); // prototipul functiei operand (de tip rezultat) ePrim
pereche descompunereSumaPrime(unsigned); // prototipul subrutinei (functiei) descompunereSumaPrime

void test_ePrim()
{
	// Functie de test (White Box Testing = Metoda Cutiei Transparente)
	// pentru functia (subrutina) ePrim

	// Prima ramura de executie: n == 2
	assert(ePrim(2) == true);

	// A doua ramura de executie: n <= 1 sau n par (si diferit de 2) 
	assert(ePrim(-1) == false);
	assert(ePrim(0) == false);
	assert(ePrim(1) == false);
	assert(ePrim(4) == false);
	assert(ePrim(6) == false);
	assert(ePrim(8) == false);
	assert(ePrim(10) == false);
	assert(ePrim(12) == false);
	assert(ePrim(14) == false);

	// A treia ramura de executie: n impar si compus (nu este prim <=> are divizori proprii)
	assert(ePrim(9) == false);
	assert(ePrim(15) == false);
	assert(ePrim(21) == false);
	assert(ePrim(25) == false);
	assert(ePrim(27) == false);

	// A patra ramura de executie: n par si prim
	assert(ePrim(3) == true);
	assert(ePrim(5) == true);
	assert(ePrim(7) == true);
	assert(ePrim(11) == true);
	assert(ePrim(13) == true);
}

void verificareGoldbach()
{
	// Procedura care verifica daca fiecare numar par din intervalul [4, 1e+5] (sau [4, 1e5])
	// poate fi descompus intr-o suma de doua numere prime,
	// adica daca este adevarata ipoteza lui Goldbach

	/*
	* Orice numar intreg par mai mare decat 3 poate fi scris ca suma de doua numere prime
	*/

	pereche p;
	for (unsigned i = 4; i <= 1e+5; i += 2) // 1e+5 == 10 la puterea 5 (sau +5)
	{
		p = descompunereSumaPrime(i);
		assert(p.a != -1 && p.b != -1); // assert(p.a != -1);
		                                // assert(p.b != -1);
	}
}

void test_descompunereSumaPrime()
{
	// Functie de test (Blcak Box Testing = Metoda Cutiei Negre)
	// pentru functia (subrutina) descompunereSumaPrime

	pereche p;

	p = descompunereSumaPrime(4);
	assert(p.a == 2 && p.b == 2);
	
	p = descompunereSumaPrime(6);
	assert(p.a == 3 && p.b == 3);
	
	p = descompunereSumaPrime(8);
	assert(p.a == 3 && p.b == 5);
	
	p = descompunereSumaPrime(10);
	assert(p.a == 3 && p.b == 7);
	
	p = descompunereSumaPrime(12);
	assert(p.a == 5 && p.b == 7);
	
	p = descompunereSumaPrime(14);
	assert(p.a == 3 && p.b == 11);

	verificareGoldbach();
}

void testare()
{
	// Procedura (functie procedurala, adica de tip void)
	// care apeleaza la randul ei alte proceduri de testare
	// pentru fiecare din functiile de tip operand (rezultat) din aplicatie 

	test_ePrim(); // testarea functiei ePrim
	test_descompunereSumaPrime(); // testarea functiei descompunereSumaPrime
}

void validare_n(unsigned n)
{
	// Procedura care valideaza daca datele de intrare sunt valide (adica daca respecta preconditiile)
	// (preconditii = restrictii impuse asupra datelor de intrare)
	// Date de intrare: n - intreg
	// Preconditii: n trebuie sa fie un intreg fara semn (unsigned)
	// Date de iesire (rezultate): -
	// Procedura arunca eroare daca n nu este un numar par (adica in cazul cand n este impar)
	// sau daca n este mai mic sau egal cu 2

	assert(n > 2 && !(n % 2)); // assert(n >= 3 && n % 2 == 0);
}

void citire_n(unsigned* pn)
{
	// Procedura care citeste un intreg fara semn (unsigned) pe 4 bytes/octeti de la tastatura
	// si modifica (suprascrie) valoarea zonei de memorie la care pointeaza/puncteaza pointerul pn
	// Date de intrare: pn (pointer n) - pointer legat la/de tipul de data unsigned
	// Preconditii: -
	// Date de iesire (rezultate): - 

	printf("n = ");
	scanf_s("%u", pn);  // nu mai trebuie &pn deoarece pn este adresa de memorie (pointer)
	// validare_n(*pn); // *pn - dereferentierea pointerului pn (operatorul unar * extrage valoarea unui pointer)
}

bool ePrim(unsigned n)
{
	// Functie operand (de tip rezultat) care valideaza primalitatea unui numar intreg fara semn (unsigned = natural)
	// Cu alte cuvinte, functia verifica daca un numar n dat ca parametru este sau nu prim
	// Date de intrare: n - intreg fara semn
	// Preconditii: -
	// Date de iesire (rezultate): bool (tip de data structurat), adica false (constanta 0) sau true (constanta 1)
	// Postconditii: functia returneaza true daca n este prim (nu are divizori proprii, doar improprii (pe 1 si el insusi))
	// si false in caz contrar (daca n este neprim/compus, adica are cel putin un divizor propriu (divizor diferit de 1 si de n))

	if (n == 2)
		return true;
	if (n <= 1 || !(n % 2))
		return false;
	for (unsigned div = 3; div * div <= n; div += 2)
		if (!(n % div))
			return false;
	return true;
}

bool ePrimGeneric(unsigned n, bool (*func)(unsigned))
{
	// Functie generica care verifica daca un numar n dat ca si argument/parametru de intrare este sau nu prim
	// Date de intrare: n    - intreg fara semn (unsigned), adica numar natural
	//                  func - pointer la o functie
	// Preconditii: -
	// Date de iesire (rezultate): bool (tip de data structurat cu structura fixa definit de catre utilizator)
	// Postconditii: true (1)  - n este prim (nu are divizori proprii, doar improprii (adica pe 1 si pe el insusi))
	//               false (0) - n nu este prim (este compus, adica are divizori proprii diferiti de 1 si de el insusi)

	return func(n);
}

pereche descompunereSumaPrime(unsigned n)
{
	// Functie care incearca descompunerea unui numar natural n in suma de doua numere prime
	// Date de intrare: n - intreg fara semn (unsigned)
	// Preconditii: n trebuie sa fie > 2 (>= 3) si par (n % 2 == 0)
	// Date de iesire (rezultate): p - variabila de tip de data structurat (pereche) 
	// Postconditii: p.a + p.b == n cu p.a si p.b numere prime, daca n poate fi descompus ca suma de doua numere prime
	//               p.a == p.b == -1, otherwise (in caz contrar)

	validare_n(n); // validam datele de intrare (verificam daca sunt satisfacute preconditiile)
	pereche p = { -1, -1 };
	#define ternary(a, b, c) ((a) ? (b) : (c))
	for (unsigned i = 2; i <= (n >> 1); i = ternary(i == 2, 3, i + 2))
		if (ePrimGeneric(i, ePrim) && ePrimGeneric(n - i, ePrim))
		{
			p = (pereche){ i, n - i }; // p.a = i; p.b = n - i;
			break;
		}
	#undef ternary
	return p;
}

void afisare_meniu()
{
	// Procedura care afiseaza/tipareste meniul aplicatiei (adica toate comenzile disponibile pentru utilizator)
	// Date de intrare: -
	// Date de iesire (rezultate): -

	puts("Meniu aplicatie:"); // printf("Meniu aplicatie:\n");
	puts("1 - descompune un numar natural par, mai mare strict ca 2, intr-o suma de doua numere prime");
	puts("2 - tiparste triunghiul lui Pascal");
	puts("3 - curatare ecran (stergere continut terminal)");
	puts("4 - iesirea din aplicatie");
}

void optiune_1()
{
	// Procedura care afiseaza la stdout (standard output = iesirea standard) descompunerea unui numar citit
	// Date de intrare: -
	// Date de iesire (rezultate): -

	unsigned n;
	citire_n(&n);
	pereche p = descompunereSumaPrime(n);
	if (p.a == -1 && p.b == -1) // n nu poate fi descompus in suma de doua numere prime
		                        // if (p.a == -1)
		                        // if (p.b == -1)
		printf("Numarul %u nu poate fi descompus ca suma de doua numere prime!\n", n);
	else printf("%u = %u + %u\n", n, p.a, p.b);
}

typedef unsigned long long ullong;

ullong combs(unsigned m, unsigned k)
{
	// Functie operand (de tip rezultat) care calculeaza combinari de m luate cate k
	// Date de intrare: m - intreg fara semn (unsigned)
	//                  k - intreg fara semn (unsigned)
	// Preconditii: -
	// Date de iesire: unsigned long long (ullong)
	// Postconditii: fie prod rezultatul returnat de functie, prod reprezinta combinari de m luate cate k

	if (k > m - k)
		k = m - k;
	ullong prod = 1;
	for (ullong i = 1; i <= k; ++i)
		prod = prod * (m - k + i) / i;
	return prod;
}

void triunghiPascalFrumos(unsigned n)
{
	// Procedura care afiseaza primele n nivele din triunghiul lui Pascal
	// Date de intrare: n - intreg fara semn (unsigned)
	// Preconditii: -
	// Date de iesire (rezultate): -

	printf("\nTriunghiul lui Pascal cu %u nivele este:\n", n);
	for (unsigned m = 0, sp = n; m < n; ++m, --sp)
	{
		for (unsigned i = 0; i < sp; putchar(' '), ++i);
		for (unsigned k = 0; k <= m; ++k)
			printf("%6llu", combs(m, k));
		putchar('\n');
	}
}

void triunghiPascalClasic(unsigned n)
{
	// Procedura care afiseaza primele n nivele din triunghiul lui Pascal
	// Date de intrare: n - intreg fara semn (unsigned)
	// Preconditii: -
	// Date de iesire (rezultate): -

	printf("\nTriunghiul lui Pascal cu %u nivele este:\n", n);
	for (unsigned m = 0; m != n; ++m)
	{
		for (unsigned k = 0; k <= m; ++k)
			printf("%llu", combs(m, k));
		printf("\n");
	}
}

void triunghiPascal(unsigned n, void (*f)(unsigned))
{
	// Procedura care apeleaza procedura f data ca argument pentru parametrul formal/simbolic n de tip intreg
	// Date de intrare: n - intreg fara semn (unsigned), adica numar natural
	//                  f - pointer la o functie cu un singur parametru (argument) avand tipul de data unsigned
	// Preconditii: -
	// Date de iesire (rezultate): -

	f(n);
}

void optiune_2()
{
	// Procedura care afiseaza la stdout (standard output = iesirea standard)
	// primele n (n se citeste de la tastatura (stdin = standard input = intrarea standard)) nivele din triunghiul lui Pascal
	// Date de intrare: -
	// Date de iesire (rezultate): -

	unsigned n;
	printf("n = ");
	scanf_s("%u", &n);
	triunghiPascal(n, triunghiPascalFrumos);
}

void optiune_3()
{
	// Procedura care sterge intreg continutul de pe ecranul aplicatiei
	// Date de intrare: -
	// Date de iesire (rezultate): -

	// Varianta I
	/*
	system("CLS");
	afisare_meniu();
	*/

	// Varianta II
	eticheta:
	puts("Sunteti sigur ca doriti sa stergeti continutul afisat pe ecranul aplicatiei? [Y/N]");
	unsigned char op;
	scanf_s("\n%c", &op);
	if (toupper(op) == 'Y')
	{
		system("CLS"); // functie sistem din fisierul antet (header) windows.h care da clear la ecran/consola/terminal
		afisare_meniu();
		return;
	}
	if (toupper(op) == 'N')
		return;
	puts("Optiune invalida!\n");
	goto eticheta;
}

void optiune_4()
{
	// Procedura care incheie executia/rularea aplicatiei (executa terminarea programului)
	// Date de intrare: -
	// Date de iesire (rezultate): -
	
	// Varianta I
	/*
	exit(0);
	*/

	// Varianta II
	eticheta:
	puts("Sunteti sigur ca doriti sa iesiti din aplicatie? [Y/N]");
	unsigned char op;
	scanf_s("\n%c", &op);
	if (toupper(op) == 'Y')
		exit(0); // terminarea normala a programului (cu codul 0)
	if (toupper(op) == 'N')
		return;
	puts("Optiune invalida!\n");
	goto eticheta;
}

int main(void)
{
	/*
	* Enunt problema:
	* 14. Descompune un numar natural par, mai mare strict ca 2, intr-o suma
    de doua numere prime (verificarea ipotezei lui Goldbach).
	*/
	
	testare();
	afisare_meniu();
	while (1) // while (1 != 0)
	{
		printf("\n>>>");
		unsigned char cmd;
		scanf_s("%hhu", &cmd);
		switch (cmd)
		{
			case 1:
				optiune_1();
				break;
			case 2:
				optiune_2();
				break;
			case 3:
				optiune_3();
				break;
			case 4:
				optiune_4();
				break;
			default:
				puts("Optiune invalida!");
				break;
		}
	}
	// return 0; // exit(0);
}