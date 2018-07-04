#ifndef TREES_GRAPH_H_
#define TREES_GRAPH_H_

#include <iostream>
#include <vector>
#include "stack.h"
#include "queue.h"

using uint = unsigned int;

using namespace std;

class Graph
{
    uint size;
    vector<vector<uint>> adjList;

public:
    Graph(uint size);
    void addEdge(uint vert, uint edge);
    void BFS(uint startVert);
    void DFS(uint startVert);

    void recDFS(uint startVert);
    void recDFS(uint recStartVert, vector<bool> &visited);

    bool routeToNode(uint start, uint end);
};

Graph::Graph(uint size)
{
	this -> size = size;

	for(uint i = 0 ; i < size; i++)
	{
		vector<uint> vec;
		this -> adjList.push_back(vec);
	}
}

void Graph::addEdge(uint vert, uint edge)
{
	adjList[vert].push_back(edge);
}

void Graph::BFS(uint startVert)
{
	vector<bool> visited;
	Queue<uint> qu;

	for(uint i = 0 ; i < this -> size ; i++)
		visited.push_back(false);

	qu.push(startVert);
	visited[startVert] = true;

	while(!qu.isEmpty())
	{
		uint currVert = qu.pop();

		for(uint i : this -> adjList[currVert])
		{
			if(!visited[i])
			{
				visited[i] = true;
				qu.push(i);
			}
		}

		cout << currVert << " ";
	}
}

void Graph::DFS(uint startVert)
{
	vector<bool> visited;
	Stack<uint> st;

	for(uint i = 0 ; i < this -> size ; i++)
		visited.push_back(false);

	st.push(startVert);
	visited[startVert] = true;

	while(!st.isEmpty())
	{
		uint currVert = st.pop();

		for(uint i : this -> adjList[currVert])
		{
			if(!visited[i])
			{
				visited[i] = true;
				st.push(i);
			}
		}

		cout << currVert << " ";
	}
}

void Graph::recDFS(uint startVert)
{
	vector<bool> visited;

	for(uint i = 0 ; i < this -> size ; i++)
		visited.push_back(false);

	visited[startVert] = true;

	recDFS(startVert, visited);
}

void Graph::recDFS(uint recStartVert, vector<bool> &visited)
{
	cout << recStartVert << " ";

	for(uint &i : this -> adjList[recStartVert])
	{
		if(!visited[i])
		{
			visited[i] = true;
			recDFS(i, visited);
		}
	}

}

bool Graph::routeToNode(uint start, uint end)
{
	vector<bool> visited;
	Queue<uint> qu;

	for(uint i = 0 ; i < this -> size ; i++)
		visited.push_back(false);

	qu.push(start);
	visited[start] = true;

	while(!qu.isEmpty())
	{
		uint currVert = qu.pop();

		for(uint &i : this -> adjList[currVert])
		{
				if(i == end)
					return true;

				if(!visited[i])
				{
					visited[i] = true;
					qu.push(i);
				}
		}
	}

	return false;
}


#endif /* TREES_GRAPH_H_ */
