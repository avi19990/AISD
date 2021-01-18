#include <iostream>

#include "ListyCykliczneDwukierunkowe.h"
#include "ListyJednokierunkowe.h"

//Funkcje pomocnicze
void ListaCD::print(elem* lista)
{
	while (lista)
	{
		std::cout << lista->dane << " ";
		lista = lista->nast;
	}
}

//Zadanie 1
void ListaCD::insert(int x, int i, elem*& a)
{
	if (i == 1)
	{
		a = new elem{ x, nullptr, a };
		if (a->nast)
			a->nast->poprz = a;
	}
	else
	{
		elem* tempElem = a;
		for (int j = 0; j < i - 2; ++j)
			tempElem = tempElem->nast;

		elem* newElem = new elem{ x, tempElem, tempElem->nast };

		if (tempElem->nast)
			tempElem->nast->poprz = newElem;
		tempElem->nast = newElem;
	}
}

void ListaCD::remove(elem*& lista)
{
	elem* tempElem = lista->nast;
	delete lista;
	lista = tempElem;
}

void ListaCD::remove(int i, elem*& lista)
{
	if (i == 1) remove(lista);
	else
	{
		elem* tempElem = lista;
		for (int j = 0; j < i - 1; ++j)
			tempElem = tempElem->nast;

		tempElem->poprz->nast = tempElem->nast;
		if (tempElem->nast)
			tempElem->nast->poprz = tempElem->poprz;

		delete tempElem;
	}
}

//Zadanie 2
void ListaCD::reverse(elem*& lista)
{
	elem* tempElem = lista;
	while (tempElem)
	{
		elem* nastElem = tempElem->nast;
		tempElem->nast = tempElem->poprz;
		tempElem->poprz = nastElem;

		if (!tempElem->poprz)
			lista = tempElem;

		tempElem = tempElem->poprz;
	}
}

//Zadanie 3
void ListaCD::to_cyclic(ListaJ::elem* lista)
{
	ListaJ::elem* tempList = lista;
	while (tempList->nast)
		tempList = tempList->nast;
	tempList->nast = lista;
}

//Zadanie 4
void ListaCD::reverse_cyclic(ListaJ::elem* lista)
{
	ListaJ::elem* prevElem = lista;
	lista = lista->nast;
	ListaJ::elem* nextElem = lista->nast;

	while (prevElem != nextElem)
	{
		lista->nast = prevElem;
		prevElem = lista;
		lista = nextElem;
		nextElem = lista->nast;
	}
}

//Zadanie 5
bool ListaCD::is_valid_pn(elem* lista)
{
	int variables = 0, operators = 0;
	while (lista)
	{
		if (lista->dane == '+' || lista->dane == '-' || lista->dane == '*' || lista->dane == '/')
			++operators;
		else if (lista->dane >= 'a' && lista->dane <= 'z')
			++variables;
		else
			return false;

		if (variables >= 2)
			if (operators >= 1)
			{
				--operators;
				--variables;
			}
			else
				return false;

		lista = lista->nast;
	}

	return variables == 1 && operators == 0;
}