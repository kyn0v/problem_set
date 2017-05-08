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
		for (j; j > 0 && a[j - 1] > temp; j--) {
			a[j] = a[j - 1];	//�Ƴ���λ
		}
		a[j] = temp;	//������λ
	}
}
//���ð�ݵ��ŵ�֮һ�����������漰������������Լ�
//ͬʱ��������Ҳ���ȶ���


void Shell_Sort(int N) {
	int temp;
	for (int D = N / 2; D > 0; D = D / 2) {	//ϣ����������
		for (int P = D; P < N; P++) {
			temp = a[P];
			int j = P;
			for (j; j >= D && a[j - D] > temp; j = j - D) {	//�����������е�1��Ϊ���D,����j>=DӦע��
				a[j] = a[j - D];
			}
			a[j] = temp;
		}
	}
}
/*
Ҫ�㣺����Ԫ�ز����ʣ���С�������ܸ�����������
	Hibbard�������У�Dk=2^k-1------��֤����Ԫ�ػ���
	sedgewick�������У�������
*/

void Select_Sort() {
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


//������

//�㷨һ��
//void Heap_Sort(int a[],int N) {
//	BuildHeap(a);
//	for (int i = 0; i < N; i++) {
//		temp[i] = DeleteMin(a);
//	}
//	for (int i = 0; i < N; i++) {
//		a[i] = temp[i];
//	}
//}
//�㷨����
//�������ѣ�Ȼ�����Ԫ����ĩβԪ�ؽ���
void PercDown(int num[], int index, int size) {
	int max;// �������ָ���±�
	while (index * 2 + 1<size) {// �����������ڵ㣬�������ڵ����   
		max = index * 2 + 1;// ��ȡ��ڵ���±�  
		if (index * 2 + 2<size) {// ������������ҽڵ�
			if (num[max] < num[index * 2 + 2]) {// �ͺ���ڵ�ֳ������   
				max = index * 2 + 2;// ��ʱ�ҽڵ���������min��ָ���±�   
			}
		}
		// ��ʱ���и�������С�߽��бȽϣ�   
		if (num[index] > num[max]) {// ���index���   
			break;// ֹͣ���˲���   
		}
		else {
			Swap(num, index, max);// ��������������С�����³�   
			index = max;// ����index��ָ��   
		}
	}// while   
}

void Heap_Sort(int a[], int n) {
	for (int i = n / 2; i > 0; i--) {	//��������
		PercDown(a, i, n);
	}
	for (int i = n - 1; i > 0; i--) {	//ɸѡ�����Ԫ��
		Swap(a, 0, i);
		PercDown(a, 0, i);
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

void Quick_Sort(int l, int r) {
	int temp;
	if (l < r) {
		temp = Partition(l, r);
		Quick_Sort(l, temp - 1);
		Quick_Sort(temp + 1, r);
	}
}

//��Ԫ��ѡȡ��Ӧ�뷨�򵥶�ֱ��ȡ��һ��Ԫ�أ���Ϊ���������������Ч���ͺ܇��ˣ���
//��ȡ������1.�������ȡ 2.ȡ�����ҵ���λ��
int CutOff = 100;	//���ÿ����������С����

int Median3(int a[],int left,int right) {
	int center = (left+right) / 2;
	if (a[left] > a[center]) {
		Swap(&a[left]);
	}
}

void Quicksort(int a[], int left, int right) {
	int pivot;	//��Ԫ
	if (CutOff <= right - left) {
		
	}
}
void Quick_Sort2(int a[],int n) {

}


void Merge(int a[],int temp[],int first,int mid,int last) {	//�ϲ�������
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

void M_Sort(int a[],int temp[],int first, int last) {	//�ݹ�ʵ��
	if (first < last) {
		int mid = (first + last) / 2;
		M_Sort(a, temp, first, mid);
		M_Sort(a, temp, mid + 1, last);
		Merge(a,temp,first, mid, last);
	}
}
void Merge_Sort1(int a[], int n) {	//�ݹ�
	int *temp;
	temp = new int[n];
	if (temp != NULL) {
		M_Sort(a, temp, 0, n - 1);
		delete[] temp;
	}
	else {
		cout << "�ռ䲻��" << endl << endl;
	}
}

//�Ż�Ϊ��ͳһ�����ӿڵĺ���
void Merge2(int a[],int temp[],int first, int mid, int last) {	//�ǵݹ��㷨�ϲ�������,��������temp�Ż�a�Ĳ���
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
}
void Merge_pass(int a[],int temp[],int n,int length) {	//�ǵݹ��㷨
	//length����ǰ�������еĳ���
	int i = 0;
	for (i; i <= n - length * 2; i+=2*length) {	//�ȴ���ɶԲ���
		Merge2(a, temp, i, i + length, i + 2 * length - 1);	//��������ݷ���temp�У����ص���a
	}
	//�������²���
	if (i + length < n) {	//�鲢���2������
		Merge2(a, temp, i, i + length, n-1);
	}
	else {	//���ֻʣһ������
		for (int j = i; j < n; j++) {
			temp[j] = a[j];
		}
	}
}
//�Ż�Ϊ��ͳһ�����ӿڵĺ���
void Merge_Sort2(int a[],int n) {	//�ǵݹ�
	int length = 1; //��ʼ�������г���Ϊ1
	int *temp;
	temp = new int[n];
	if (temp != NULL) {
		while (length<n) {	//��ͣ����a��temp������ص�



			//��һ���г���=='
			Merge_pass(a, temp, n, length);
			length *= 2;
			Merge_pass(temp, a, n, length);
			length *= 2;



		}
		delete[] temp;
	}
	else {
		cout << "�ռ䲻��" << endl << endl;
	}
}
//�鲢�������ȶ����㷨��ͨ�����������򣬼��ڴ�ռ����򲻹��õ�����£����ǲŻ�ѡ�鲢����
//���⣬�����ʱ���鲻����������㣬����ÿ�ε��ù鲢����ʱ�ظ����ٿռ䣬�ή�ͳ���Ч��


int main() {
	Merge_Sort2(a, 10);
	for (int i = 0; i < _size; i++) {
		cout << a[i] << endl;
	}
	system("pause");
}

