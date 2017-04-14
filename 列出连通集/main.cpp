#include <iostream>
#include <queue>
#include <string.h> //��Ϊʹ����memset����
using namespace std;

//�Ȳ����ǿռ����⣬����������⸴�ӻ�
//������ֱ�����������ٽ���󴢴�ͼ�ṹ
//���������������Ǵ洢
int map[10][10] = { 0 };
int N, E, k = 0, node = 0;
bool visited[10] = { 0 };
int result[10] = { 0 };

void init() {
	memset(visited, 0, sizeof(visited));
	memset(result, 0, sizeof(result));		//̫���ġ�����
	k = 0;	//k�Խ�������±���б���
	node = 0;	//��ʼ�ڵ�
}

void CreatGraph() {
	cin >> N >> E;
	int i = 0, j = 0;
	for (int k = 0; k < E; k++) {
		cin >> i >> j;
		map[i][j] = 1;
		map[j][i] = 1;
	}
	//�����Ǵ洢�������ӻ��˺�������
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
			//visited[i] = 1;	//����ע�͵Ĵ��������
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
		result[k++] = top;	//ȡ����Ԫ��ʱ��ý����Ԫ��
		q.pop();
		for (int i = 0; i < N; i++) {
			if (map[top][i] && !visited[i]) {	//ÿ�β�ѯ����Щ�ڵ�����׽ڵ�������δ������
				q.push(i);
				visited[i] = 1;	//���ʱ��������Ϊ�ѷ��ʣ�
			}
		}
	}
}

int main() {
	CreatGraph();
	//DFS:
	while (node < N) {
		if (!visited[node]) {
			k = 0;	//�˴���k��Ϊ0��ʹresult����ÿ��DFSˢ��֮ǰ��result��
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

	init();	//��ԭһЩ�����ĳ�ʼֵ

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