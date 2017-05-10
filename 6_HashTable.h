#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>

using namespace std;

#include <string>

#include "HashLinkedList.h"

const int TableSize = 101;    // set the table size as a prime number

class HashTable
	{
	public:
		                   HashTable           ();        // constructor
		                   ~HashTable          ();        // destructor
		int                HashFunction        (string);  // a function to add up the ASCII values of all characters of a key
		void               PutKeyToTable       (string);  // a function to put the key into the hash table
		void               PrintHashTable      ();        // print the hash table and the number of collisions

	private:
		HashLinkedList ** MyHashTable;
	};

HashTable::HashTable ()
	{
	MyHashTable = new HashLinkedList* [TableSize];

	for (int i = 0; i < TableSize; i++)            // set all elements in hash table as NULL
		MyHashTable[i] = NULL;
	}

HashTable::~HashTable ()    // destructor to delete the hash table
	{
	for (int i = 0; i < TableSize; i++)
		{
		if (MyHashTable[i] != NULL)
			{
			HashLinkedList * PrevStart = NULL;
			HashLinkedList * Start = MyHashTable[i];
			while (Start != NULL)
				{
				PrevStart = Start;
				Start = (*Start).GetNext();
				delete PrevStart;
				}
			}			
		}
	delete [] MyHashTable;
	}

int HashTable::HashFunction (string key)  
	{
	int HashValue = 0;

	for (int i = 0; i < key.length(); i++)
		HashValue = HashValue + key[i];    // sum the ASCII values of all characters of a string key
	return HashValue % TableSize;
	}

void HashTable::PutKeyToTable (string key)
	{
	if ((key.length() <= 8) && (key.length() > 0))  //  as assignment requested, the max size of string is 8 characters
		{
	    int HashIndex = HashFunction(key);  // get the index of the hash table for current key string
	    if (MyHashTable[HashIndex] == NULL) // if no collision
		    MyHashTable[HashIndex] = new HashLinkedList (key);
	    else  // if the collision happened
		    {
		    HashLinkedList * Begin = MyHashTable[HashIndex]; 
		    while (((*Begin).GetNext() != NULL) && ((*Begin).GetKey() != key))
			    {
			    Begin = (*Begin).GetNext(); // go to the end of the linked list, or go to the same string's position
			    }
		    if ((*Begin).GetKey() == key) // if there already exists a same string in the collision index position
			    (*Begin).SetKey(key);
		    else  // if not, set the new key at the end of the linked list
			    (*Begin).SetNext(new HashLinkedList(key));	
		    }
		}
	else
		{
		cout << "'" << key << "' is more than 8 characters! (Error: Out of boundary)" << endl;
		cout << endl;
		}
	}

void HashTable::PrintHashTable ()
	{
	HashLinkedList * Tmp;
	int CountElements = 0;
	int CountTables = 0;
	int CountCollisions = 0;
	cout << "The Hash Table is : " << endl;
	for (int i = 0; i < TableSize; i++)
		{
		Tmp = MyHashTable[i];
		if (Tmp != NULL)
			{
			cout << "Hash Table[" << i << "] :" ;
			CountTables = CountTables + 1;
			}
		else
			continue;
		while (Tmp != NULL)
			{
			cout << " -> " << (*Tmp).GetKey();
			Tmp = (*Tmp).GetNext();
			CountElements = CountElements + 1;
			}		
		cout << endl;
		}
	CountCollisions = CountElements - CountTables;  // get the number of the collisions
	cout << endl;
	cout << "The number of collisions is : " << CountCollisions << endl;
	}

#endif