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

Node *SingleRotateLeft(Node *T) {	//��ת
	Node *Lchild = T->Left;
	T->Left = Lchild->Right;
	Lchild->Right = T;
	
	//ע��˴��Ǹ��¸߶ȣ������Ǹ���ƽ������
	T->Height = std::max(Get_Height(T->Left), Get_Height(T->Right)) + 1;
	Lchild->Height = std::max(Get_Height(Lchild->Left), Get_Height(Lchild->Right)) + 1;
	
	return Lchild;
}

Node *SingleRotateRight(Node *T) {	//�ҵ���
	Node *Rchild = T->Right;
	T->Right = Rchild->Left;
	Rchild->Left = T;

	//���¸߶�
	T->Height = std::max(Get_Height(T->Left), Get_Height(T->Right)) + 1;
	Rchild->Height = std::max(Get_Height(Rchild->Left), Get_Height(Rchild->Right)) + 1;

	return Rchild;
}

Node *LR_Double_Rotate(Node *T) {	//�ƻ��ڵ�Ϊ���ƻ��ڵ�--���ӵ��Һ���
	T->Left = SingleRotateRight(T->Left);
	return SingleRotateLeft(T);
}

Node *RL_Double_Rotate(Node *T) {	//�ƻ��ڵ�Ϊ���ƻ��ڵ��--�Һ��ӵ�����
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
		if (data < root->Data) {	//����������
			root->Left = Insert(root->Left, data);
			if (!Is_Balanced(root->Left, root->Right)) {
				//�����ǵ�������˫��
				if (data < root->Left->Data) {	//����

					//�����root�ڵ���ת֮�󣬱����root�ڵ����һ�飡������
					root = SingleRotateLeft(root);
				} else {	//����˫��
					root = LR_Double_Rotate(root);
				}
			}
		} else {	//����������
			root->Right = Insert(root->Right, data);
			//�ж��Ƿ�ƽ��
			if (!Is_Balanced(root->Left, root->Right)) {
				//�ж��ǵ�������˫��
				if (data > root->Right->Data) {		//�ҵ���
					root = SingleRotateRight(root);
				} else {	//����˫��
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
