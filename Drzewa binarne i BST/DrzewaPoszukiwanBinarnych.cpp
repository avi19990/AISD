#include <iostream>
#include <math.h>

#include "DrzewaPoszukiwanBinarnych.h"

//Funkcje pomocnicze
void BST::insert(node*& tree, int value)
{
	if (!tree)
	{
		tree = new node{ value, nullptr, nullptr };
		return;
	}

	node* tempTree = tree;

	while (true)
	{
		if (value < tempTree->data)
			if (tempTree->left)
				tempTree = tempTree->left;
			else
			{
				tempTree->left = new node{ value, nullptr, nullptr };
				break;
			}
		else if (value >= tempTree->data)
			if (tempTree->right)
				tempTree = tempTree->right;
			else
			{
				tempTree->right = new node{ value, nullptr, nullptr };
				break;
			}
	}
}

void BST::print_tree(node* tree, int depth, char prefix)
{
	for (int i = 0; i < depth; ++i)
		std::cout << prefix;
	std::cout << tree->data << std::endl;

	++depth;
	if (tree->left)
		print_tree(tree->left, depth, prefix);
	else
	{
		for (int i = 0; i < depth; ++i)
			std::cout << prefix;
		std::cout << 'N' << std::endl;
	}
	if (tree->right)
		print_tree(tree->right, depth, prefix);
	else
	{
		for (int i = 0; i < depth; ++i)
			std::cout << prefix;
		std::cout << 'N' << std::endl;
	}
}

int BST::count(node* tree)
{
	int nodeCount = 1;

	if (tree->left)
		nodeCount += count(tree->left);
	if (tree->right)
		nodeCount += count(tree->right);

	return nodeCount;
}

void BST::rotateRight(node*& tree)
{
	node* tempNode = tree->left;
	tree->left = tempNode->right;
	tempNode->right = tree;
	tree = tempNode;
}

void BST::rotateLeft(node*& tree)
{
	node* tempNode = tree->right;
	tree->right = tempNode->left;
	tempNode->left = tree;
	tree = tempNode;
}

//Zadanie 2
void BST::reconstructDSW(node*& tree)
{
	node* tempTree = tree;
	node* tempNode = nullptr;

	//Stworzenie krêgos³upu
	while (tempTree)
	{
		if (tempTree->left)
		{
			rotateRight(tempTree);
			if (tempTree->data < tree->data)
				tree = tempTree;
		}
		else
		{
			if (tempNode)
				tempNode->right = tempTree;
			tempNode = tempTree;
			tempTree = tempTree->right;
		}
	}

	//Przywrócenie kszta³tu drzewa
	int nodeCount = count(tree);
	int m = pow(2, floor(log2(nodeCount+1))) - 1;

	tempTree = tree;
	tempNode = nullptr;

	for (int i = 0; i < nodeCount - m; ++i)
	{
		if (tree == tempTree)
		{
			rotateLeft(tempTree);
			tree = tempTree;
		}
		else
			rotateLeft(tempTree);

		if (tempNode)
			tempNode->right = tempTree;
		tempNode = tempTree;
		tempTree = tempTree->right;
	}

	while (m > 1)
	{
		tempTree = tree;
		tempNode = nullptr;

		m = floor(m/2);
		for (int i = 0; i < m; ++i)
		{
			if (tree == tempTree)
			{
				rotateLeft(tempTree);
				tree = tempTree;
			}
			else
				rotateLeft(tempTree);

			if (tempNode)
				tempNode->right = tempTree;
			tempNode = tempTree;
			tempTree = tempTree->right;
		}
	}
}

//Zadanie 3
bool BST::szukaj(node* tree, int value)
{
	if (tree->data == value)
		return true;
	
	if (value < tree->data)
		if (tree->left)
			return szukaj(tree->left, value);
		else
			return false;
	else if (value >= tree->data)
		if (tree->right)
			return szukaj(tree->right, value);
		else
			return false;
}