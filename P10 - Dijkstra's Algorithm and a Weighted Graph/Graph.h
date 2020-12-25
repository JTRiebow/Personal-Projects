#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <list>

using namespace std;

class Graph
{
public:
	Graph();
	~Graph() = default;
	void AddEdge(string source, string target, int weight);
	void AddVertex(string label);
	int GetIndex(string label) const;
	bool IsEdge(int sourceIndex, int targetIndex) const;
	int GetWeight(int sourceIndex, int targetIndex) const;
	void BreadthFirstSearch(string startingVertex) const;
	void BreadthFirstSearch(string startingVertex, int visited[]) const;
	void DijkstraShortestPath(string startingVertex) const;
	void DijkstraShortestPath(string startingVertex, int distance[], int prevVertex[]) const;
	void PrintGraph() const;
	static const int MAX_VERTECIES = 10;
	int minDistance(int distance[], bool known[]);

private:
	int numVertices;
	int matrix[MAX_VERTECIES][MAX_VERTECIES];
	string labels[MAX_VERTECIES];
};