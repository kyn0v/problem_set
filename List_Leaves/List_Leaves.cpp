#include <iostream>
#include <queue>
using namespace std;

#define Maxtree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
	Tree Left;
	Tree Right;
}T[Maxtree];

Tree BuildTree(TreeNode T[]) {	//建树
	int size = 0, root = Null;
	cin >> size;
	char temp_char;
	int check[Maxtree];
	if (size) {
		for (int i = 0; i < size; i++)check[i] = 0;	//初始化前size个数据，因为只会用的到size个
		for (int i = 0; i < size; i++) {	//输入数据
			cin >> temp_char;
			if (temp_char == '-') {		//是'-'存入Null，即-1
				T[i].Left = Null;
			} else {
				T[i].Left = temp_char - '0';	//不是'-'存入儿子序号
				check[T[i].Left] = 1;	//标记已经遍历过，说明这个节点不是root
			}
			cin >> temp_char;
			if (temp_char == '-') {
				T[i].Right = Null;
			} else {
				T[i].Right = temp_char - '0';
				check[T[i].Right] = 1;
			}
		}
		for (int i = 0; i < size; i++) {	//若check[i]==0,则i为根
			if (check[i] == 0) {
				root = i;
				break;
			}
		}
	}
	return root;	//返回根节点序号
}

void List_Leaves(int root) {
	queue<int> q;
	q.push(root);
	int left = T[root].Left;
	int right = T[root].Right;
	bool flag = 0;
	while (!q.empty()) {
		root = q.front();
		q.pop();
		left = T[root].Left;
		right = T[root].Right;
		if (left == Null && right == Null) {
			if (!flag) {
				cout << root;
				flag=true;
			} else {
				cout << " " << root;
			}
		}
		if (left != Null) {
			q.push(left);
		}
		if (right != Null) {
			q.push(right);
		}
	}
}
int main() {
	int root = BuildTree(T);
	List_Leaves(root);
	//system("pause");
	return 0;
}