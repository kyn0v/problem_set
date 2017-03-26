// ����ͬ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define Maxtree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[Maxtree],T2[Maxtree];

Tree BuildTree(TreeNode T[]) {	//����
	int size = 0, root = Null;
	cin >> size;
	char temp_char;
	int check[Maxtree];
	if (size) {
		for (int i = 0; i < size; i++)check[i] = 0;	//��ʼ��ǰsize�����ݣ���Ϊֻ���õĵ�size��
		for (int i = 0; i < size; i++) {	//��������
			cin >> T[i].Element;
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

int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == Null) && (R2 == Null)) {	//��Ϊ��
		return 1;
	} if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null))) {	//����һ��Ϊ��
		return 0;
	} if (T1[R1].Element != T2[R2].Element) {	//�������ݲ�ͬ
		return 0;
	} if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) {	//��û��������
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	} if (((T1[R1].Left != Null) && (T2[R2].Left != Null))&&(T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)) {	//����Ҫ��������
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	} else {	//��Ҫ��������
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
	}
}

int main()
{
	//����
	int root1 = BuildTree(T1);
	int root2 = BuildTree(T2);
	if (Isomorphic(root1, root2)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	system("pause");
    return 0;
}


