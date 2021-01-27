#include <iostream>
#include <math.h>

#include "DrzewaBinarne.h"

//Funkcje pomocnicze
void DrzewoBinarne::copy(node* source, node*& destination)
{
	destination = new node{ source->data, nullptr, nullptr };

	if (source->left)
		copy(source->left, destination->left);
	if (source->right)
		copy(source->right, destination->right);
}

void DrzewoBinarne::destroy(node*& tree)
{
	if (tree->left)
		destroy(tree->left);
	if (tree->right)
		destroy(tree->right);

	delete tree;
	tree = nullptr;
}

//Zadanie 1
bool DrzewoBinarne::search(node* tree, int x)
{
	if (tree->data == x)
		return true;

	if (tree->left)
		if (search(tree->left, x))
			return true;
	if (tree->right)
		if (search(tree->right, x))
			return true;

	return false;
}

//Zadanie 2
int DrzewoBinarne::node_count(node* tree)
{
	int counter = 1;
	if (tree->left)
		counter += node_count(tree->left);
	if (tree->right)
		counter += node_count(tree->right);

	return counter;
}

int DrzewoBinarne::leaves_count(node* tree)
{
	int counter = 0;
	if (tree->left)
		counter += leaves_count(tree->left);
	if (tree->right)
		counter += leaves_count(tree->right);

	if (!tree->left && !tree->right)
		++counter;

	return counter;
}

int DrzewoBinarne::right_children_count(node* tree)
{
	int counter = 0;
	if (tree->left)
		counter += right_children_count(tree->left);
	if (tree->right)
	{
		++counter;
		counter += right_children_count(tree->right);
	}

	return counter;
}

int DrzewoBinarne::tree_height(node* tree)
{
	int lCounter = 0, rCounter = 0;
	if (tree->left)
	{
		++lCounter;
		lCounter += tree_height(tree->left);
	}
	if (tree->right)
	{
		++rCounter;
		rCounter += tree_height(tree->right);
	}

	if (lCounter > rCounter)
		return lCounter;
	else
		return rCounter;
}

//Zadanie 3
bool DrzewoBinarne::is_balanced(node* tree)
{
	int lCounter = 0, rCounter = 0;
	if (tree->left)
	{
		++lCounter;
		lCounter += tree_height(tree->left);
	}
	if (tree->right)
	{
		++rCounter;
		rCounter += tree_height(tree->right);
	}

	return abs(lCounter - rCounter) <= 1;
}

//Zadanie 4
bool DrzewoBinarne::is_BST(node* tree)
{
	bool isBST = true;

	if (tree->left)
	{
		if (tree->left->data > tree->data)
			return false;
		else
			isBST = is_BST(tree->left);
	}

	if (tree->right)
	{
		if (tree->right->data < tree->data)
			return false;
		else
			isBST = is_BST(tree->right);
	}

	return isBST;
}

//Zadanie 5
void DrzewoBinarne::delete_leaves(node*& tree)
{
	if (!tree->left && !tree->right)
	{
		delete tree;
		tree = nullptr;
	}
	else
	{
		if (tree->left)
			delete_leaves(tree->left);
		if (tree->right)
			delete_leaves(tree->right);
	}
}

//Zadanie 6
void DrzewoBinarne::preorderA(node* p)
{
	if (p->left != 0 && p->data - p->left->data < 2)
		p->left->data += 2;
	if (p->left)
		preorderA(p->left);
	if (p->right)
		preorderA(p->right);
}

void DrzewoBinarne::inorderA(node* p)
{
	if (p->left)
		inorderA(p->left);
	if (p->left != 0 && p->data - p->left->data < 2)
		p->left->data += 2;
	if (p->right)
		inorderA(p->right);
}

void DrzewoBinarne::postorderA(node* p)
{
	if (p->left)
		postorderA(p->left);
	if (p->right)
		postorderA(p->right);
	if (p->left != 0 && p->data - p->left->data < 2)
		p->left->data += 2;
}

void DrzewoBinarne::preorderB(node* p)
{
	if (p->left == 0)
		p->right = 0;
	if (p->left)
		preorderB(p->left);
	if (p->right)
		preorderB(p->right);
}

void DrzewoBinarne::inorderB(node* p)
{
	if (p->left)
		inorderB(p->left);
	if (p->left == 0)
		p->right = 0;
	if (p->right)
		inorderB(p->right);
}

void DrzewoBinarne::postorderB(node* p)
{
	if (p->left)
		postorderB(p->left);
	if (p->right)
		postorderB(p->right);
	if (p->left == 0)
		p->right = 0;
}

//Zadanie 7
void DrzewoBinarne::preorder(node* tree)
{
	std::cout << tree->data << " ";
	if (tree->left)
		preorder(tree->left);
	if (tree->right)
		preorder(tree->right);
}

void DrzewoBinarne::inorder(node* tree)
{
	if (tree->left)
		inorder(tree->left);
	std::cout << tree->data << " ";
	if (tree->right)
		inorder(tree->right);
}

void DrzewoBinarne::equalPreorderInorder()
{
	node* testTree = new node{
		5,
		new node{
			7,
			new node{5, nullptr, nullptr},
			new node{5, nullptr, nullptr}
		},
		new node{
			9,
			new node{9, nullptr, nullptr},
			new node{3, nullptr, nullptr}
		}
	};

	std::cout << "Drzewo binarne dla ktorego metody preorder i inorder generuja ten sam ciag" << std::endl;
	print_tree(testTree);
	std::cout << "Preorder: ";
	preorder(testTree);
	std::cout << std::endl << "Inorder: ";
	inorder(testTree);
	std::cout << std::endl;
}

//Zadanie 8
DrzewoBinarne::node* DrzewoBinarne::mirror_tree(node* tree)
{
	node* tempNode = new node{tree->data, nullptr, nullptr};

	if (tree->left)
		tempNode->right = mirror_tree(tree->left);
	if (tree->right)
		tempNode->left = mirror_tree(tree->right);

	return tempNode;
}

//Zadanie 9
void DrzewoBinarne::print_tree(node* tree, int depth, char prefix)
{
	for (int i = 0; i < depth; ++i)
		std::cout << prefix;
	std::cout << tree->data << std::endl;

	++depth;
	if (tree->left)
		print_tree(tree->left, depth, prefix);
	if (tree->right)
		print_tree(tree->right, depth, prefix);
}

//Zadanie 10
int DrzewoBinarne::eval(node_calc* tree)
{
	if (tree->op == '-')
		return eval(tree->left) - eval(tree->right);
	else if (tree->op == '+')
		return eval(tree->left) + eval(tree->right);
	else if (tree->op == '/')
		return eval(tree->left) / eval(tree->right);
	else if (tree->op == '*')
		return eval(tree->left) * eval(tree->right);
	else if (tree->op == 0)
		return tree->number;
}

//Zadanie 11
DrzewoBinarne::node* DrzewoBinarne::create_perfect_tree(int* a, const int k)
{
	int index = (pow(2, k) - 1) / 2;
	node* newNode = new node{ a[index], nullptr, nullptr };

	if (k > 1)
	{
		newNode->left = create_perfect_tree(a, k - 1);
		newNode->right = create_perfect_tree(a + index + 1, k - 1);
	}

	return newNode;
}