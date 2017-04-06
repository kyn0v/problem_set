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
	} else {			//此处的ELSE
		if (data < T->data) {
			T->Left = Insert(T->Left, data);	//正当我准备放弃时候，发现这里写错了！！！
		} else {
			T->Right = Insert(T->Right, data);	//谨记
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
	//应当注意的是：当发现某个数据不一致的时候，必须把后面的数据都读完，不能马上返回
	/*
	有BUG版本：
	for (int i = 1; i < N; i++) {
		cin >> data;
		if (!Check(T, data)) return 0;
	}
	假设输入数据3241，到2时就已经不同了，这样写，程序会把41当成下一组数据
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
	//读入树的节点个数N，和待比较的树的个数L
	int N, L;
	TreeNode *T;
	cin >> N;
	while (N) {
		cin >> L;
		T = MakeTree(N);	//通过第二行数据建基准树T
		for (int i = 0; i < L; i++) {
			if (Judge(T, N)) {	//依据树T分别判别后面的L个序列，是否能构成与T相同的BST
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