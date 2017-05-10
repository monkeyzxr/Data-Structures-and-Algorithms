//*******************************************************
// Class:       CS 5343.501
// Assignment : Assignment - 6
// Author:      Xiangru Zhou
// Date:        04-23-2016
//*******************************************************

#include <iostream>

#include <string>

using namespace std;

#include "HashTable.h"

#include "HashLinkedList.h"

void main ()
	{
	HashTable ht;    // create a hash table

	ht.PutKeyToTable("Games");    // insert 20 strings into the hash table
	ht.PutKeyToTable("of");
	ht.PutKeyToTable("Thrones");
	ht.PutKeyToTable("Season");
	ht.PutKeyToTable("Six");
	ht.PutKeyToTable("premieres"); // this string is 9 characters, it should show error warning
	ht.PutKeyToTable("this");
	ht.PutKeyToTable("Sunday");
	ht.PutKeyToTable("night");
	ht.PutKeyToTable("April");
	ht.PutKeyToTable("24");
	ht.PutKeyToTable("semaG");   // the reverse way to write English word "Games"
	ht.PutKeyToTable("fo");      // the reverse way to write English word "of"
	ht.PutKeyToTable("senorhT"); // the reverse way to write English word "Thrones"
	ht.PutKeyToTable("nosaeS");  // the reverse way to write English word "Season"
	ht.PutKeyToTable("xiS");     // the reverse way to write English word "Six"
	ht.PutKeyToTable("The");
	ht.PutKeyToTable("Winter");
	ht.PutKeyToTable("is");
	ht.PutKeyToTable("Coming");  
	//ht.PutKeyToTable("Coming"); 

	ht.PrintHashTable();    // print the hash table and the number of collisions 

	}
