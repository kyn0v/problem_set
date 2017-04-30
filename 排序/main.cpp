#include <iostream>
using namespace std;

int a[9] = {9,8,7,6,5,4,3,2,1};
int _size = 9;

void Bubble_Sort() {
	int temp;
	int flag = 0;
	for (int i = 9; i>0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				flag = 1;	/*标识发生了交换*/
			}
		}
		if (flag == 1) break;	//全程无交换，说明已经是排好序的了
	}
}
//冒泡的优点:1.对于用链表存储的数据进行排序不会受到影响
//			2.保证了排序的稳定性




void Swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void Insertion_Sort() {	//类似于抽扑克牌
	int temp;
	for (int i = 0; i < _size; i++) {
		temp = a[i];	//摸下一张牌
		int j = i;
		for ( j; i > 0 && a[i - 1] > temp; i--) {
			a[i] = a[i - 1];	//移除空位
		}
		a[j] = temp;	//新牌落位
	}
}
//相比冒泡的优点之一，插入排序不涉及两两交换，相对简单
//同时插入排序也是稳定的

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


void Merge(int first,int mid,int last,int temp[]) {	//合并子序列
	int i = first, j = mid + 1, k = 0;
	while (i <= mid&&j <= last) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= last) {
		temp[k++] = a[j++];
	}
	for (int i = 0; i < k; i++) {
		a[first + i] = temp[i];
	}
}

void MergeSort(int first, int last) {
	int temp[20];	//因为数据量小，临时数组就放在了函数里面，大小设置为20
	if (first < last) {
		int mid = (first + last) / 2;
		MergeSort(first, mid);
		MergeSort(mid + 1, last);
		Merge(first, mid, last, temp);
	}
}

//希尔排序
void Hill() {

}

int main() {
	MergeSort(0, _size);
	for (int i = 0; i < _size; i++) {
		cout << a[i] << endl;
	}
	system("pause");
}

