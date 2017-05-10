#ifndef GRAPH_H
#define GRAPH_H

// the Graph class use adjacency list to represent an undirected graph
// use list container of STL to store lists of adjacent nodes
// priority queue is a container which its first element is always the greatest of the elements(max heap)
// we can use STL's priority queue to implement min-heap, which is much easier
// pair is a container which holds two member objects of arbitary type
// for Prim's algorithm, every vertex need to hold a vertex name and the weight(key)

#include <iostream>
#include <list>       // STL's list container
#include <queue>      // STL's priority queue, which is a max heap
#include <utility>    // a header file in STL for "pair"
#include <functional> // to make a min-heap, we need to use "greater()" in this header file
/**************************
if we don't include <functional>, we could use following struct to make min-heap by priority_queue:
struct MyComparator               // define a comparator struct
    {
     bool operator()(int i, int j)
	     {
         return i > j;
         }
    };
priority_queue<int, std::vector<int>, MyComparator> MyMinHeap;  // construct a min-heap by priority_queue
***************************/

using namespace std;

typedef pair<int, int> MyPair;   // define a pair (weight, vertex name) for a vertex

class Graph
	{
	public:
		        Graph         (int);              // constructor
		void    PrintVertices ();                 // print all vertives in a graph (due to the STL's list, vertex name begin from 0)
		void    AddEdge       (int, int, int);    // add edge and weight to an undirected graph and print the edge   
		void    PrimMST       ();                 // use Prim's algorithm to find MST

	private:
		int             VerNum;      // how many vertices
		list <MyPair> * AdjList;     // pointer to an array containing adjacency lists of pairs of int
	};

Graph::Graph (int vnumber)
	{
	VerNum = vnumber;	
	AdjList = new list<MyPair> [vnumber];  // create an array (size == VerNum) containing adjacency lists of pairs of int
	}

void::Graph::PrintVertices ()
	{
	cout << "The vertices in this graph is : ";
	for (int i = 0; i < VerNum; i++)
		cout << i << " ";
	cout << endl;
	}

void Graph::AddEdge (int a, int b, int w)
	{
	if ((a >= VerNum)||(b >= VerNum))
		cout << "Vertex out of boundary" << endl;
	else
		{
		//undirected graph
		AdjList[a].push_back(make_pair(b, w)); // construct pair object
		AdjList[b].push_back(make_pair(a, w));
		cout << "The edge in this graph is : (" << a << ", " << b << ") with weight " << w << endl;
		}	
	}

void Graph::PrimMST ()
	{
	int start_vertex = 0;     // initialize the start vertex
	if ((start_vertex >= VerNum) || (start_vertex < 0))
		{
		cout << "Vertex out of boundary" << endl;
		exit (0);
		}
	else
	    cout << "The start vertex in MST is: " << start_vertex << endl;

	// priority_queue supports a constructor that requires two extra arguments to make it min-heap
	// the form is: priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	// create MyPQ to store vertices which belongs to PrimMST
	priority_queue<MyPair, vector<MyPair>, greater<MyPair>> MyPQ;

	// create a vector for all vertices' keys, initialize all keys as INT_MAX
	vector<int> Key(VerNum, INT_MAX);

	// to check whether the vertex in MST or not
	vector<bool> WhetherInMST(VerNum, false);

	// use vector to store parent of vertex
	vector<int> Parent(VerNum, NULL);

	// put start-vertex in priority queue and set its key as zero
	MyPQ.push(make_pair(0, start_vertex));
	Key[start_vertex] = 0;

	while (MyPQ.empty() == false)
		{
		// define min_vertex as minimum key vertex's name
		int min_vertex = MyPQ.top().second;  // get the second element(vertex name) in the pair
		WhetherInMST[min_vertex] = true;    // regard the min_vertex as already been removed from MyPQ (already visited)
		MyPQ.pop();		

		list<MyPair>::iterator i;
		for (i = AdjList[min_vertex].begin(); i != AdjList[min_vertex].end(); i++)
			{
			int vertex_name = (*i).first; // get min_vertex's neighbour's name
			int weight = (*i).second;     // get min_vertex's neighbour's weight

			if ((WhetherInMST[vertex_name] == false) && (Key[vertex_name] > weight))
				{
				Key[vertex_name] = weight;
				MyPQ.push(make_pair(Key[vertex_name], vertex_name));
				Parent[vertex_name] = min_vertex;
				}
			}
		}
	cout << "The PrimeMST of the graph is: " << endl;
	// print the MST using parent array
	// print the edge by ascending vertex order
	for (int i = 1; i < VerNum; i++)
		cout << i << " - " << Parent[i] << endl;	
	}

#endif 