#include <iostream>
using namespace std;

void Merge(int source[], int temp[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid&&j <= right) {	//注意此处应该是<=
		if (source[i] < source[j]) {	//这里也是<=
			temp[k++] = source[i++];
		} else {
			temp[k++] = source[j++];	//还有这里也是
		}
	}
	while (i <= mid) {
		temp[k++] = source[i++];
	}
	while (j <= right) {
		temp[k++] = source[j++];
	}
}
void Merge_Sort(int a[], int left, int right) {
	int mid, temp[1000];
	if (left == right)return;
	else {
		mid = (left + right) / 2;
		Merge_Sort(a, left, mid);
		Merge_Sort(a, mid + 1, right);
		Merge(a, temp, left, mid, right);
	}
	for (int i = left; i <= right; i++) {
		a[i] = temp[i];
	}
}
int main() {
	int a[10] = { 3,5,67,2,6,7,82,1,34,8 };
	Merge_Sort(a, 8, 9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}