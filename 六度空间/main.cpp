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
int N;	//�����
int V;	//����
bool *Visited;


void InitGraph() {
	cin >> N >> V;
	map = new Node[N];
	int v, w;
	AdjNode *NewNode;
	for (int i = 0; i < V; i++) {	//���β����
		cin >> v >> w;
		v = v - 1;
		w = w - 1;	//�ӣ�����
		NewNode = new AdjNode(w, map[v].FirstEdge);	//�����ٽ��β�������������FirstEdge
		map[v].FirstEdge = NewNode;	//�������FirstEdge����ΪNewNode
		//����ͼҪ��������
		NewNode = new AdjNode(v, map[w].FirstEdge);	//�����ٽ��β�������������FirstEdge
		map[w].FirstEdge = NewNode;	//�������FirstEdge����ΪNewNode
	}
	Visited = new bool[N] {0};
}

void Clear() {
	//�ջ��ڴ�ռ�
}

//�ѵ�:����������� 
//�����ֽ��������1.�ڽڵ��ڲ����ϲ������ԣ��������˷ѿռ� 2.����
int BFS(int v) {
	queue<int> q;
	q.push(v);
	Visited[v] = 1;
	int count = 1;	//������
	int level = 0;	//��ǰ����
	int last = v, tail = v;
	while (!q.empty()) {
		v = q.front();	//������׽��
		q.pop();	//������
		AdjNode *traverse= map[v].FirstEdge;
		while (traverse) {	//ɨ�赱ǰ�����ڽӽ��
			if (!Visited[traverse->V]) {	//��δ�����ʣ����
				q.push(traverse->V);
				Visited[traverse->V] = 1;
				count++;	//ÿ����У���������һ
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
����������
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