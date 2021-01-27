#include <iostream>

#include "DrzewaBinarne.h"
#include "DrzewaPoszukiwanBinarnych.h"

void testDrzewoBinarne()
{
	using namespace DrzewoBinarne;

	std::cout << "Drzewa binarne" << std::endl;

	node* testTree = new node{
		5,
		new node{
			10,
			new node{ 4, new node{ 18, new node{ 21, nullptr, nullptr }, nullptr }, nullptr },
			new node{ 11, nullptr, nullptr } },
		new node{
			7,
			new node{ 2, nullptr, nullptr },
			new node{ 9, nullptr, nullptr } } };

	std::cout << "Drzewo testTree zawiera elementy [5, 10, 7, 4, 11, 2, 9, 18, 21]" << std::endl;
	print_tree(testTree);

	std::cout << "Szukanie elementow w drzewie testTree" << std::endl;
	std::cout << "4 - " << ((search(testTree, 4) ? "Znaleziono" : "Nie znaleziono")) << std::endl;
	std::cout << "1 - " << ((search(testTree, 1) ? "Znaleziono" : "Nie znaleziono")) << std::endl;

	std::cout << "Ilosc wierzcholkow w drzewie testTree - " << node_count(testTree) << std::endl;
	std::cout << "Ilosc lisci w drzewie testTree - " << leaves_count(testTree) << std::endl;
	std::cout << "Ilosc prawych potomkow w drzewie testTree - " << right_children_count(testTree) << std::endl;
	std::cout << "Wysokosc drzewa testTree - " << tree_height(testTree) << std::endl;

	std::cout << "Drzewo testTree " << ((is_balanced(testTree)) ? "" : "nie ") << "jest zbalansowane" << std::endl;
	std::cout << "Drzewo testTree " << ((is_BST(testTree)) ? "" : "nie ") << "jest drzewem BST" << std::endl;

	std::cout << "Usuwanie lisci z drzewa testTree" << std::endl;
	delete_leaves(testTree);
	print_tree(testTree);

	std::cout << "Lustrzane odbicie drzewa testTree" << std::endl;
	node* tempTree = mirror_tree(testTree);
	print_tree(tempTree);

	node* zad3Tree = new node{
		10,
		new node{
			5,
			new node{ 4, new node{ 0, nullptr, nullptr }, nullptr },
			new node{ 6, nullptr, new node{ 7, nullptr, new node{ 9, nullptr, nullptr } } } },
		new node{
			20,
			new node{ 15, new node{ 13, nullptr, nullptr }, nullptr },
			new node{ 30, nullptr, nullptr } } };

	std::cout << std::endl << "Drzewo zad6Tree" << std::endl;
	print_tree(zad3Tree);

	tempTree = nullptr;
	copy(zad3Tree, tempTree);
	std::cout << "Zad 6a preorder" << std::endl;
	preorderA(tempTree);
	print_tree(tempTree);

	destroy(tempTree);
	copy(zad3Tree, tempTree);
	std::cout << "Zad 6a inorder" << std::endl;
	inorderA(tempTree);
	print_tree(tempTree);

	destroy(tempTree);
	copy(zad3Tree, tempTree);
	std::cout << "Zad 6a postorder" << std::endl;
	postorderA(tempTree);
	print_tree(tempTree);

	destroy(tempTree);
	copy(zad3Tree, tempTree);
	std::cout << "Zad 6b preorder" << std::endl;
	preorderB(tempTree);
	print_tree(tempTree);

	destroy(tempTree);
	copy(zad3Tree, tempTree);
	std::cout << "Zad 6b inorder" << std::endl;
	inorderB(tempTree);
	print_tree(tempTree);

	destroy(tempTree);
	copy(zad3Tree, tempTree);
	std::cout << "Zad 6b postorder" << std::endl;
	postorderB(tempTree);
	print_tree(tempTree);

	equalPreorderInorder();

	node_calc* arythmeticTree = new node_calc{
		'*',
		0,
		new node_calc{
			'+',
			0,
			new node_calc{ 0, 7, nullptr, nullptr },
			new node_calc{ 0, 8, nullptr, nullptr } },
		new node_calc{
			'-',
			0,
			new node_calc{ 0, 3, nullptr, nullptr },
			new node_calc{ 0, 2, nullptr, nullptr } } };
	std::cout << "Wynik drzewa arytmetycznego z zad 10: " << eval(arythmeticTree) << std::endl;
	int* valueTab = new int[] { 5, 3, 7, 3, 9, 1, 8 };
	std::cout << "Stworzenie drzewa z zadanie 11 z tablicy wartosci [5, 3, 7, 3, 9, 1, 8]" << std::endl;
	node* perfectTree = create_perfect_tree(valueTab, 3);
	print_tree(perfectTree);
}

void testDrzewoBST()
{
	using namespace BST;

	node* testTree = nullptr;

	insert(testTree, 10);
	insert(testTree, 5);
	insert(testTree, 13);
	insert(testTree, 7);
	insert(testTree, 11);
	insert(testTree, 15);
	insert(testTree, 20);
	insert(testTree, 14);
	std::cout << "Drzewo testTree zawiera elementy [10, 5, 13, 7, 11, 15, 14, 20]" << std::endl;
	print_tree(testTree, 0, '-');

	std::cout << "Szukanie w drzewie testTree wartosci 11: " << ((szukaj(testTree, 11) ? "znaleziono" : "nie znaleziono")) << std::endl;
	std::cout << "Szukanie w drzewie testTree wartosci 4: " << ((szukaj(testTree, 4) ? "znaleziono" : "nie znaleziono")) << std::endl;

	std::cout << "Rekonstrukcja testTree" << std::endl;
	reconstructDSW(testTree);
	print_tree(testTree, 0, '-');
}

int main()
{
	testDrzewoBinarne();
	testDrzewoBST();
}