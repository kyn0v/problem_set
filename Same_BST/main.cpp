#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *Left, *Right;
	int flag;
	/*TreeNode(int data, TreeNode *Left, TreeNode *Right, int flag) {
		this->data = data;
		this->Left = Left;
		this->Right = Right;
		this->flag = flag;
	}*/
};

TreeNode *NewNode(int data) {
	TreeNode *T = new TreeNode();
	T->data = data;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

TreeNode *Insert(TreeNode *T, int data) {
	if (T == NULL) {
		T = NewNode(data);
	} else {			//�˴���ELSE
		if (data < T->data) {
			T->Left = Insert(T->Left, data);	//������׼������ʱ�򣬷�������д���ˣ�����
		} else {
			T->Right = Insert(T->Right, data);	//����
		}
	}
	return T;
}

TreeNode *MakeTree(int N) {
	TreeNode *T;
	int data;

	cin >> data;
	T = NewNode(data);
	for (int i = 1; i < N; i++) {
		cin >> data;
		Insert(T, data);
	}
	return T;
}

int Check(TreeNode *T, int data) {
	if (T->flag) {
		if (data < T->data) {
			return Check(T->Left, data);
		} else if (data > T->data) {
			return Check(T->Right, data);
		} else {
			return 0;
		}
	} else {
		if (data == T->data) {
			T->flag = 1;
			return 1;
		} else {
			return 0;
		}
	}
}

bool Judge(TreeNode *T, int N) {
	int data, flag = 0;
	cin >> data;
	if (data != T->data) {
		flag = 1;
	} else {
		T->flag = 1;
	}
	//Ӧ��ע����ǣ�������ĳ�����ݲ�һ�µ�ʱ�򣬱���Ѻ�������ݶ����꣬�������Ϸ���
	/*
	��BUG�汾��
	for (int i = 1; i < N; i++) {
		cin >> data;
		if (!Check(T, data)) return 0;
	}
	������������3241����2ʱ���Ѿ���ͬ�ˣ�����д��������41������һ������
	*/
	for (int i = 1; i < N; i++) {
		cin >> data;
		if ((!flag) && !Check(T, data)) flag = 1;
	}
	if (flag) {
		return 0;
	} else {
		return 1;
	}
}

void Reset(TreeNode *T) {
	if (T->Left) Reset(T->Left);
	if (T->Right) Reset(T->Right);
	T->flag = 0;
}

void Traverse(TreeNode *T) {
	if (T) {
		cout << T->data << endl;
		Traverse(T->Left);
		Traverse(T->Right);
	}
}
int main() {
	//�������Ľڵ����N���ʹ��Ƚϵ����ĸ���L
	int N, L;
	TreeNode *T;
	cin >> N;
	while (N) {
		cin >> L;
		T = MakeTree(N);	//ͨ���ڶ������ݽ���׼��T
		for (int i = 0; i < L; i++) {
			if (Judge(T, N)) {	//������T�ֱ��б�����L�����У��Ƿ��ܹ�����T��ͬ��BST
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
			Reset(T);
		}
		delete[] T;
		cin >> N;
	}
	return 0;
}