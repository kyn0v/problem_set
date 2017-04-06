#include <iostream>
using namespace std;

struct Element{
	int parent;
	Element() :parent(-1) {};
	Element(int _parent) :parent(_parent) {};
};

int Find(Element *Union,int k) {
	//当parent<0时，说明为根节点,直接返回下标
	while (Union[k].parent > 0) {
		k = Union[k].parent;
	}
	return k;
}

int main() {
	int size;
	cin >> size;
	Element *Union = new Element[size + 1];	//从下标为1开始计
	char flag = '0';
	int i, j;
	while (1) {
		cin >> flag;
		if (flag == 'S') {
			break;
		}
		cin >> i >> j;
		//找到根节点
		int root1 = Find(Union, i);
		int root2 = Find(Union, j);
		switch (flag) {
		case 'C':
			if (root1 == root2) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
			break;
		case 'I':
			if (root1 != root2) {
				if (abs(Union[root1].parent) >= abs(Union[root2].parent)) {
					Union[root2].parent = root1;
					Union[root1].parent -= abs(Union[root2].parent);
				} else {
					Union[root1].parent = root2;
					Union[root2].parent -= abs(Union[root1].parent);
				}
			}
			break;
		default:
			cout << "Wrong Input!" << endl;
			break;
		}
	}
	int cnt = 0;

	for (int i = 1; i < size + 1; i++) {
		if (Union[i].parent < 0) {
			cnt++;
		}
	}
	if (cnt == 1) {
		cout << "The network is connected." << endl;
	} else {
		cout << "There are " << cnt << " components." << endl;
	}
	//system("pause");
	return 0;
}