#include <iostream>

#include "ListyJednokierunkowe.h"
#include "StosyKolejki.h"

//Zadanie 1
void ListaJ::insert(int x, int i, elem*& a)
{
	if (i == 1)
	{
		elem* newElem = new elem{ x, a };
		a = newElem;
	}
	else
	{
		elem* tempElem = a;
		for (int j = 0; j < i - 2; ++j)
			tempElem = tempElem->nast;

		elem* newElem = new elem{ x, tempElem->nast };
		tempElem->nast = newElem;
	}
}

void ListaJ::remove(int i, elem*& lista)
{
	elem* tempElem = lista;
	if (i == 1)
	{
		lista = lista->nast;
		delete tempElem;
	}
	else
	{
		for (int j = 0; j < i - 2; ++j)
		{
			tempElem = tempElem->nast;
		}

		elem* rmElem = tempElem->nast;
		tempElem->nast = rmElem->nast;
		delete rmElem;
	}
}

int ListaJ::read(int i, elem* lista)
{
	if (i == 1)
		return lista->dane;
	else
	{
		for (int j = 0; j < i - 1; ++j)
			lista = lista->nast;
		return lista->dane;
	}
}

//Zadanie 2
int ListaJ::size(elem* lista)
{
	int count = 0;
	for (; lista; lista = lista->nast)
		++count;
	return count;
}

//Zadanie 3
void ListaJ::print(elem* lista)
{
	for (; lista; lista = lista->nast)
		std::cout << lista->dane << " ";
}

//Zadanie 4
void ListaJ::printReverseStack(elem* lista)
{
	Stos::elem* stack = nullptr;
	for (; lista; lista = lista->nast)
		Stos::push(stack, lista->dane);
	while (!Stos::isEmpty(stack))
		std::cout << Stos::pop(stack) << " ";
}

//Zadanie 5
void ListaJ::printReverse(elem* lista)
{
	if (lista->nast)
		printReverse(lista->nast);
	std::cout << lista->dane << " ";
}

//Zadanie 6
void ListaJ::destroy(elem*& lista)
{
	if (lista->nast)
		destroy(lista->nast);
	delete lista;
	lista = nullptr;
}

//Zadanie 7
ListaJ::elem* ListaJ::search(int x, elem* lista)
{
	for (; lista->dane != x; lista = lista->nast);
	return lista;
}

//Funkcje pomocnicze do zadania 8
void ListaPoly::append(int expo, float coef, elem*& a)
{
	if (!a)
	{
		a = new elem{ expo, coef, nullptr };
	}
	else
	{
		elem* tempElem = a;
		while (tempElem->nast)
			tempElem = tempElem->nast;

		tempElem->nast = new elem{ expo, coef, nullptr };
	}
}

void ListaPoly::print(elem* a)
{
	while (a)
	{
		std::cout << ((a->coef >= 0) ? "+" : "") << a->coef << "x^" << a->expo;
		a = a->nast;
	}
}

//Zadanie 8
ListaPoly::elem* ListaPoly::polyadd(elem* l1, elem* l2)
{
	elem* poly = nullptr;
	while (true)
	{
		if (l1 != nullptr && l2 != nullptr && l1->expo == l2->expo)
		{
			ListaPoly::append(l1->expo, l1->coef + l2->coef, poly);
			l1 = l1->nast;
			l2 = l2->nast;
		}
		else if (l2 == nullptr || (l1 != nullptr && l1->expo > l2->expo))
		{
			ListaPoly::append(l1->expo, l1->coef, poly);
			l1 = l1->nast;
		}
		else
		{
			ListaPoly::append(l2->expo, l2->coef, poly);
			l2 = l2->nast;
		}

		if (l1 == nullptr && l2 == nullptr)
			return poly;
	}
}

//Funkcje pomocnicze do zadania 9
void ListaFarey::insert(int a, int b, int i, elem*& lista)
{
	if (i == 1)
	{
		lista = new elem{ a, b, lista };
	}
	else
	{
		elem* tempElem = lista;
		for (int j = 0; j < i - 2; ++j)
			tempElem = tempElem->nast;

		elem* newElem = new elem{ a, b, tempElem->nast };
		tempElem->nast = newElem;
	}
}

ListaFarey::elem* ListaFarey::read(int i, elem* lista)
{
	for (int j = 0; j < i - 1; ++j)
		lista = lista->nast;

	return lista;
}

void ListaFarey::print(elem* lista)
{
	while (lista)
	{
		std::cout << lista->a << "/" << lista->b << " ";
		lista = lista->nast;
	}
}

//Zadanie 9
ListaFarey::elem* ListaFarey::ulamekFareya(int n)
{
	elem* fareyList = new elem{ 0, 1, new elem{ 1, 1, nullptr } };
	int i = n;
	while (i - 1 > 0)
	{
		elem* tempList = fareyList;
		while (true)
		{
			if (tempList->b + tempList->nast->b <= n)
			{
				insert(tempList->a + tempList->nast->a, tempList->b + tempList->nast->b, 2, tempList);
				tempList = tempList->nast->nast;
			}
			else
				tempList = tempList->nast;
			if (!tempList->nast)
				break;
		}
		i--;
	}
	return fareyList;
}