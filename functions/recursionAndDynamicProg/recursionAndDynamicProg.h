#ifndef RECURSIONANDDYNAMICPROG_RECURSIONANDDYNAMICPROG_H_
#define RECURSIONANDDYNAMICPROG_RECURSIONANDDYNAMICPROG_H_

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stack>
using uint = unsigned int;

int getNumStepsRec(int n);
void getNumStepsRec(int n, int &count);

int getNumSteps(int n);


std::vector<uint> traverseGrid(uint **grid, bool **walls);
std::vector<uint> traverseGrid(uint grid[][4], bool walls[][4]);


#endif /* RECURSIONANDDYNAMICPROG_RECURSIONANDDYNAMICPROG_H_ */
