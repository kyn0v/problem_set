#include <iostream>
using namespace std;

#define YES 1
#define NO 0
//��ǰ����(0,0)

struct Position {
	int x;
	int y;
};

Position *node;	//ÿ�����������
bool *visited;
int N;	//��������
int D;	//������
int answer = NO;	//���

void InitGraph() {
	cin >> N >> D;
	node = new Position[N];
	visited = new bool[N];
	for (int v = 0; v < N; v++) {
		cin >> node[v].x >> node[v].y;
		visited[v] = 0;
	}
}

bool FirstJump(int v) {	//��һ��
	int dx = abs(node[v].x - 0);
	int dy = abs(node[v].y - 0);
	if (dx*dx + dy*dy <= D*D) {
		return true;
	}
	return false;
}

bool IsSafe(int v) {	//��ȫ����ˮ��
	if (node[v].x + D >= 50 || node[v].x - D <= -50 ||
		node[v].y + D >= 50 || node[v].y - D <= -50) {
		return true;
	}
	return false;
}

bool Jump(int v, int w) {	//�ж��Ƿ�������
	int dx = abs(node[v].x - node[w].x);
	int dy = abs(node[v].y - node[w].y);
	if (dx*dx + dy*dy <= D*D) {
		return true;
	}
	return false;
}

bool DFS(int v) {
	int answer = 0;
	visited[v] = 1;
	if (IsSafe(v)) answer = YES;
	else {
		for (int w = 0; w < N; w++) {
			if (!visited[w] && Jump(v,w)) {	//��Ӧ�����ܹ�����w�����
				answer = DFS(w);
				if (answer == YES)break;	//ע���������ֹ��������һ��дʱ�͸����ˡ���
			}
		}
	}
	return answer;
}

void ListComponent() {	//�������ڰ�ȫ������ͨ��
	if (N == 0 && D >= 50) {
		answer = YES;
	}
	for (int v = 0; v < N; v++) {
		if (!visited[v] && FirstJump(v)) {	//��Ӧ�����һ���ܹ�����
			answer = DFS(v);
			if (answer == YES) break;
		}
	}
	if (answer == YES)cout << "Yes";
	else cout << "No";
}

int main() {
		InitGraph();
		ListComponent();
		delete[] visited;
		delete[] node;
}

/*
����������ͼ���ʾͼֻ��Ϊ��ȷ��ͼ֮���Ƿ��С��ߡ���
����������У�������ܱ�jump��issafe��firstjump���������
--via ������ũ��
*/
