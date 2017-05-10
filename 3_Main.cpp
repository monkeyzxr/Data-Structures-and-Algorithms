//*******************************************************
// Class:       CS 5343.501
// Assignment : Assignment - 3
// Author:      Xiangru Zhou
// Date:        02-27-2016
//*******************************************************

#include <iostream>

using namespace std;

#include "MinHeap.h"

void main ()
	{
	MinHeap hp (50); // Create a min-heap with maximum size = 50, current size = 25

	hp.Insert (16);
	hp.Insert (4);
	hp.Insert (10);
	hp.Insert (14);
	hp.Insert (7);
	hp.Insert (9);
	hp.Insert (3);
	hp.Insert (12);
	hp.Insert (8);
	hp.Insert (24);
	hp.Insert (12);
	hp.Insert (21);
	hp.Insert (32);
	hp.Insert (10);
	hp.Insert (9);
	hp.Insert (33);
	hp.Insert (2);
	hp.Insert (36);
	hp.Insert (18);
	hp.Insert (28);
	hp.Insert (8);
	hp.Insert (25);
	hp.Insert (19);
	hp.Insert (30);
	hp.Insert (17);

	cout << "The original given array in min-heap is : " << endl;
	PrintArray(hp.Array, hp.CurrentSize);
	cout << endl;

	// make a loop to insert and delete the min-heap for 4 times
	for (int i = 1; i <= 4; i++)
		{
		int a;
		cout << "Please enter an interger to insert in the min-heap : ";
		cin >> a;
		hp.Insert (a);
		cout << "After the insert, print the min-heap : " << endl;
		PrintArray(hp.Array, hp.CurrentSize);
		cout << "After the delete, print the min-heap : " << endl;
		hp.RemoveMin ();
		PrintArray(hp.Array, hp.CurrentSize);
		cout << endl;
		}

	}