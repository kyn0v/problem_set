#include <iostream>
using namespace std;

//����Ԫ�������2���ؼ��֣����һ���ȫ��ͬ����Radix
#define MaxDigit 2
#define Radix 10


//�뵽����������
struct node {	//Ͱ���
	int key;
	node* next;
};
typedef struct node *PtrToNode;

struct headnode {	//Ͱͷ���
	node *head;
	node *tail;
};
typedef struct headnode Bucket[Radix];

//��ȡ��Ӧλ�ϵĻ���ֵ,�ؼ���������
int GetDigit(int x,int D) {
	//Ĭ�ϴ�λd=1,��λd<=MaxDigit
	int d, i;

	for (i = 1; i < D; i++) {
		d = x%Radix;
		x = x / Radix;
	}
	return d;
}

void LSDRadixSort(int A[], int N)
{ /* �������� - ��λ���� */
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for (i = 0; i<Radix; i++) /* ��ʼ��ÿ��ͰΪ������ */
		B[i].head = B[i].tail = NULL;
	for (i = 0; i<N; i++) { /* ��ԭʼ������������ʼ����List */
		tmp = (PtrToNode)malloc(sizeof(struct node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* ���濪ʼ���� */
	for (D = 1; D <= MaxDigit; D++) { /* �����ݵ�ÿһλѭ������ */
									  /* �����Ƿ���Ĺ��� */
		p = List;
		while (p) {
			Di = GetDigit(p->key, D); /* ��õ�ǰԪ�صĵ�ǰλ���� */
									  /* ��List��ժ�� */
			tmp = p; p = p->next;
			/* ����B[Di]��Ͱβ */
			tmp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else {
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/* �������ռ��Ĺ��� */
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--) { /* ��ÿ��Ͱ��Ԫ��˳���ռ���List */
			if (B[Di].head) { /* ���Ͱ��Ϊ�� */
							  /* ��Ͱ����List��ͷ */
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; /* ���Ͱ */
			}
		}
	}
	/* ��List����A[]���ͷſռ� */
	for (i = 0; i<N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
}

//void LSD(int a[],int n) {	//��λ����
//	int bucket[10] = {0};
//	for(int )
//}

int main() {
	int N;
	cin >> N;
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	LSDRadixSort(a, N);
	for (int i = 0; i < N; i++) {
		
	}
}
//���ÿռ任ȡʱ��
//#include <stdio.h>
//
//int main()
//{
//	int N, workAge;
//	int workYear[55] = { 0 };
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &workAge);
//		workYear[workAge]++;
//	}
//	for (int i = 0; i < 51; i++) {
//		if (workYear[i])
//			printf("%d:%d\n", i, workYear[i]);
//	}
//	return 0;
//}