#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>

using namespace std;

struct Node
	{
	int     Val;
	Node *  Next;
	};
Node * Head;

class SingleLinkedList
	{   
	public:
		Node *  CreateNode         (int);
        void    InsertAtBegin      ();
		void    InsertAtLast       ();
		void    PrintNodes         (Node *);
		void    FindMiddle         (Node *, Node *);
	};

Node * SingleLinkedList::CreateNode (int i)
	{
	Node * Temp;
	Temp = new(struct Node);
		(*Temp).Val = i;
		(*Temp).Next = NULL;
		return Temp;
	}

void SingleLinkedList::InsertAtBegin ()
	{
	int Value;
	cout << "Enter the value to be inserted: ";
	cin >> Value;
	Node * Tmp;
	Node * P;
	Tmp = CreateNode (Value);
	if (Head == NULL)
		{
		Head = Tmp;
		(*Head).Next = NULL;
		}
	else
		{
		P = Head;
		Head = Tmp;
		(*Head).Next = P;
		}
	//cout << "Element inserted at beginning successfully" << endl;
	}

void SingleLinkedList::InsertAtLast ()
	{
	int Value;
	cout << "Enter the value to be inserted: ";
	cin >> Value;
	Node * Tmp;
	Node * H ;
	Tmp = CreateNode (Value);
	H = Head;
	while ((*H).Next != NULL)
		{
		H = (*H).Next;
		}
	(*Tmp).Next = NULL;
	(*H).Next = Tmp;
	//cout << "Element inserted at last successfully" << endl;
	}

void SingleLinkedList::PrintNodes (Node * Head)
	{
	if (Head == NULL)
		return;
	else
		{
		cout << "The interger in the node is:" << (*Head).Val << endl;
		PrintNodes ((*Head).Next);
		}
	}

void SingleLinkedList::FindMiddle (Node * Fast, Node * Slow)
	{
	if ((*Fast).Next == NULL)
		cout << "The Value in the Middle Node is : " << (*Slow).Val;
	else
	    FindMiddle( (*((*Fast).Next)).Next, (*Slow).Next);
	}

#endif