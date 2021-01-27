#ifndef DRZEWA_BINARNE_H
#define DRZEWA_BINARNE_H

namespace DrzewoBinarne
{
	struct node
	{
		int data;
		node* left;
		node* right;
	};

	struct node_calc
	{
		char op;
		int number;
		node_calc* left;
		node_calc* right;
	};

	//Funkcje pomocnicze
	void copy(node* source, node*& destination);
	void destroy(node*& tree);

	//Zadanie 1
	bool search(node* tree, int x);

	//Zadanie 2
	int node_count(node* tree);
	int leaves_count(node* tree);
	int right_children_count(node* tree);
	int tree_height(node* tree);

	//Zadanie 3
	bool is_balanced(node* tree);

	//Zadanie 4
	bool is_BST(node* tree);

	//Zadanie 5
	void delete_leaves(node*& tree);

	//Zadanie 6
	void preorderA(node* p);
	void inorderA(node* p);
	void postorderA(node* p);
	void preorderB(node* p);
	void inorderB(node* p);
	void postorderB(node* p);

	//Zadanie 7
	void preorder(node* tree);
	void inorder(node* tree);
	void equalPreorderInorder();

	//Zadanie 8
	node* mirror_tree(node* tree);

	//Zadanie 9
	void print_tree(node* tree, int depth = 0, char prefix = 0);

	//Zadanie 10
	int eval(node_calc* tree);

	//Zadanie 11
	node* create_perfect_tree(int* a, const int k);
}

#endif
