#include <iostream>
using namespace std;

#define MAXSIZE 101
#define INFINITY 101

typedef int Vertex;
typedef int TYPEWEIGHT;

int Graph[MAXSIZE][MAXSIZE];
int N, V;

void Build() {
	cin >> N >> V;
	Vertex v, w;
	int weight;
	for (int i = 0; i < V; i++) {
		cin >> v >> w >> weight;
		v = v - 1;
		w = w - 1;	//��û�����ԡ���
		Graph[v][w] = weight;
		Graph[w][v] = weight;
	}
}

void Floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Graph[i][k] + Graph[k][j] < Graph[i][j]) {
					Graph[i][j] = Graph[i][k] + Graph[k][j];
				}
			}
		}
	}
}

struct Max
{
	int weight;
	int index;
	Max():weight(0),index(-1) {}
};

void FindAnimal() {
	Floyd();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	Max max[MAXSIZE];

	for (int i = 0; i < N; i++) {	//�ҳ�ÿ�е����ֵ
		for (int j = 0; j < N; j++) {
			if (Graph[i][j]>max[i].weight) {
				max[i].weight = Graph[i][j];
				max[i].index = j;
			}
		}
	}
	
	int min_weight = INFINITY;
	int min_vertex;
	int row;
	for (row = 0; row < N; row++) {	//�ҳ����ֵ�е���Сֵ
		if (max[row].weight < min_weight) {
			min_weight = max[row].weight;
			min_vertex = max[row].index;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << row << " " << min_weight;
}

int main() {
	//����ͼ
	Build();
	//����ͼ
	FindAnimal();
	return 0;
}

/*
��������
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
 */