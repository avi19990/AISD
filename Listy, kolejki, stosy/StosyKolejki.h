#ifndef STOSY_KOLEJKI_H
#define STOSY_KOLEJKI_H

namespace Stos
{
	struct elem
	{
		int dane;
		elem* nast;
	};

	//Funkcje pomocnicze
	void copy(elem* source, elem*& destination);
	void destroy(elem*& stos);
	void print(elem* stos);

	//Zadanie 1
	void push(elem*& stos, int x);
	int pop(elem*& stos);
	int topEl(elem* stos);
	bool isEmpty(elem* stos);

	//Zadanie 4
	void sequence();

	//Zadanie 5
	void add(elem*& stos1, int x);
	int next(elem*& stos1, elem*& stos2);

	//Zadanie 7
	void reverseWithStack(elem*& stos);
	void reverseWithQueue(elem*& stos);

	//Zadanie 8
	void sort(elem*& stos);

	//Zadanie 9
	void move(elem* stos1, elem*& stos2);
}

namespace Kolejka
{
	struct elem
	{
		int dane;
		elem* nast;
	};

	//Zadanie 2
	void add(elem*& pocz_kolejki, elem*& kon_kolejki, int x);
	int next(elem*& pocz_kolejki, elem*& kon_kolejki);
	int firstEl(elem* pocz_kolejki);
	bool isEmpty(elem* pocz_kolejki);

	//Zadanie 3
	void sequence();

	//Zadanie 6
	void add(int* tab, int maxSize, int& tail, int x);
	int next(int* tab, int maxSize, int& head);
}

#endif