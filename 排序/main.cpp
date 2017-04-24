#include <iostream>
using namespace std;

int a[9] = {9,8,7,6,5,4,3,2,1};
int _size = 9;

void Bubble() {
	int temp;
	for (int i = 9; i>0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void Swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void Select() {
	int min = 0;
	for (int i = 0; i < _size; i++) {
		min = i;
		for (int j = i; j < _size; j++) {
			if (a[j]<a[min]) {
				min = j;
				Swap(a, i, min);
			}
		}
	}
}

int Partition(int l,int r) {
	//算法课本上的代码，很简练：
	//int i = l, j = r;
	//while (i < j) {
	//	while (i < j&&a[i] <= a[j]) j--;	//右侧扫描
	//	if (i < j) {	//此时i>=j或a[i]>=a[j]
	//		int temp = a[i];
	//		a[i] = a[j];
	//		a[j] = temp;
	//		i++;
	//	}
	//	while (i < j&&a[i] <= a[j]) i++;
	//	if (i < j) {
	//		int temp = a[i];
	//		a[i] = a[j];
	//		a[j] = temp;
	//		j--;
	//	}
	//	return i;
	//}

	//以下为啊哈算法中的实现，感觉更易理解
	int i = l, j = r;
	int temp = a[l];
	int t;
	while (i < j) {
		//顺序很重要，先从右边找
		//原因:http://blog.csdn.net/w282529350/article/details/50982650
		while (a[j] >= temp&&i < j)
			j--;
		while (a[i] <= temp&&i < j)	//再找左边的
			i++;
		if (i < j) {	//交换两个数在数组中的位置 
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位
	a[l] = a[i];
	a[i] = temp;
	return i;
}

void Quick(int l, int r) {
	int temp;
	if (l < r) {
		temp = Partition(l, r);
		Quick(l, temp - 1);
		Quick(temp + 1, r);
	}
}

int main() {
	Quick(0, 9);
	for (int i = 0; i < _size; i++) {
		cout << a[i] << endl;
	}
	system("pause");
}

