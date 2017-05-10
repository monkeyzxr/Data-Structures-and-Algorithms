//*******************************************************
// Class:       CS 5343.501
// Assignment : Assignment - 4
// Author:      Xiangru Zhou
// Date:        03-30-2016
//*******************************************************

#include <iostream>

using namespace std;

#include "Graph.h"

int main ()
	{
	Graph g(18);       // create an undirected graph with 18 vertices
	g.PrintVertices();
	                    	
	g.AddEdge(0, 1);   // add 26 edges in this graph
	g.AddEdge(0, 2);   // this graph visualization is in "Screen-shot.pdf"
	g.AddEdge(0, 4);
	g.AddEdge(0, 7);
	g.AddEdge(1, 2);
	g.AddEdge(1, 5);
	g.AddEdge(2, 3);
	g.AddEdge(2, 6);
	g.AddEdge(3, 10);
	g.AddEdge(3, 7);
	g.AddEdge(3, 6);
	g.AddEdge(4, 5);
	g.AddEdge(4, 7);
	g.AddEdge(4, 8);
	g.AddEdge(7, 8);
	g.AddEdge(8, 11);
	g.AddEdge(9, 12);
	g.AddEdge(9, 13);
	g.AddEdge(10, 13);
	g.AddEdge(11, 12);
	g.AddEdge(11, 14);
	g.AddEdge(11, 15);
	g.AddEdge(12, 16);
	g.AddEdge(13, 16);
	g.AddEdge(15, 16);
	g.AddEdge(16, 17);   

	cout << "The DFS order starting from vertex 0 is: " ;
	g.DFS(0);
	cout << endl;

	cout << "The BFS order starting from vertex 0 is: " ;
	g.BFS(0);
	cout << endl;
        
    return 0;
	}