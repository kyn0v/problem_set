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
int N;	//�����
int V;	//����
bool *Visited;


void InitGraph() {
	cin >> N >> V;
	map = new Node[N];
	Visited = new bool[N];
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
		
		Visited[i] = 0;
	}
}

void Clear() {
	//�ջ��ڴ�ռ�
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


//�ѵ�:����������� 
//�����ֽ��������1.�ڽڵ��ڲ����ϲ������ԣ��������˷ѿռ� 2.����
int BFS(int v) {
	queue<int> q;	//ÿ����һ�κ�������һ�ζ��У�������ȫ�ֶ���,ÿ�ζ����ﶼ�в���
	q.push(v);
	Visited[v] = 1; int count = 1;	//������
	int level = 0;	//��ǰ����
	int last = v, tail;
	AdjNode *traverse = map[v].FirstEdge;	//���ָ��������ѭ�������
	if (traverse) {
		tail = traverse->V;
		while (!q.empty()) {
			v = q.front();	//������׽��
			q.pop();	//������
			traverse = map[v].FirstEdge;
			while (traverse) {	//ɨ�赱ǰ���������ڽӽ��
				if (!Visited[traverse->V]) {	//��δ�����ʣ����
					q.push(traverse->V);
					Visited[traverse->V] = 1; count++;	//ÿ����У���������һ
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
		cout.setf(ios::fixed);	//����ָ����
		cout << v + 1 << ": " << setprecision(2) << double(cnt / N) * 100 << "%" << endl;
		//v+1����һ���ӣ�����
		for (int i = 0; i < N; i++) {	//��ԭVisited����
			Visited[i] = 0;
		}
	}
}

int main() {
	cout << "����������" << endl;
	InitGraph();
	SDS();
	Clear();
	cout << "����������" << endl;
	Matrix_Implement m;
	m.InitGraph();
	m.SDS();
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