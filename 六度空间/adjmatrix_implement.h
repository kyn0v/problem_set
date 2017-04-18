#pragma once

#include "adjmatrix_implement.h"
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

#define MAXSIZE 100

class Matrix_Implement {
	int Matrix[MAXSIZE][MAXSIZE] = { 0 };
	bool *Visited;
	int N, V;

public:
	void InitGraph();
	int BFS(int v);
	void SDS();
};

