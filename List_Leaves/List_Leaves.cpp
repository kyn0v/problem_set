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

Tree BuildTree(TreeNode T[]) {	//����
	int size = 0, root = Null;
	cin >> size;
	char temp_char;
	int check[Maxtree];
	if (size) {
		for (int i = 0; i < size; i++)check[i] = 0;	//��ʼ��ǰsize�����ݣ���Ϊֻ���õĵ�size��
		for (int i = 0; i < size; i++) {	//��������
			cin >> temp_char;
			if (temp_char == '-') {		//��'-'����Null����-1
				T[i].Left = Null;
			} else {
				T[i].Left = temp_char - '0';	//����'-'����������
				check[T[i].Left] = 1;	//����Ѿ���������˵������ڵ㲻��root
			}
			cin >> temp_char;
			if (temp_char == '-') {
				T[i].Right = Null;
			} else {
				T[i].Right = temp_char - '0';
				check[T[i].Right] = 1;
			}
		}
		for (int i = 0; i < size; i++) {	//��check[i]==0,��iΪ��
			if (check[i] == 0) {
				root = i;
				break;
			}
		}
	}
	return root;	//���ظ��ڵ����
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