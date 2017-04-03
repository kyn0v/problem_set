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
		return -1;		//�˴�Ϊ-1����ʾ��
	}
	return T->Data;
}

Node *SingleRotateLeft(Node *T) {	//������ת
	Node *Lchild = T->Left;
	T->Left = Lchild->Right;
	Lchild->Right = T;
	
	//ע��˴��Ǹ��¸߶ȣ������Ǹ���ƽ������
	T->Height = std::max(Get_Weight(T->Left), Get_Weight(T->Right)) + 1;
	Lchild->Height = std::max(Get_Weight(Lchild->Left), Get_Weight(Lchild->Right)) + 1;
	
	return Lchild;
}

Node *SingleRotateRight(Node *T) {
	Node *Rchild = T->Right;
	T->Right = Rchild->Left;
	Rchild->Left = T;

	//���¸߶�
	T->Height = std::max(Get_Weight(T->Left), Get_Weight(T->Right)) + 1;
	Rchild->Height = std::max(Get_Weight(Rchild->Left), Get_Weight(Rchild->Right)) + 1;

	return Rchild;
}

Node *LR_Double_Rotate(Node *T) {	//�ƻ��ڵ�Ϊ���ƻ��ڵ�--���ӵ��Һ���
	T->Left = SingleRotateRight(T->Left);
	return SingleRotateLeft(T);
}

Node *RL_Double_Rotate(Node *T) {	//�ƻ��ڵ�Ϊ���ƻ��ڵ��--�Һ��ӵ�����
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
		if (data > root->Data) {	//����������
			root->Right = Insert(root->Right, data);
			//�ж��Ƿ�ƽ��
			if (!Is_Balanced) {
				//�ж��ǵ�������˫��
				if (data > root->Right->Data) {		//�ҵ���
					SingleRotateRight(root);
				} else {	//����˫��
					RL_Double_Rotate(root);
				}
			}
		} else {	//����������
			root->Left = Insert(root->Left, data);
			if (!Is_Balanced(root->Left, root->Right)) {
				//�����ǵ�������˫��
				if (data < root->Left->Data) {	//����
					SingleRotateLeft(root);
				} else {	//����˫��
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