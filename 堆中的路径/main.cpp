#include <iostream>
using namespace std;

#define MAXN 1001
#define MINH -10001

int Min_Heap[MAXN], size;

void Create() {
	::size = 0;
	Min_Heap[0] = MINH;	//设置岗哨
}

void Insert(int X) {
	if (::size < MAXN) {
		int i;
		//因为之前设置了哨兵，因此这里判断条件可以省略i>0
		for (i = ++::size; Min_Heap[i / 2] > X; i = i / 2) {
			Min_Heap[i] = Min_Heap[i / 2];	//依次下移
		}
		Min_Heap[i] = X;
	}
}

int main() {
	int n, m, x, i, j;
	cin >> n >> m;
	Create();
	for (i = 0; i < n; i++) {
		cin >> x;
		Insert(x);
	}
	for (i = 0; i < m; i++) {
		cin >> j;
		while (j > 1) {
			cout << Min_Heap[j] << " ";
			j = j / 2;
		}
		cout << Min_Heap[j] << endl;
	}
	//system("pause");
	return 0;
}