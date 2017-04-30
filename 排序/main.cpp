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
				flag = 1;	/*��ʶ�����˽���*/
			}
		}
		if (flag == 1) break;	//ȫ���޽�����˵���Ѿ����ź������
	}
}
//ð�ݵ��ŵ�:1.����������洢�����ݽ������򲻻��ܵ�Ӱ��
//			2.��֤��������ȶ���




void Swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void Insertion_Sort() {	//�����ڳ��˿���
	int temp;
	for (int i = 0; i < _size; i++) {
		temp = a[i];	//����һ����
		int j = i;
		for ( j; i > 0 && a[i - 1] > temp; i--) {
			a[i] = a[i - 1];	//�Ƴ���λ
		}
		a[j] = temp;	//������λ
	}
}
//���ð�ݵ��ŵ�֮һ�����������漰������������Լ�
//ͬʱ��������Ҳ���ȶ���

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
	//�㷨�α��ϵĴ��룬�ܼ�����
	//int i = l, j = r;
	//while (i < j) {
	//	while (i < j&&a[i] <= a[j]) j--;	//�Ҳ�ɨ��
	//	if (i < j) {	//��ʱi>=j��a[i]>=a[j]
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

	//����Ϊ�����㷨�е�ʵ�֣��о��������
	int i = l, j = r;
	int temp = a[l];
	int t;
	while (i < j) {
		//˳�����Ҫ���ȴ��ұ���
		//ԭ��:http://blog.csdn.net/w282529350/article/details/50982650
		while (a[j] >= temp&&i < j)
			j--;
		while (a[i] <= temp&&i < j)	//������ߵ�
			i++;
		if (i < j) {	//�����������������е�λ�� 
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//���ս���׼����λ
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


void Merge(int first,int mid,int last,int temp[]) {	//�ϲ�������
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
	int temp[20];	//��Ϊ������С����ʱ����ͷ����˺������棬��С����Ϊ20
	if (first < last) {
		int mid = (first + last) / 2;
		MergeSort(first, mid);
		MergeSort(mid + 1, last);
		Merge(first, mid, last, temp);
	}
}

//ϣ������
void Hill() {

}

int main() {
	MergeSort(0, _size);
	for (int i = 0; i < _size; i++) {
		cout << a[i] << endl;
	}
	system("pause");
}

