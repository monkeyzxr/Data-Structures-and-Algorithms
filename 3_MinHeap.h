#ifndef MIN_HEAP_H
#define MIN_HEAP_H

/********************
// A binary heap is a complete binary tree. 
// The value in a parent node is smaller than the values in its two children nodes.
// This former is called as min-heap.
// The following min-heap is build from an array.
*********************/

void PrintArray (int *, int);   // a function to print elements of an array
void Swap       (int *, int *); // a function to swap two integers

class MinHeap
	{
	public:
		          MinHeap               (int);           // constructor to create a min-heap with given size
		void      BuildHeap             (int [], int);
		int       GetParentIndex        (int);           // get index of the parent of a node
		int       GetLeftChildIndex     (int);           // get index of the left child of a node
		int       GetRightChildIndex    (int);           // get index of the right child of a node
		int       GetMin                ();              // get minimum key (root) 
		void      RemoveMin             ();              // remove the root which is the minimum element
		void      MinHeapify            (int);           // heapify a subtree with root at given index
		void      Insert                (int);           // insert the given integer to min-heap
	public:
		      int * Array;          // the elements in the min-heap
		      int   CurrentSize;    // the current size of the min-heap
              int   MaxSize;        // the maximum size of the heap
	};


MinHeap::MinHeap (int maxsize)
	{
	MaxSize = maxsize;
	CurrentSize = 0;
	Array = new int [MaxSize];
	}

void MinHeap::BuildHeap (int a[], int size)
	{
	CurrentSize = size;
	Array = a;
	int i = (CurrentSize - 1)/2;
	while (i >= 0)
		{
		MinHeapify (i);
		i--;
		}
	}

int MinHeap::GetParentIndex (int i)
	{
	return (i - 1)/2;
	}

int MinHeap::GetLeftChildIndex (int i)
	{
	return (2*i + 1);     
	}

int MinHeap::GetRightChildIndex (int i)
	{
	return (2*i + 2);     
	}

int MinHeap::GetMin ()
	{
	return Array[0];
	}

void MinHeap::RemoveMin()    
	{
	if (CurrentSize <= 0)
		cout << " Error, no element in the array. " << endl;
	else
		{
	    Array[0] = Array[CurrentSize-1];
	    CurrentSize--;
	    MinHeapify (0);
		}
	}

void MinHeap::MinHeapify (int i)
// Use a recursive function to heapify a tree with root at index i
// Assume that element at index i (root of the tree) is already heapified
	{
	int Min   = i; // Initialize the min-value index as root of the tree
	int Left  = GetLeftChildIndex (i);
	int Right = GetRightChildIndex (i);

	//The following is base of the recursive function
	//Image Min as an "arrow" to point the smallest value of the two children nodes
	if ((Array[Left] < Array[Min]) && (Left < CurrentSize))
		Min = Left;
	if ((Array[Right] < Array[Min]) && (Right < CurrentSize))
		Min = Right;

	if (Min != i)
	    {
		// swap the value of "root node" and the "its smallest children node"
		// to make sure the value of the root node is always smaller than its children
		Swap (&Array[Min], &Array[i]); 
		// use recursive function to continue heapify its subtree 
		MinHeapify (Min);
		}		                               
	}

void MinHeap::Insert (int key)
	{
	if (CurrentSize == MaxSize)
		{
		cout << "Overflow: Can not insert key. " << endl;
		return;
		}
	// First insert the new key at the end
	CurrentSize ++;
	int i = CurrentSize - 1;
	Array [i] = key;

	// Fix the min-heap property
	while ((i != 0) && (Array[GetParentIndex(i)] > Array[i]))
		{
		Swap (&Array[i], &Array[GetParentIndex(i)]);
		i = GetParentIndex (i);
		}
	}


void PrintArray (int * a, int s)
	{
	for (int i = 0; i < s; i++)
		cout << a [i] << " ";
	cout << '\n';
	}

void Swap (int * a, int * b)
	{
	int Tmp;
	Tmp = *a;
	*a  = *b;
	*b  = Tmp;
	}

#endif