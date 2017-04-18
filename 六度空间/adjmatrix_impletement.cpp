#include "adjmatrix_implement.h"

void Matrix_Implement::InitGraph() {
	cin >> N >> V;
	Visited = new bool[N];	//初始化访问数组
	int v, w;
	for (int i = 0; i < V; i++) {
		cin >> v >> w;
		Matrix[v - 1][w - 1] = 1;
		Matrix[w - 1][v - 1] = 1;
	}
}
int Matrix_Implement::BFS(int v) {
	for (int i = 0; i < N; i++) {
		Visited[i] = 0;
	}
	queue<int> q;
	int count = 1;
	int level = 0;
	int last = v, tail = 0;
	//值得注意的问题是tail应初始化
	q.push(v);
	Visited[v] = 1;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int w = 0; w < N; w++) {
			if (Matrix[v][w] && !Visited[w]) {
				q.push(w);
				Visited[w] = 1;
				count++;
				tail = w;
			}
		}
		if (v == last) {
			level++;
			last = tail;
		}
		if (level == 6) {
			break;
		}
	}
	return count;
}
void Matrix_Implement::SDS() {
	double count = 0;
	cout.precision(2);
	cout.setf(ios::fixed);	//不带指数域
	for (int v = 0; v < N; v++) {
		count = BFS(v);
		cout << v + 1 << ": " << double(count / N) * 100 << "%" << endl;
	}
	delete[] Visited;
}