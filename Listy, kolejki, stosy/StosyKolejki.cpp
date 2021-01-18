#include <iostream>

#include "StosyKolejki.h"

//Funkcje pomocnicze
void Stos::copy(elem* source, elem*& destination)
{
	destination = new elem{ source->dane, nullptr };
	if (source->nast)
		copy(source->nast, destination->nast);
}

void Stos::destroy(elem*& stos)
{
	if (stos->nast)
		destroy(stos->nast);

	delete stos;
	stos = nullptr;
}

void Stos::print(elem* stos)
{
	while (stos)
	{
		std::cout << stos->dane << " ";
		stos = stos->nast;
	}
}

//Zadanie 1
void Stos::push(elem*& stos, int x)
{
	elem* tempElem = stos;
	stos = new elem{ x, tempElem };
}

int Stos::pop(elem*& stos)
{
	if (stos->nast)
	{
		int tempValue = stos->dane;
		elem* tempElem = stos;
		stos = stos->nast;

		delete tempElem;
		tempElem = nullptr;

		return tempValue;
	}
	else
	{
		int tempValue = stos->dane;
		delete stos;
		stos = nullptr;
		return tempValue;
	}
}

int Stos::topEl(elem* stos)
{
	return stos->dane;
}

bool Stos::isEmpty(elem* stos)
{
	return !stos;
}

//Zadanie 4
void Stos::sequence()
{
	elem* stos = nullptr;

	std::string sequence = "EA*S*Y**";
	for (int i = 0; i < sequence.size(); ++i)
	{
		if (sequence[i] == '*')
			std::cout << (char)pop(stos);
		else
			push(stos, sequence[i]);
	}
}

//Zadanie 5
void Stos::add(elem*& stos1, int x)
{
	Stos::push(stos1, x);
}

int Stos::next(elem*& stos1, elem*& stos2)
{
	if (Stos::isEmpty(stos2))
	{
		while (!Stos::isEmpty(stos1))
		{
			Stos::push(stos2, Stos::pop(stos1));
		}
	}
	
	return Stos::pop(stos2);
}

//Zadanie 7
void Stos::reverseWithStack(elem*& stos)
{
	elem* tempStack = nullptr;
	while (!Stos::isEmpty(stos))
		Stos::push(tempStack, Stos::pop(stos));
	stos = tempStack;
}

void Stos::reverseWithQueue(elem*& stos)
{
	Kolejka::elem* startQueue = nullptr;
	Kolejka::elem* endQueue = nullptr;
	while (!Stos::isEmpty(stos))
		Kolejka::add(startQueue, endQueue, Stos::pop(stos));
	while (!Kolejka::isEmpty(startQueue))
		Stos::push(stos, Kolejka::next(startQueue, endQueue));
}

//Zadanie 8
void Stos::sort(elem*& stos)
{
	elem* tempStack = nullptr;
	int tempElem = 0;

	while (!Stos::isEmpty(stos))
	{
		tempElem = Stos::pop(stos);

		while (!Stos::isEmpty(tempStack))
		{
			if (Stos::topEl(tempStack) < tempElem)
				break;

			Stos::push(stos, Stos::pop(tempStack));
		}

		Stos::push(tempStack, tempElem);
	}

	stos = tempStack;
}

//Zadanie 9
void Stos::move(elem* stos1, elem*& stos2)
{
	elem* tempStack = nullptr;
	while (!Stos::isEmpty(stos1))
		Stos::push(tempStack, Stos::pop(stos1));
	while (!Stos::isEmpty(tempStack))
		Stos::push(stos2, Stos::pop(tempStack));
}

//Zadanie 2
void Kolejka::add(elem*& pocz_kolejki, elem*& kon_kolejki, int x)
{
	if (pocz_kolejki)
	{
		kon_kolejki->nast = new elem{ x, nullptr };
		kon_kolejki = kon_kolejki->nast;
	}
	else
	{
		pocz_kolejki = kon_kolejki = new elem{ x, nullptr };
	}
}

int Kolejka::next(elem*& pocz_kolejki, elem*& kon_kolejki)
{
	int tempValue = pocz_kolejki->dane;
	elem* tempElem = pocz_kolejki;
	pocz_kolejki = pocz_kolejki->nast;
	delete tempElem;
	tempElem = nullptr;
	return tempValue;
}

int Kolejka::firstEl(elem* pocz_kolejki)
{
	return pocz_kolejki->dane;
}

bool Kolejka::isEmpty(elem* pocz_kolejki)
{
	return !pocz_kolejki;
}

//Zadanie 3
void Kolejka::sequence()
{
	elem* pocz_kolejki = nullptr;
	elem* kon_kolejki = nullptr;

	std::string sequence = "EAS*Y*QUE***ST***IO*NS***";
	for (int i = 0; i < sequence.size(); ++i)
	{
		if (sequence[i] == '*')
			std::cout << (char)next(pocz_kolejki, kon_kolejki);
		else
			add(pocz_kolejki, kon_kolejki, sequence[i]);
	}
}

//Zadanie 6
void Kolejka::add(int* tab, int maxSize, int& tail, int x)
{
	tail++;
	tail %= maxSize;
	tab[tail] = x;
}

int Kolejka::next(int* tab, int maxSize, int& head)
{
	int value = tab[head++];
	head %= maxSize;
	return value;
}