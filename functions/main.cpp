#include "linkedList.h"
#include "setOfStacks.h"
#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "linkedListFunctions.h"
#include "stack.h"
#include "queue.h"
#include "minMaxStack.h"
#include "setOfStacks.h"
#include "queueOfStacks.h"
#include "animalShelter.h"
#include "binaryTree.h"
#include "avlTree.h"
#include "graph.h"
#include "recursionAndDynamicProg.h"

using namespace std;
using fPtr = uint (*)(uint);

int main()
{
	/*** getNumSteps() ***/
	int n = 10;
	for(int i = 0 ; i < n ; i++)
	{
		cout << "rec of " << i << " printing solution: " << getNumStepsRec(i) << endl;
		cout << "itr of " << i << " printing solution: " << getNumSteps(i) << "\n" << endl;
	}

	/*** getPath() ***/
	uint grid[4][4];
	bool walls[4][4];

	uint **ptrGrid = new uint*[4];
	bool **ptrWalls = new bool*[4];

	for(uint i = 0 ; i < 4 ; i++)
	{
		ptrGrid[i] = new uint[4];
		ptrWalls[i] = new bool[4];
	}

	bool coinFlip;
	srand(time(NULL));

	for(uint i = 0 ; i < 4 ; i++)
	{
		for(uint j = 0 ; j < 4 ; j++)
		{
			grid[i][j] = (i*4 + j);
			ptrGrid[i][j] = (i*4 + j);

			coinFlip = rand() % 2;

			walls[i][j] = coinFlip;
			ptrWalls[i][j] = coinFlip;
		}
	}

	cout << "ptrGrid is:" << endl;
	for(uint i = 0 ; i < 4 ; i++)
	{
		for(uint j = 0 ; j < 4 ; j++)
		{
			cout << ptrGrid[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "ptrWalls is:" << endl;
	for(uint i = 0 ; i < 4 ; i++)
	{
		for(uint j = 0 ; j < 4 ; j++)
		{
			cout << ptrWalls[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "grid is:" << endl;
	for(uint i = 0 ; i < 4 ; i++)
	{
		for(uint j = 0 ; j < 4 ; j++)
		{
			cout << grid[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "walls is:" << endl;
	for(uint i = 0 ; i < 4 ; i++)
	{
		for(uint j = 0 ; j < 4 ; j++)
		{
			cout << walls[i][j] << "\t";
		}
		cout << endl;
	}

	vector<uint> path = traverseGrid(grid, walls);
	vector<uint> ptrPath = traverseGrid(ptrGrid, ptrWalls);

	cout << "path is:" << endl;
	for(uint i : path)
		cout << i << " ";

	cout << "\nptrPath is:" << endl;
	for(uint i : ptrPath)
		cout << i << " ";

	return 0;
}

