#include <iostream>
#include <queue>
using namespace std;

typedef int Vertex;
#define MAXWEIGHT 999

int N, V;
int map[10][10];
int visited[10];
int dist[10];	//������ʼ�㵽�����ڵ����̾���
int path[10] = {-1};	//��¼·��
queue<int> q;

void Init(int s) {
	//��ʼ������
	dist[s] = 0;
	std::fill(visited, visited + 10, 0);
	std::fill(dist, dist + 10, MAXWEIGHT);
	std::fill(path, path + 10, -1);
}

void BFS(Vertex s) {	//ԭʼ��BFS
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

void Unweighted (Vertex s) {	//��Ȩͼ�ĵ�Դ���·���㷨:·����������·���
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
	//����һ��ֱ��ɨ������δ��¼�Ķ���---���ڳ���ͼЧ����
	for (int i = 0; i < N; i++) {
		if (!collected[i] && dist[i] < MinDist) {
			MinDist = dist[i];
			MinV = i;
		}
	}
	//����������dist������С���У�Ҫע��ÿ�θ���dist��ֵʱ����ҲӦ��Ӧ����


	return MinV;	//��û���ҵ���Сֵ,�򷵻س�ʼֵ-1��
}

void Dijkstra(int s) {	//��Ȩͼ�ĵ�Դ���·����·��������·��һ�����
	//�ؼ�:���յ���˳���ҳ�����㵽������������·
	//Dikstra�㷨
	//ע�⣺ÿ�ս�һ������vi���뼯�ϣ����ܻ�Ӱ��vi��һȦ�ڽӵ��distֵ�����Ҫ���м��;
	//	dist[w]=min{dist[w],dist[v]+<v,w>��Ȩ��}

	//��ʼ��dist����
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
		v = Min(dist);	//�ҳ�δ��¼�����е�dist��С��,������¼
		if (v == -1) {	//��������
			break;
		}
		collected[v] = true;
		for (Vertex w = 0; w < N && map[v][w] < SIZE_MAX; w++) {	//���ո���¼�ĵ�v���ڽӵ��dist�Ƿ��ܵ���v��Ӱ��
			if (collected[w] == 0) {
				if (map[v][w] < 0) {
					return;	//���и��ߣ�������ȷ���������ֱ�ӷ���
				}
				if (dist[v] + map[v][w] < dist[w]) {
					dist[w] = dist[v] + map[v][w];
					path[w] = v;
				}
			}
		}
	}
}	//���ܽ����������,�������ﲻ���Ǹ�ֵȦ

int D[10][10];
int pathFloyd[10][10];
void Floyd(int s) {	//��Դ���·�㷨
	//��ʼ��
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			D[i][j] = map[i][j];
		}
	}

	for (int k = 0; k < N; k++) {	//���μ�����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					pathFloyd[i][j] = k;
					/*
					������̣�
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
	//����Ϊ��¼��ѧϰ���̣����ܴ���������⣬���ؼ�����ѧϰ���㷨˼��
}