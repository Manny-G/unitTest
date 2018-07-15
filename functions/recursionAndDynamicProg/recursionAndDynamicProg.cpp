#include "recursionAndDynamicProg.h"

int getNumStepsRec(int n)
{
	if(n <= 0)
		return 0;

	int count = 0;
	getNumStepsRec(n, count);

	return count;
}

void getNumStepsRec(int n, int &count)
{
	if(n < 0)
		return;

	else if(n == 0)
		count++;

	getNumStepsRec(n - 1, count);
	getNumStepsRec(n - 2, count);
	getNumStepsRec(n - 3, count);
}

int getNumSteps(int n)
{
	if(n <= 0)
		return 0;

	std::vector<int> vec;
	int itr = 0;

	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);

	for(int i = 4 ; i <= n ; i++)
	{
		itr = vec[i - 1] + vec[i - 2] + vec[i - 3];
		vec.push_back(itr);
	}

	return vec[n];
}

std::vector<uint> traverseGrid(uint **grid, bool **walls)
{
	std::vector<uint> vec;
	std::vector<bool> seen;

	for(uint i = 0 ; i < 16 ; i++)
		seen.push_back(false);

	std::pair<uint, uint> p = std::make_pair(0, 0);
	std::stack< std::pair<uint, uint> > st;
	st.push(p);
	seen[ (p.first * 4) + p.second ] = true;

	while(!st.empty())
	{
		p = st.top();
		st.pop();

		if( (p.first + 1 < 4) && !walls[p.first + 1][p.second] && !seen[ ( (p.first + 1) * 4 ) + p.second ])
		{
			st.push( std::make_pair(p.first + 1, p.second) );
			seen[ ( (p.first + 1) * 4 ) + p.second ] = true;
		}

		if( (p.second + 1 < 4) && !walls[p.first][p.second + 1] && !seen[ (p.first * 4) + (p.second + 1) ])
		{
			st.push( std::make_pair(p.first, p.second + 1) );
			seen[ (p.first * 4) + (p.second + 1) ];
		}

		vec.push_back(grid[p.first][p.second]);

		if(p.first == 3 && p.second == 3)
			return vec;
	}

	return vec;
}

std::vector<uint> traverseGrid(uint grid[][4], bool walls[][4])
{
	std::vector<uint> vec;
	std::vector<bool> seen;

	for(uint i = 0 ; i < 16 ; i++)
		seen.push_back(false);

	std::pair<uint, uint> p = std::make_pair(0, 0);
	std::stack< std::pair<uint, uint> > st;
	st.push(p);
	seen[ (p.first * 4) + p.second ] = true;

	while(!st.empty())
	{
		p = st.top();
		st.pop();

		if( (p.first + 1 < 4) && !walls[p.first + 1][p.second] && !seen[ ( (p.first + 1) * 4 ) + p.second ])
		{
			st.push( std::make_pair(p.first + 1, p.second) );
			seen[ ( (p.first + 1) * 4 ) + p.second ] = true;
		}

		if( (p.second + 1 < 4) && !walls[p.first][p.second + 1] && !seen[ (p.first * 4) + (p.second + 1) ])
		{
			st.push( std::make_pair(p.first, p.second + 1) );
			seen[ (p.first * 4) + (p.second + 1) ];
		}

		vec.push_back(grid[p.first][p.second]);

		if(p.first == 3 && p.second == 3)
			return vec;
	}

	return vec;
}

