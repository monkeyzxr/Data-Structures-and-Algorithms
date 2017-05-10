//*******************************************************
// Class:       CS 5343.501
// Assignment : Assignment - 5
// Author:      Xiangru Zhou
// Date:        04-10-2016
//*******************************************************

#include <iostream>

using namespace std;

#include "Graph.h"

void main ()
	{
	Graph g(18);          // create an undirected graph of 18 vertices
	g.PrintVertices();

	g.AddEdge(0, 4, 2);   // add 25 edges with weight in this graph
	g.AddEdge(1, 4, 3);   // this graph visualization is in "Screen-shot.pdf"
	g.AddEdge(1, 2, 1);   // this graph visualization is from "www.cs.usfca.edu/~galles/visualization/Prim.html"
	g.AddEdge(2, 5, 7);
	g.AddEdge(3, 10, 8);
	g.AddEdge(3, 17, 7);
	g.AddEdge(4, 7, 8);
	g.AddEdge(4, 8, 8);
	g.AddEdge(5, 6, 6);
	g.AddEdge(5, 8, 1);
	g.AddEdge(7, 11, 1);
	g.AddEdge(8, 11, 4);
	g.AddEdge(8, 12, 8);
	g.AddEdge(9, 10, 9);
	g.AddEdge(9, 13, 5);
	g.AddEdge(10, 17, 6);
	g.AddEdge(11, 14, 2);
	g.AddEdge(11, 15, 6);
	g.AddEdge(12, 13, 5);
	g.AddEdge(12, 16, 6);
	g.AddEdge(13, 16, 3);
	g.AddEdge(14, 0, 2);
	g.AddEdge(14, 15, 4);
	g.AddEdge(15, 17, 2);
	g.AddEdge(16, 17, 8);

	g.PrimMST();         // print the MST by Prim algorithm
	}