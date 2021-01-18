#include <iostream>

#include "ListyJednokierunkowe.h"
#include "StosyKolejki.h"
#include "ListyCykliczneDwukierunkowe.h"

void testListaJednokierunkowa()
{
	using namespace ListaJ;

	std::cout << "Listy jednokierunkowe" << std::endl;
	std::cout << "Dodanie 5 elementow do listy jednokierunkowej" << std::endl;
	elem* lista = nullptr;
	insert(5, 1, lista);
	insert(3, 2, lista);
	insert(6, 3, lista);
	insert(7, 4, lista);
	insert(9, 5, lista);
	print(lista);

	std::cout << std::endl << "Usuniecie 3. elementu" << std::endl;
	remove(3, lista);
	print(lista);

	std::cout << std::endl << "Odczytanie 2. elementu: ";
	std::cout << read(2, lista) << std::endl;

	std::cout << "Wielkosc listy: ";
	std::cout << size(lista) << std::endl;

	std::cout << "Lista wypisana odwrotnie" << std::endl;
	printReverseStack(lista);
	std::cout << " - z pomoca stosu" << std::endl;
	printReverse(lista);
	std::cout << " - bez dodatkowych struktur" << std::endl;

	std::cout << "Wypisanie adresu elementu o wartosci 3: ";
	std::cout << search(3, lista) << std::endl;
}

void testListaWielomianowa()
{
	using namespace ListaPoly;

	std::cout << "Dodawanie wielomianu" << std::endl;
	elem* poly1 = nullptr;
	append(3, 2, poly1);
	append(2, -4, poly1);
	append(1, 7, poly1);
	print(poly1);
	std::cout << " + ";
	elem* poly2 = nullptr;
	append(4, 2, poly2);
	append(2, -2, poly2);
	append(1, 10, poly2);
	print(poly2);
	std::cout << " = ";
	print(polyadd(poly1, poly2));
}

void testListaFareya()
{
	using namespace ListaFarey;

	std::cout << std::endl << "Lista Fareya 5. stopnia" << std::endl;
	print(ulamekFareya(5));
	std::cout << std::endl;
}

void testStos()
{
	using namespace Stos;

	std::cout << std::endl << "Stosy i kolejki" << std::endl;
	std::cout << "Dodanie do stosu elementow [3, 4, 2, 1]" << std::endl;
	elem* stos = nullptr;
	push(stos, 3);
	push(stos, 4);
	push(stos, 2);
	push(stos, 1);

	std::cout << "Pobranie 2 wartosci ze stosu: ";
	std::cout << pop(stos) << " ";
	std::cout << pop(stos) << std::endl;

	std::cout << "Zwrocenie wartosci z wierzcholka stosu: ";
	std::cout << topEl(stos) << std::endl;

	std::cout << "Sekwencja z zadania 4: ";
	sequence();

	std::cout << std::endl << "Dodanie do kolejki, zlozonej z 2 stosow, elementow [3, 4, 2, 1] i wypisanie pierwszych dwoch elementow" << std::endl;
	elem* kolStos1 = nullptr;
	elem* kolStos2 = nullptr;
	add(kolStos1, 3);
	add(kolStos1, 4);
	add(kolStos1, 2);
	add(kolStos1, 1);
	std::cout << next(kolStos1, kolStos2) << " ";
	std::cout << next(kolStos1, kolStos2) << std::endl;

	std::cout << "Dodanie do stosu elementow [3, 4, 2, 1] i odwrocenie go" << std::endl;
	destroy(stos);
	push(stos, 3);
	push(stos, 4);
	push(stos, 2);
	push(stos, 1);

	elem* tempStos = nullptr;
	copy(stos, tempStos);
	print(tempStos);
	std::cout << "- stos bez zmian" << std::endl;

	reverseWithStack(tempStos);
	print(tempStos);
	std::cout << "- stos odwrocony z pomoca stosu" << std::endl;

	destroy(tempStos);
	copy(stos, tempStos);
	reverseWithQueue(tempStos);
	print(tempStos);
	std::cout << "- stos odwrocony z pomoca kolejki" << std::endl;

	std::cout << "Posortowanie stosu" << std::endl;
	sort(stos);
	print(stos);
}

void testKolejka()
{
	using namespace Kolejka;

	std::cout << std::endl << "Dodanie do kolejki elementow [3, 4, 2, 1]" << std::endl;
	elem* kolStart = nullptr;
	elem* kolKoniec = nullptr;
	add(kolStart, kolKoniec, 3);
	add(kolStart, kolKoniec, 4);
	add(kolStart, kolKoniec, 2);
	add(kolStart, kolKoniec, 1);

	std::cout << "Pobranie 2 wartosci z kolejki: ";
	std::cout << next(kolStart, kolKoniec) << " ";
	std::cout << next(kolStart, kolKoniec) << std::endl;

	std::cout << "Zwrocenie wartosci z poczatku kolejki: ";
	std::cout << firstEl(kolStart) << std::endl;

	std::cout << "Sekwencja z zadania 3: ";
	sequence();

	std::cout << std::endl << "Dodanie do kolejki, zlozonej z tablicy, elementow [3, 4, 2, 1] i wypisanie pierwszych 2 elementow" << std::endl;
	int* tab = new int[15];
	int head = 0, tail = -1;
	add(tab, 15, tail, 3);
	add(tab, 15, tail, 4);
	add(tab, 15, tail, 2);
	add(tab, 15, tail, 1);
	std::cout << next(tab, 15, head) << " ";
	std::cout << next(tab, 15, head) << std::endl;
}

void testListaCyklicznaIDwukierunkowa()
{
	using namespace ListaCD;

	std::cout << std::endl << "Listy cykliczne i dwukierunkowe" << std::endl;
	std::cout << "Dodanie do listy elementow [5, 4, 7, 8], usuniecie 2. elementu i odwrocenie pozostalej czesci" << std::endl;
	elem* lista = nullptr;
	insert(5, 1, lista);
	insert(4, 2, lista);
	insert(7, 3, lista);
	insert(8, 4, lista);
	print(lista);
	std::cout << std::endl;
	remove(2, lista);
	print(lista);
	std::cout << std::endl;
	reverse(lista);
	print(lista);

	std::cout << std::endl << "Sprawdzenie wyrazen NP" << std::endl;
	elem* wyrazenieNP1 = nullptr;
	insert('+', 1, wyrazenieNP1);
	insert('a', 2, wyrazenieNP1);
	insert('b', 3, wyrazenieNP1);
	insert('/', 4, wyrazenieNP1);
	insert('c', 5, wyrazenieNP1);
	std::cout << "+ab/c - " << ((is_valid_pn(wyrazenieNP1)) ? "Poprawne" : "Niepoprawne") << std::endl;
	elem* wyrazenieNP2 = nullptr;
	insert('*', 1, wyrazenieNP2);
	insert('a', 2, wyrazenieNP2);
	insert('b', 3, wyrazenieNP2);
	insert('c', 4, wyrazenieNP2);
	insert('/', 5, wyrazenieNP2);
	std::cout << "*abc/ - " << ((is_valid_pn(wyrazenieNP2)) ? "Poprawne" : "Niepoprawne") << std::endl;
}

int main()
{
	testListaJednokierunkowa();
	testListaWielomianowa();
	testListaFareya();

	testStos();
	testKolejka();

	testListaCyklicznaIDwukierunkowa();

	return 0;
}