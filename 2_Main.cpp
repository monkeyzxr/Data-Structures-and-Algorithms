//*******************************************************
// Class:       CS 5343.501
// Assignment : Assignment - 2
// Author:      Xiangru Zhou
// Date:        02-10-2016
//*******************************************************

#include <iostream>

using namespace std;

#include"BSTree.h"

int main ()
	{
	//int key [15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
	int key [15] = {30, 10, 20, 110, 80, 60, 70, 130, 150, 120, 40, 100, 50, 140, 90};
	BSTree BST;

	for (int i = 0; i < 15; i++)
		BST.root = BST.InsertNode (BST.root, key[i]);

	cout << "Inorder travel to show the tree: " << endl;
	BST.InOrder (BST.root);
	cout << '\n';
	cout << "Delete two internal numbers, (50 and 80)" << endl;
	BST.DeleteNode (BST.root, 50);
	BST.DeleteNode (BST.root, 80);
	cout << "Inorder travel to show the deleted tree: " << endl;
	BST.InOrder (BST.root);
        return 0;

	}