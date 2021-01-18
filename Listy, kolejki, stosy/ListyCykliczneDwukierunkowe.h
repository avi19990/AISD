#ifndef LISTY_CYKLICZNE_DWUKIERUNKOWE_H
#define LISTY_CYKLICZNE_DWUKIERUNKOWE_H

#include "ListyJednokierunkowe.h"

namespace ListaCD
{
	struct elem
	{
		int dane;
		elem* poprz;
		elem* nast;
	};

	//Funkcje pomocnicze
	void print(elem* lista);

	//Zadanie 1
	void insert(int x, int i, elem*& a);
	void remove(elem*& lista);
	void remove(int i, elem*& lista);

	//Zadanie 2
	void reverse(elem*& lista);

	//Zadanie 3
	void to_cyclic(ListaJ::elem* lista);

	//Zadanie 4
	void reverse_cyclic(ListaJ::elem* lista);

	//Zadanie 5
	bool is_valid_pn(elem* lista);
}

#endif