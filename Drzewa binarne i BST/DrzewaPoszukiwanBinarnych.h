#ifndef DRZEWA_POSZUKIWAN_BINARNYCH_H
#define DRZEWA_POSZUKIWAN_BINARNYCH_H

namespace BST
{
	struct node
	{
		int data;
		node* left;
		node* right;
	};

	//Funkcje pomocnicze
	void insert(node*& tree, int value);
	void print_tree(node* tree, int depth, char prefix);
	int count(node* tree);
	void rotateRight(node*& tree);
	void rotateLeft(node*& tree);

	//Zadanie 2
	void reconstructDSW(node*& tree);

	//Zadanie 3
	bool szukaj(node* tree, int value);
}

#endif
