#include <iostream>
#include <queue>
#include <string.h> //因为使用了memset函数
using namespace std;

//先不考虑空间问题，这样会把问题复杂化
//所以先直接用完整的临界矩阵储存图结构
//而不考虑上下三角存储
int map[10][10] = { 0 };
int N, E, k = 0, node = 0;
bool visited[10] = { 0 };
int result[10] = { 0 };

void init() {
	memset(visited, 0, sizeof(visited));
	memset(result, 0, sizeof(result));		//太粗心。。。
	k = 0;	//k对结果集的下标进行保存
	node = 0;	//起始节点
}

void CreatGraph() {
	cin >> N >> E;
	int i = 0, j = 0;
	for (int k = 0; k < E; k++) {
		cin >> i >> j;
		map[i][j] = 1;
		map[j][i] = 1;
	}
	//上三角存储，但复杂化了后续操作
	/*int max = N*(N + 1) / 2;
	int *g = new int[max]();
	int i, j;
	for (int k = 0; k < E; k++)
	{
		cin >> i >> j;
		if (i > j) {
			g[(1 + i)*i / 2 + j] = 1;
		}
		else {
			g[(1 + j)*j / 2 + i] = 1;
		}
	}
	return g;*/
}

void DFS(int node) {
	visited[node] = 1;
	result[k++] = node;
	for (int i = 0; i < N; i++) {
		if (map[node][i] && !visited[i]) {
			//visited[i] = 1;	//这里注释的代码多余了
			DFS(i);
		}
	}
}

void BFS(int node) {
	queue<int> q;
	int top;
	q.push(node);
	visited[node] = 1;
	while (!q.empty()) {
		top = q.front();
		result[k++] = top;	//取队首元素时获得结果集元素
		q.pop();
		for (int i = 0; i < N; i++) {
			if (map[top][i] && !visited[i]) {	//每次查询有哪些节点与队首节点相连且未被访问
				q.push(i);
				visited[i] = 1;	//入队时立即设置为已访问！
			}
		}
	}
}

int main() {
	CreatGraph();
	//DFS:
	while (node < N) {
		if (!visited[node]) {
			k = 0;	//此处的k置为0，使result数组每次DFS刷新之前的result集
			DFS(node);
			cout << "{ ";
			for (int i = 0; i < k; i++) {
				cout << result[i] << " ";
			}
			cout << "}";
			cout << endl;
		}
		node++;
	}

	init();	//还原一些变量的初始值

	//BFS:
	while (node < N) {
		if (!visited[node]) {
			k = 0;
			BFS(node);
			cout << "{ ";
			for (int i = 0; i < k; i++) {
				cout << result[i] << " ";
			}
			cout << "}";
			cout << endl;
		}
		node++;
	}
	//system("pause");
	return 0;
}