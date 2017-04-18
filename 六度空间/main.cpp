#include <iostream>
#include <queue>
#include <iomanip>
#include "adjmatrix_implement.h"

using namespace std;

struct AdjNode
{
	int V;
	AdjNode *Next;
	AdjNode(int v, AdjNode *n) :V(v), Next(n) {}
};

struct Node {
	AdjNode *FirstEdge;
	Node() :FirstEdge(NULL) {}
};

Node *map;
int N;	//结点数
int V;	//边数
bool *Visited;


void InitGraph() {
	cin >> N >> V;
	map = new Node[N];
	Visited = new bool[N];
	int v, w;
	AdjNode *NewNode;
	for (int i = 0; i < V; i++) {	//依次插入边
		cin >> v >> w;
		v = v - 1;
		w = w - 1;	//坑！！！
		NewNode = new AdjNode(w, map[v].FirstEdge);	//新增临界点尾部接上主数组的FirstEdge
		map[v].FirstEdge = NewNode;	//主数组的FirstEdge更新为NewNode
		//无向图要插入两次
		NewNode = new AdjNode(v, map[w].FirstEdge);	//新增临界点尾部接上主数组的FirstEdge
		map[w].FirstEdge = NewNode;	//主数组的FirstEdge更新为NewNode
		
		Visited[i] = 0;
	}
}

void Clear() {
	//收回内存空间
	AdjNode *cur,*temp;
	for (int i = 0; i < N; i++) {
		cur = map[i].FirstEdge;
		while (cur) {
			temp = cur->Next;
			delete cur;
			cur = temp;
		}
	}
}


//难点:解决层数问题 
//有两种解决方案：1.在节点内部加上层数属性，但这样浪费空间 2.如下
int BFS(int v) {
	queue<int> q;	//每调用一次函数构造一次队列，若共用全局队列,每次队列里都有残留
	q.push(v);
	Visited[v] = 1; int count = 1;	//计数器
	int level = 0;	//当前层数
	int last = v, tail;
	AdjNode *traverse = map[v].FirstEdge;	//这个指针声明在循环外更好
	if (traverse) {
		tail = traverse->V;
		while (!q.empty()) {
			v = q.front();	//保存队首结点
			q.pop();	//出队列
			traverse = map[v].FirstEdge;
			while (traverse) {	//扫描当前结点的所有邻接结点
				if (!Visited[traverse->V]) {	//若未被访问，入队
					q.push(traverse->V);
					Visited[traverse->V] = 1; count++;	//每入队列，计数器加一
					tail = traverse->V;
				}
				traverse = traverse->Next;
			}
			if (v == last) {
				level++;
				last = tail;
			}
			if (level == 6)break;
		}
	}
	return count;
}

void SDS() {
	double cnt = 0;
	for (int v = 0; v < N; v++) {
		cnt = BFS(v);
		cout.setf(ios::fixed);	//不带指数域
		cout << v + 1 << ": " << setprecision(2) << double(cnt / N) * 100 << "%" << endl;
		//v+1又是一个坑！！！
		for (int i = 0; i < N; i++) {	//还原Visited数组
			Visited[i] = 0;
		}
	}
}

int main() {
	cout << "输入用例：" << endl;
	InitGraph();
	SDS();
	Clear();
	cout << "输入用例：" << endl;
	Matrix_Implement m;
	m.InitGraph();
	m.SDS();
}
/*
测试用例：
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/