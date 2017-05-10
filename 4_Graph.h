#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>    // STL's list container
using namespace std;

// the Graph class use adjacency list to represent an undirected graph
// use list container of STL to store lists of adjacent nodes

class Graph
	{
	public:
		        Graph         (int);          // constructor
		void    PrintVertices ();             // print all vertives in a graph (due to the STL's list, vertex name begin from 0)
		void    AddEdge       (int, int);     // add edge to an undirected graph and print the edge           
		void    CheckDFS      (int, bool[]);  // check whether one vertex in a list is visited
		void    DFS           (int);          // print DFS traversal order from a given vertex
		void    BFS           (int);          // print BFS traversal order from a given vertex
	private:
		int          VerNum;      // how many vertices
		list <int> * AdjList;     // pointer to an array containing adjacency lists of int
	};

Graph::Graph (int vnumber)
	{
	VerNum = vnumber;	
	AdjList = new list<int> [vnumber];  // create an array (size == VerNum) containing adjacency lists of int
	}

void::Graph::PrintVertices ()
	{
	cout << "The vertices in this graph is : ";
	for (int i = 0; i < VerNum; i++)
		cout << i << " ";
	cout << endl;
	}

void Graph::AddEdge (int a, int b)
	{
	if ((a >= VerNum)||(b >= VerNum))
		cout << "Out of boundary" << endl;
	else
		{
		//undirected graph
	    AdjList[a].push_back(b);
	    AdjList[b].push_back(a);
		cout << "The edge in this graph is : (" << a << ", " << b << ")" << endl;
		}	
	}

void Graph::CheckDFS (int Current, bool Visited[])
	{
	// Set current vertex as visited and print it
	Visited[Current] =true;
	cout << Current << " ";

	list<int>::iterator i;
	// use loop to go through current adjacency list
	// if one vertex in current list not visited, recur call this function to 
	// go through another list begin whth this "not visited vertex"
	for (i = AdjList[Current].begin(); i != AdjList[Current].end(); i++) 
		{
		if (Visited[*i] == false)
			CheckDFS (*i, Visited);
		}
	}

void Graph::DFS (int Start)  // DFS traversal start from a given vertex
	{
	bool *visited = new bool[VerNum];
	// set all vertices as not visited
	for (int i = 0; i < VerNum; i++)
		visited[i] = false;

	CheckDFS (Start, visited);
	}

void Graph::BFS (int Current)
	{
	// create a list(queue) to hold BFS order vertices
	list<int> MyBfsList;
	// set all vertices as not visited
	bool *visited = new bool[VerNum];
	for (int i = 0; i < VerNum; i++)
		visited[i] = false;
	// set the current vertex as visited
	visited[Current] = true;
	// put the current vertex in this list(queue)
	MyBfsList.push_back(Current);

	list<int>::iterator i;
	while (MyBfsList.empty() == false)
		{
		// print the current front(first) vertex in the list
		Current = MyBfsList.front();
		cout << Current << " ";
		// remove this current front(first) vertex from the list
		MyBfsList.pop_front();
		// put all not-visited adjacent vertices in the current Adj-list into the Bfs-list (enqueue)
		for (i = AdjList[Current].begin(); i != AdjList[Current].end(); i++)
			{
			if (visited[*i] == false)
				{
				visited[*i] = true;
				MyBfsList.push_back(*i);
				}
			}
		}

	}

#endif 