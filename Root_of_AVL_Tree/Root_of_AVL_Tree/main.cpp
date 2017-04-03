#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node{
	int Data;
	Node *Left;
	Node *Right;
	int Height;
	Node(int data) :Data(data), Left(NULL), Right(NULL), Height(0) {}
	Node() :Data(0), Left(NULL), Right(NULL), Height(0) {}
};

int Get_Height(Node *T) {
	if (T == NULL) {
		return -1;		//
	}
	return T->Height;
}

Node *SingleRotateLeft(Node *T) {	//左单转
	Node *Lchild = T->Left;
	T->Left = Lchild->Right;
	Lchild->Right = T;
	
	//注意此处是更新高度，而并非更新平衡因子
	T->Height = std::max(Get_Height(T->Left), Get_Height(T->Right)) + 1;
	Lchild->Height = std::max(Get_Height(Lchild->Left), Get_Height(Lchild->Right)) + 1;
	
	return Lchild;
}

Node *SingleRotateRight(Node *T) {	//右单旋
	Node *Rchild = T->Right;
	T->Right = Rchild->Left;
	Rchild->Left = T;

	//更新高度
	T->Height = std::max(Get_Height(T->Left), Get_Height(T->Right)) + 1;
	Rchild->Height = std::max(Get_Height(Rchild->Left), Get_Height(Rchild->Right)) + 1;

	return Rchild;
}

Node *LR_Double_Rotate(Node *T) {	//破坏节点为被破坏节点--左孩子的右孩子
	T->Left = SingleRotateRight(T->Left);
	return SingleRotateLeft(T);
}

Node *RL_Double_Rotate(Node *T) {	//破坏节点为被破坏节点的--右孩子的左孩子
	T->Right = SingleRotateLeft(T->Right);
	return SingleRotateRight(T);
}

bool Is_Balanced(Node *left, Node *right) {
	return std::abs(Get_Height(left) - Get_Height(right)) < 2;
}

Node *Insert(Node *root, int data) {
	if (root == NULL) {
		root = new Node(data);
		return root;
	} else {
		if (data < root->Data) {	//插入左子树
			root->Left = Insert(root->Left, data);
			if (!Is_Balanced(root->Left, root->Right)) {
				//测试是单旋还是双旋
				if (data < root->Left->Data) {	//左单旋

					//在这里，root节点旋转之后，必须把root节点更新一遍！！！！
					root = SingleRotateLeft(root);
				} else {	//左右双旋
					root = LR_Double_Rotate(root);
				}
			}
		} else {	//插入右子树
			root->Right = Insert(root->Right, data);
			//判断是否平衡
			if (!Is_Balanced(root->Left, root->Right)) {
				//判断是单旋还是双旋
				if (data > root->Right->Data) {		//右单旋
					root = SingleRotateRight(root);
				} else {	//右左双旋
					root = RL_Double_Rotate(root);
				}
			}
		}
	}
	root->Height = std::max(Get_Height(root->Left), Get_Height(root->Right)) + 1;
	return root;
}

int main() {
	int size, data;
	Node *root = NULL;
	cin >> size;
	while (size) {
		cin >> data;
		root = Insert(root, data);
		size--;
	}
	cout << root->Data;
	system("pause");
	return 0;
}
