#pragma once

#include "adjmatrix_implement.h"
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

#define MAXSIZE 100	//原先是10001,但是编译时显示"编译器堆栈空间不足!",于是改为100

class Matrix_Implement {
	int Matrix[MAXSIZE][MAXSIZE] = { 0 };
	bool *Visited;
	int N, V;

public:
	void InitGraph();
	int BFS(int v);
	void SDS();
};

