#include <iostream>
#include <queue>
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
	}
	Visited = new bool[N] {0};
}

void Clear() {
	//收回内存空间
}

//难点:解决层数问题 
//有两种解决方案：1.在节点内部加上层数属性，但这样浪费空间 2.如下
int BFS(int v) {
	queue<int> q;
	q.push(v);
	Visited[v] = 1;
	int count = 1;	//计数器
	int level = 0;	//当前层数
	int last = v, tail = v;
	while (!q.empty()) {
		v = q.front();	//保存队首结点
		q.pop();	//出队列
		AdjNode *traverse= map[v].FirstEdge;
		while (traverse) {	//扫描当前结点的邻接结点
			if (!Visited[traverse->V]) {	//若未被访问，入队
				q.push(traverse->V);
				Visited[traverse->V] = 1;
				count++;	//每入队列，计数器加一
				tail = traverse->V;
				traverse = traverse->Next;
			}
		}
		if (v == last) {
			level++;
			last = tail;
		}
		if (level == 6)break;
	}
	return count;
}

void SDS() {
	int cnt = 0;
	for (int v = 0; v < N; v++) {
		cnt = BFS(v);
		cout << (cnt / N) << endl;
	}
}

int main() {
	InitGraph();
	//for (int v = 0; v < N; v++) {
	//	AdjNode *show = map[v].FirstEdge;
	//	while (show) {
	//		cout << show->V<<"	";
	//		show = show->Next;
	//	}
	//	cout << endl;
	//}
	SDS();
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