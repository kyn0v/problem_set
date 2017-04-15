#include <iostream>
using namespace std;

#define YES 1
#define NO 0
//当前坐标(0,0)

struct Position {
	int x;
	int y;
};

Position *node;	//每个鳄鱼的坐标
bool *visited;
int N;	//鳄鱼数量
int D;	//最大距离
int answer = NO;	//结果

void InitGraph() {
	cin >> N >> D;
	node = new Position[N];
	visited = new bool[N];
	for (int v = 0; v < N; v++) {
		cin >> node[v].x >> node[v].y;
		visited[v] = 0;
	}
}

bool FirstJump(int v) {	//第一跳
	int dx = abs(node[v].x - 0);
	int dy = abs(node[v].y - 0);
	if (dx*dx + dy*dy <= D*D) {
		return true;
	}
	return false;
}

bool IsSafe(int v) {	//安全跳出水池
	if (node[v].x + D >= 50 || node[v].x - D <= -50 ||
		node[v].y + D >= 50 || node[v].y - D <= -50) {
		return true;
	}
	return false;
}

bool Jump(int v, int w) {	//判断是否能跳达
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
			if (!visited[w] && Jump(v,w)) {	//还应满足能够跳到w结点上
				answer = DFS(w);
				if (answer == YES)break;	//注意这里的终止条件，第一次写时就给忘了。。
			}
		}
	}
	return answer;
}

void ListComponent() {	//搜索存在安全结点的连通集
	if (N == 0 && D >= 50) {
		answer = YES;
	}
	for (int v = 0; v < N; v++) {
		if (!visited[v] && FirstJump(v)) {	//还应满足第一步能够到达
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
在这种无向图里，表示图只是为了确定图之间是否有“边”，
在这个例子中，这个功能被jump，issafe和firstjump函数替代了
--via 当个码农吧
*/
