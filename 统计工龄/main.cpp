#include <iostream>
using namespace std;

//假设元素最多有2个关键字，并且基数全是同样的Radix
#define MaxDigit 2
#define Radix 10


//想到基数排序解决
struct node {	//桶结点
	int key;
	node* next;
};
typedef struct node *PtrToNode;

struct headnode {	//桶头结点
	node *head;
	node *tail;
};
typedef struct headnode Bucket[Radix];

//获取相应位上的基数值,关键函数！！
int GetDigit(int x,int D) {
	//默认次位d=1,主位d<=MaxDigit
	int d, i;

	for (i = 1; i < D; i++) {
		d = x%Radix;
		x = x / Radix;
	}
	return d;
}

void LSDRadixSort(int A[], int N)
{ /* 基数排序 - 次位优先 */
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for (i = 0; i<Radix; i++) /* 初始化每个桶为空链表 */
		B[i].head = B[i].tail = NULL;
	for (i = 0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
		tmp = (PtrToNode)malloc(sizeof(struct node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* 下面开始排序 */
	for (D = 1; D <= MaxDigit; D++) { /* 对数据的每一位循环处理 */
									  /* 下面是分配的过程 */
		p = List;
		while (p) {
			Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
									  /* 从List中摘除 */
			tmp = p; p = p->next;
			/* 插入B[Di]号桶尾 */
			tmp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else {
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/* 下面是收集的过程 */
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--) { /* 将每个桶的元素顺序收集入List */
			if (B[Di].head) { /* 如果桶不为空 */
							  /* 整桶插入List表头 */
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; /* 清空桶 */
			}
		}
	}
	/* 将List倒入A[]并释放空间 */
	for (i = 0; i<N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
}

//void LSD(int a[],int n) {	//次位优先
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
//利用空间换取时间
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