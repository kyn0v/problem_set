#include <iostream>
#include <queue>
using namespace std;

typedef int Vertex;
#define MAXWEIGHT 999

int N, V;
int map[10][10];
int visited[10];
int dist[10];	//保存起始点到其他节点的最短距离
int path[10] = {-1};	//记录路径
queue<int> q;

void Init(int s) {
	//初始化操作
	dist[s] = 0;
	std::fill(visited, visited + 10, 0);
	std::fill(dist, dist + 10, MAXWEIGHT);
	std::fill(path, path + 10, -1);
}

void BFS(Vertex s) {	//原始的BFS
	q.push(s);
	visited[s] = true;
	int v;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int w = 0; w < N && map[v][w]; w++) {
			if (!visited[w]) {
				q.push(w);
				visited[w] = true;
			}
		}
	}
}

void Unweighted (Vertex s) {	//无权图的单源最短路径算法:路径数最少则路最短
	q.push(s);
	int v;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int w = 0; w < N && map[v][w]; w++)
		{
			if (dist[w] == -1) {
				dist[w] == dist[v] + 1;
				path[w] = v;
				q.push(w);
			}
		}
	}
}

int collected[10] = { 0 };
int Min(int dist[]) {
	int MinDist = MAXWEIGHT;
	int MinV = -1;
	//方法一：直接扫描所有未收录的顶点---对于稠密图效果好
	for (int i = 0; i < N; i++) {
		if (!collected[i] && dist[i] < MinDist) {
			MinDist = dist[i];
			MinV = i;
		}
	}
	//方法二：将dist存在最小堆中，要注意每次更新dist的值时，堆也应相应调整


	return MinV;	//若没有找到最小值,则返回初始值-1；
}

void Dijkstra(int s) {	//有权图的单源最短路径：路径数最少路不一定最短
	//关键:按照递增顺序找出，起点到各个顶点的最短路
	//Dikstra算法
	//注意：每收进一个顶点vi进入集合，可能会影响vi的一圈邻接点的dist值，因此要进行检查;
	//	dist[w]=min{dist[w],dist[v]+<v,w>的权重}

	//初始化dist数组
	for (Vertex w = 0; w < N; w++) {
		if (map[s][w] < MAXWEIGHT) {
			dist[w] = map[s][w];
			path[w] = s;
		}
	}
	dist[s] = 0;
	collected[s] = true;

	int v;
	while (true) {
		v = Min(dist);	//找出未收录顶点中的dist最小者,将其收录
		if (v == -1) {	//若不存在
			break;
		}
		collected[v] = true;
		for (Vertex w = 0; w < N && map[v][w] < SIZE_MAX; w++) {	//检查刚刚收录的点v的邻接点的dist是否受到了v的影响
			if (collected[w] == 0) {
				if (map[v][w] < 0) {
					return;	//如有负边，不能正确解决，函数直接返回
				}
				if (dist[v] + map[v][w] < dist[w]) {
					dist[w] = dist[v] + map[v][w];
					path[w] = v;
				}
			}
		}
	}
}	//不能解决负边问题,所以这里不考虑负值圈

int D[10][10];
int pathFloyd[10][10];
void Floyd(int s) {	//多源最短路算法
	//初始化
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			D[i][j] = map[i][j];
		}
	}

	for (int k = 0; k < N; k++) {	//依次加入结点
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					pathFloyd[i][j] = k;
					/*
					输出过程：
					PrintPath(path[i][k])
					PrintPath(k)
					PrintPath(path[k][j])
					*/
				}
			}
		}
	}
}

int main() {
	//以上为记录的学习过程，可能代码会有问题，但关键在于学习的算法思想
}