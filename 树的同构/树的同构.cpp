// 树的同构.cpp : 定义控制台应用程序的入口点。
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

Tree BuildTree(TreeNode T[]) {	//建树
	int size = 0, root = Null;
	cin >> size;
	char temp_char;
	int check[Maxtree];
	if (size) {
		for (int i = 0; i < size; i++)check[i] = 0;	//初始化前size个数据，因为只会用的到size个
		for (int i = 0; i < size; i++) {	//输入数据
			cin >> T[i].Element;
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

int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == Null) && (R2 == Null)) {	//都为空
		return 1;
	} if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null))) {	//其中一个为空
		return 0;
	} if (T1[R1].Element != T2[R2].Element) {	//根的内容不同
		return 0;
	} if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) {	//都没有左子树
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	} if (((T1[R1].Left != Null) && (T2[R2].Left != Null))&&(T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)) {	//不需要交换左右
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	} else {	//需要交换左右
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
	}
}

int main()
{
	//建树
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


