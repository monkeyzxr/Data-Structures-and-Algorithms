//*******************************************************
// Class:       CS 5343.501
// Assignment : Assignment - 1
// Author:      Xiangru Zhou
// Date:        01-30-2016
//*******************************************************

#include <iostream>

using namespace std;

#include "SingleLinkedList.h"

void main ()
	{
	SingleLinkedList SLL;
	Head = NULL;

	for (int i = 0; i < 15; i++)
		{
		SLL.InsertAtBegin();
		//SLL.InsertAtLast ();
		}
	cout << '\n';  
	SLL.PrintNodes (Head);
	cout << '\n';  
	SLL.FindMiddle (Head, Head);
	cout << '\n';    
	}