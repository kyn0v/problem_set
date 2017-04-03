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

int Get_Weight(Node *T) {
	if (!T) {
		return -1;		//此处为-1，表示其
	}
	return T->Data;
}

Node *SingleRotateLeft(Node *T) {	//左左旋转
	Node *Lchild = T->Left;
	T->Left = Lchild->Right;
	Lchild->Right = T;
	
	//注意此处是更新高度，而并非更新平衡因子
	T->Height = std::max(Get_Weight(T->Left), Get_Weight(T->Right)) + 1;
	Lchild->Height = std::max(Get_Weight(Lchild->Left), Get_Weight(Lchild->Right)) + 1;
	
	return Lchild;
}

Node *SingleRotateRight(Node *T) {
	Node *Rchild = T->Right;
	T->Right = Rchild->Left;
	Rchild->Left = T;

	//更新高度
	T->Height = std::max(Get_Weight(T->Left), Get_Weight(T->Right)) + 1;
	Rchild->Height = std::max(Get_Weight(Rchild->Left), Get_Weight(Rchild->Right)) + 1;

	return Rchild;
}

Node *LR_Double_Rotate(Node *T) {	//破坏节点为被破坏节点--左孩子的右孩子
	T->Left = SingleRotateRight(T->Left);
	return SingleRotateLeft(T);
}

Node *RL_Double_Rotate(Node *T) {	//破坏节点为被破坏节点的--右孩子的左孩子
	T->Left = SingleRotateRight(T->Left);
	return SingleRotateLeft(T);
}

bool Is_Balanced(Node *left, Node *right) {
	return std::abs(Get_Weight(left) - Get_Weight(right) < 2);
}

Node *Insert(Node *root, int data) {
	if (root == NULL) {
		root = new Node(data);
		return root;
	} else {
		if (data > root->Data) {	//插入右子树
			root->Right = Insert(root->Right, data);
			//判断是否平衡
			if (!Is_Balanced) {
				//判断是单旋还是双旋
				if (data > root->Right->Data) {		//右单旋
					SingleRotateRight(root);
				} else {	//右左双旋
					RL_Double_Rotate(root);
				}
			}
		} else {	//插入左子树
			root->Left = Insert(root->Left, data);
			if (!Is_Balanced(root->Left, root->Right)) {
				//测试是单旋还是双旋
				if (data < root->Left->Data) {	//左单旋
					SingleRotateLeft(root);
				} else {	//左右双旋
					LR_Double_Rotate(root);
				}
			}
		}
	}
	root->Height = std::max(Get_Weight(root->Left), Get_Weight(root->Right)) + 1;
	return root;
}

Node* CreateAVL() {
	int size, data;
	Node *T;
	cin >> size;
	if (size == 0) {
		return NULL;
	}
	cin >> data;
	T = new Node(data);
	size--;
	while (size) {
		cin >> data;
		Insert(T, data);

		size--;
	}
}


int main() {

	return 0;
}