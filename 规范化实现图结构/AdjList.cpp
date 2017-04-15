#include <iostream>
using namespace std;

#define MaxVertexNum 100
typedef int DataType;
typedef int Vertex;
typedef int WeightType;

//�����ṹ�Ķ���
typedef struct AdjVNode {
	Vertex AdjV;	//�ڽӵ��±�
	WeightType Weight;	//��Ȩ��
	AdjVNode* Next;
} *PtrToAdjVNode;

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;	//
	DataType data;	//�涥�������
} AdjList[MaxVertexNum];	//����C���Խṹ��������������

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;	//������
	int Ne;	//����
	AdjList G;	//�ڽӱ�
};
typedef PtrToGNode LGgaph;

//LGraph�ĳ�ʼ����1.��ʼ���ж���û�бߵ�ͼ 2.�����
LGgaph Create(int VertexNum) {
	Vertex V, W;
	LGgaph Graph = new GNode;
	Graph->Ne = 0;
	Graph->Nv = VertexNum;
	for (V = 0; V < Graph->Nv; V++) {
		Graph->G[V].FirstEdge = NULL;	//��ʼ�����еĿձ�
	}
	return Graph;
}

typedef struct ENode {
	Vertex V1, V2;	//�����
	WeightType Weight;	//Ȩ��
	ENode():V1(0), V2(0), Weight(0) {}
	ENode(int v1, int v2, int weight) :V1(v1), V2(v2), Weight(weight) {}
} *PtrToENode;
typedef PtrToENode Edge;
//�����
void InsertEdge(LGgaph Graph, Edge E) {
	//�����<V1,V2>:
	//��ʼ����������ڽӱ���
	PtrToAdjVNode NewNode = new AdjVNode;
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//����������ͷ
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	//��Ϊ����ͼ����Ҫ�����<V2,V1>:
	NewNode = new AdjVNode;
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}


LGgaph BuildGraph() {
	LGgaph Graph;
	int Nv, Ne;	//������������
	cin >> Nv;
	Graph = Create(Nv);
	cin >> Graph->Ne;
	if (!Graph->Ne) {
		Edge E = new ENode;
		for (int i = 0; i < Graph->Ne; i++) {
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph, E);
		}
	}
	//�������д������ݣ���Ҫ��������
	for (Vertex V = 0; V < Graph->Nv; V++) {
		cin >> Graph->G[V].data;
	}
	return Graph;
}
/*
�ܽ᣺�ڽӱ�Ĵ洢�ṹ�൱�ڽ�һ��������������Ӧ������Ԫ����
				�ڿڿڿڿڿ�
				| | | | | |  <------FirstEdge
				@ # @ @ # #
				| | | | | |
				# @ # # @ #
				|     |   |
				#     @   #
*/
