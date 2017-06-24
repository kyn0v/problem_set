// PracticeMakesPerfect.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
void Problem1() {	//约瑟夫环
//初始化
int num;
cin >> num;
int k;
cin >> k;
int *a = new int[num];
for (int i = 0; i < num; i++) {
a[i] = 1;
}

int leave_kid = -1;
int rest = num;
int cnt,cur;
while (rest > 0) {
cnt = k;
leave_kid = (leave_kid + 1) % num;
while (cnt > 0) {
if (a[leave_kid] > 0) {	//有人则计数
cnt--;
} else {
leave_kid++;
}
}
a[leave_kid] = 0;
rest--;
}
cout << "index: " << leave_kid << endl;
delete [] a;
}

void Problem2() {	//排序
//初始化
int n;
cin >> n;
int *a=new int[n];
for (int i = 0; i < n; i++) {
cin >> a[i];
}
int *b = new int[n];
for (int i = 0; i < n; i++) {
b[i] = a[i];
}
//冒泡排序
int bubble_temp;
for (int i = 0; i < n; i++) {
for (int j = 0; j < n-i-1; j++) {	//j<n-i-1
if (b[j] > b[j + 1]) {
bubble_temp = b[j];
b[j] = b[j + 1];
b[j + 1] = bubble_temp;
}
}
}
//输出
for (int k = 0; k < n; k++) {
cout << b[k] << "  ";
}
//回收
delete[]b;
delete[]a;
}

void Problem3() {	//按大小排列字符串并输出
//初始化
char c[3][80], temp[80];
int i, j;
for (int i = 0; i < 3; i++) {
gets_s(c[i]);	//这种方式可以允许输入的字符数组有空格，而cin则做不到
//cin >> c[i];
}

for (int i = 0; i < 3-1; i++) {
for (int j = i + 1; j < 3; j++) {
if (strcmp(c[i], c[j]) > 0) {
strcpy_s(temp, c[i]);
strcpy_s(c[i], c[j]);
strcpy_s(c[j], temp);
}
}
}

//输出
for (int i = 0; i < 3; i++) {
puts(c[i]);
//cout << c[i];
}
}

void Problem4() {	//素数筛
int a[1001] = { 0 };
int endl_cnt = 0;
for (int i = 2; i <= 1000; i++) {
if (a[i] == 0) {
for (int j = 2; j*i <= 1000; j++) {
a[i*j] = 1;
}
cout << i << " ";
endl_cnt++;
if (endl_cnt == 10) {
endl_cnt = 0;
cout << endl;
}
}
}
}
*/
void Problem5() {	//蛇形矩阵
	int n;	//阶数
	cin >> n;
	//动态分配空间
	int** array2D;
	array2D = new int*[n];
	for (int i = 0; i < n; i++) {
		array2D[i] = new int[n];
	}
	/*
	不知道哪里错了
	int i = n - 1, j = 0,k = 1;
	while (k <= n*n) {
	while (j > 0 && i > 0) {	//左上方向
	array2D[i][j] = k;
	k++;
	i--;
	j--;
	}
	array2D[i][j] = k;
	k++;
	if (k > n*n) {
	break;
	}
	if (j == 0 && i!=0) {
	i--;
	}
	else if (i == 0) {
	j++;
	}
	while (i < n - 1 && j < n - 1) {	//右下方向
	array2D[i][j] = k;
	k++;
	i++;
	j++;
	}
	array2D[i][j] = k;
	k++;
	if (i = n - 1 && j != n - 1) {
	j++;
	}
	else if (j == n - 1) {
	i--;
	}
	}
	*/
	int row = n - 1, col = 0, num = 1;
	bool up = true;
	array2D[row][col] = num;
	while (num < n*n) {
		if (up) {
			row--;
			col--;
		} else {
			row++;
			col++;
		}
		if (row == -1) {	//超过首行
			row++;
			col = col + 2;
			up = !up;
		}
		if (col == n) {	//超过末列
			row = row - 2;
			col--;
			up = !up;
		}
		if (row == n) {	//超过末行
			row--;
			up = !up;
		}
		if (col == -1) {
			col++;
			up = !up;
		}
		num++;
		array2D[row][col] = num;
	}

	//输出
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array2D[i][j] << " ";
		}
		cout << endl;
	}
	//释放
	for (int i = 0; i < n; i++) {
		delete[] array2D[i];
	}
	delete array2D;
	//或直接"delete[] array2D;"即可全部释放 
}

int main()
{
	//Problem1();
	//Problem2();
	//Problem3();
	//Problem4();
	Problem5();
	return 0;
}

