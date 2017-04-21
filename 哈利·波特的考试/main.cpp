#include <iostream>
using namespace std;

#define MAXSIZE 10001
#define MAXWEIGHT 99999

int N, V;

int dist[MAXSIZE][MAXSIZE];
int *Path;

void Build() {
	cin >> N >> V;
	int v, w, weight;
	Path = new int[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 999;
		}
	}
	for (int i = 0; i < V; i++) {
		cin >> v >> w >> weight;
		dist[v][w] = weight;
		dist[w][v] = weight;
	}
}

void Floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void FindAnimal(MGraph G) {

}

int main() {
	//¶ÁÈëÍ¼
	MGraph G = Build();
	//·ÖÎöÍ¼
	FindAnimal(G);
	return 0;
}

/*
²âÊÔÓÃÀý
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