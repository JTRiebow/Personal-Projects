#include "Graph.h"

using namespace std;

Graph::Graph()
{
	numVertices = 0;
}

void Graph::AddEdge(string source, string target, int weight)
{
	int from;
	int to;

	for (int i = 0; i < numVertices; i++)
	{
		if (labels[i] == source)
		{
			from = i;
		}
	}
	for (int j = 0; j < numVertices; j++)
	{
		if (labels[j] == target)
		{
			to = j;
		}
	}
	matrix[from][to] = weight;
}

void Graph::AddVertex(string label)
{
	int newVertexNum;

	assert(numVertices < MAX_VERTECIES);
	newVertexNum = numVertices;
	++numVertices;
	for (int i = 0; i < numVertices; i++)
	{
		matrix[i][newVertexNum] = INT_MAX;
		matrix[newVertexNum][i] = INT_MAX;
	}
	labels[newVertexNum] = label;
}

int Graph::GetIndex(string label) const
{
	int index = -1;

	for (int i = 0; i < numVertices; i++)
	{
		if (labels[i] == label)
		{
			index = i;
		}
	}
	return index;
}

bool Graph::IsEdge(int sourceIndex, int targetIndex) const
{
	if (matrix[sourceIndex][targetIndex] != INT_MAX)
	{
		return true;
	}
	return false;
}

int Graph::GetWeight(int sourceIndex, int targetIndex) const
{
	return matrix[sourceIndex][targetIndex];
}

void Graph::BreadthFirstSearch(string startingVertex) const
{
	int visited[MAX_VERTECIES];
	cout << "starting BFS with vertex " << startingVertex << endl;

	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		visited[i] = -1;
	}

	BreadthFirstSearch(startingVertex, visited);
	cout << endl;
}

void Graph::BreadthFirstSearch(string startingVertex, int visited[]) const
{
	int index = 0;
	int vert;
	int startVert;
	queue<string> verts;
	bool * known = new bool[MAX_VERTECIES];

	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		known[i] = false;
	}
	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		if (labels[i] == startingVertex)
		{
			startVert = i;
			known[startVert] = true;
			verts.push(labels[startVert]);
		}
	}
	while (!verts.empty())
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (labels[i] == verts.front())
			{
				vert = i;
			}
		}
		visited[index] = vert;
		index++;
		cout << "\t" << " visited " << verts.front() << endl;
		verts.pop();
		for (int i = 0; i < numVertices; i++)
		{
			if (matrix[vert][i] != INT_MAX and known[i] == false)
			{
				verts.push(labels[i]);
				known[i] = true;
			}
		}
	}
}

void Graph::DijkstraShortestPath(string startingVertex) const
{
	int * distance = new int[MAX_VERTECIES];
	int * prevVertex = new int[MAX_VERTECIES];

	cout << "Shortest Distance starting from vertex " << startingVertex << endl;
	DijkstraShortestPath(startingVertex, distance, prevVertex);
	cout << endl;
}

void Graph::DijkstraShortestPath(string startingVertex, int distance[], int prevVertex[]) const
{
	int index;
	bool known[MAX_VERTECIES];
	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		distance[i] = INT_MAX;
		prevVertex[i] = -1;
	}

	for (int i = 0; i < MAX_VERTECIES; i++)   // Fill known with false
	{
		known[i] = false;
	}
	for (int i = 0; i < MAX_VERTECIES; i++)   // Find the starting vertex
	{
		if (labels[i] == startingVertex)
		{
			distance[i] = 0;
			index = i;
		}
	}
	while (known[index] != true)   
	{
		known[index] = true;
		for (int i = 0; i < numVertices; i++)
		{
			if (matrix[index][i] != INT_MAX and known[i] == false)
			{
				if (distance[i] > matrix[index][i] + distance[index])
				{
					distance[i] = matrix[index][i] + distance[index];
				}
				prevVertex[i] = index;
			}
		}
		int target = INT_MAX;
		for (int i = 0; i < numVertices; i++)
		{
			if (known[i] != true and distance[i] != INT_MAX and distance[i] != 0 and target == INT_MAX)
			{
				target = i;
			}
			if (known[i] != true and distance[i] != INT_MAX and distance[i] != 0 and distance[i] < distance[target])
			{
				target = i;
			}
		}
		if (target != INT_MAX)
		{
			index = target;
		}
	}
	for (int i = 0; i < numVertices; i++)
	{
		cout << "\t" << "to: " << labels[i] << "\t";
		if (distance[i] == INT_MAX) 
		{
			cout << "no path" << endl;
		}
		else
		{
			cout << distance[i] << "\t" << "Path:";
			int vertex_on_path = i;
			cout << " " << labels[i];
			while (labels[vertex_on_path] != startingVertex)
			{
				vertex_on_path = prevVertex[vertex_on_path];
				cout << ", " << labels[vertex_on_path];
			}
			cout << endl;
		}
	}
}

void Graph::PrintGraph() const
{
	cout << "numVerticies: " << numVertices << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << "\t" << labels[i];
	}
	cout << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << labels[i];
		for (int j = 0; j < numVertices; j++)
		{
			cout << "\t";
			if (matrix[i][j] != INT_MAX)
			{
				cout << matrix[i][j];
			}
		}
		cout << endl;
	}
}

int Graph::minDistance(int distance[], bool known[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		if (known[i] == false and distance[i] <= min)
		{
			min = distance[i], min_index = i;
		}
	}
	return min_index;
}
