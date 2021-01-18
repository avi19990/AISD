#ifndef LISTY_JEDNOKIERUNKOWE_H
#define LISTY_JEDNOKIERUNKOWE_H

namespace ListaJ
{
	struct elem
	{
		int dane;

		elem* nast;
	};

	//Zadanie 1
	void insert(int x, int i, elem*& a);
	void remove(int i, elem*& lista);
	int read(int i, elem* lista);

	//Zadanie 2
	int size(elem* lista);

	//Zadanie 3
	void print(elem* lista);

	//Zadanie 4
	void printReverseStack(elem* lista);

	//Zadanie 5
	void printReverse(elem* lista);

	//Zadanie 6
	void destroy(elem*& lista);

	//Zadanie 7
	elem* search(int x, elem* lista);
}

namespace ListaPoly
{
	struct elem
	{
		int expo;
		float coef;

		elem* nast;
	};

	//Funkcje pomocnicze do zadania 8
	void append(int expo, float coef, elem*& a);
	void print(elem* a);

	//Zadanie 8
	elem* polyadd(elem* l1, elem* l2);
}

namespace ListaFarey
{
	struct elem
	{
		int a;
		int b;

		elem* nast;
	};

	//Funkcje pomocnicze do zadania 9
	void insert(int a, int b, int i, elem*& lista);
	elem* read(int i, elem* lista);
	void print(elem* lista);

	//Zadanie 9
	elem* ulamekFareya(int n);
}

#endif