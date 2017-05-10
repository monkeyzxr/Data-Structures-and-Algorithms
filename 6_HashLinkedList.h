#ifndef HASH_LINKED_LIST_H
#define HASH_LINKED_LIST_H

// As assignment requested, use separate chaining to implement collisions
// This means, more than one key map to the same list index 
// The HashLinkedList class is used to handle the entries of a single linked list 

#include <iostream>

#include <string>

using namespace std;

class HashLinkedList
	{
	public:
		                    HashLinkedList  (string &);
		string              GetKey          ();
		HashLinkedList *    GetNext         ();
		void                SetKey          (string &);
		void                SetNext         (HashLinkedList *);
	private:
		string           Key;
		HashLinkedList * Next;
	};

HashLinkedList::HashLinkedList (string & s)
	{
	this ->Key = s;
	this ->Next = NULL;
	}

string HashLinkedList::GetKey ()
	{
	return Key;
	}

HashLinkedList * HashLinkedList::GetNext ()
	{
	return Next;
	}

void HashLinkedList::SetKey (string & s)
	{
	this ->Key = s;
	}

void HashLinkedList::SetNext (HashLinkedList * next)
	{
	this ->Next = next;
	}

#endif
