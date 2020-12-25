#include <iostream>
#include <climits>
#include "Graph.h"

using namespace std;

// Test 1  Vertex
bool testPassed() {
	Graph g;
	g.AddVertex("Brown");
	g.AddVertex("Cow");
	g.AddVertex("Now");

	int brownIndex = g.GetIndex("Brown");
	int cowIndex = g.GetIndex("Cow");
	int nowIndex = g.GetIndex("Now");
	int badIndex = g.GetIndex("Junk");

	if (brownIndex < 0 || brownIndex > 2)
	{
		cout << "Index of vertex Brown is not correct" << std::endl;
		return false;
	}
	if (cowIndex < 0 || cowIndex > 2)
	{
		cout << "Index of vertex Cow is not correct" << std::endl;
		return false;
	}
	if (nowIndex < 0 || nowIndex > 2)
	{
		cout << "Index of vertex Now is not correct" << std::endl;
		return false;
	}
	if (badIndex >= 0)
	{
		cout << "Index of invalid vertex is not correct" << std::endl;
		return false;
	}

	if (brownIndex == cowIndex ||
		cowIndex == nowIndex)
	{
		cout << "Multiple vertex labels map to the same index number" << std::endl;
		return false;
	}


	g.AddEdge("Brown", "Cow", 123);
	g.AddEdge("Cow", "Brown", 321);

	if (g.GetWeight(brownIndex, cowIndex) != 123)
	{
		cout << "Incorrect weight between to edges (Brown to Cow)" << std::endl;
		return false;
	}
	if (g.GetWeight(cowIndex, brownIndex) != 321)
	{
		cout << "Incorrect weight between to edges (Cow to Brown)" << std::endl;
		return false;
	}
	if (g.GetWeight(cowIndex, nowIndex) < 32767)
	{
		cout << "Incorrect weight for no-path" << std::endl;
		return false;
	}

	return true;
}

int main()
{
	Graph g;

	testPassed();

	g.AddVertex("A");
	g.AddVertex("B");
	g.AddVertex("C");
	g.AddVertex("D");
	g.AddVertex("E");
	g.AddVertex("F");

	g.AddEdge("A", "B", 2);
	g.AddEdge("A", "F", 9);

	g.AddEdge("B", "F", 6);
	g.AddEdge("B", "D", 15);
	g.AddEdge("B", "C", 8);

	g.AddEdge("C", "D", 1);

	g.AddEdge("E", "C", 7);
	g.AddEdge("E", "D", 3);

	g.AddEdge("F", "E", 3);

	g.PrintGraph();

	g.BreadthFirstSearch("A");

	g.DijkstraShortestPath("A");
	g.DijkstraShortestPath("B");
	g.DijkstraShortestPath("C");
	g.DijkstraShortestPath("D");
	g.DijkstraShortestPath("E");
	g.DijkstraShortestPath("F");
}