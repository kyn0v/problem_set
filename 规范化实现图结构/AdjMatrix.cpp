#include <iostream>
using namespace std;

typedef int WeightType;
typedef int DataType;	//��㴢�����������
typedef int Vertex;	//���嶥�����ͣ�Ϊ���ͣ������͵��߼����岻ͬ

#define MaxVertexNum 100

//ͼ�ṹ�Ķ���
typedef struct GNode *PtrToGno;
struct GNode	//Ӧ��һ��������ʨ���ı�׼Ҫ���Լ���ע�ش���ķ�װ
{
	int Ne;	//������
	int Nv;	//����
	WeightType G[MaxVertexNum][MaxVertexNum]; //�ڽӾ���
	DataType Data[MaxVertexNum];	//�洢���������
};
typedef PtrToGno MGraph;

//ͼ�Ľ�����1.����ͼ�Ķ��� 2.����ͼ�ı�

MGraph CreateGraph(int VertexNum) {	//1.�����н���ޱߵ�ͼ
	Vertex V, W;
	MGraph Graph = new GNode;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	
	//Ĭ�϶������Ǵ�0��ʼ
	for (Vertex V = 0; V < Graph->Nv; V++) {
		for (Vertex W = 0; W < Graph->Nv; W++) {
			Graph->G[V][W] = 0;	//��INFINITY
		}
	}
	return Graph;
}

typedef struct ENode *PtrToEnode;//����߽ṹ
struct ENode
{
	Vertex V1, V2;	//�����
	WeightType Weight;	//Ȩ��
	ENode() :V1(0), V2(0), Weight(0) {}
	ENode(int v1, int v2, int weight) :V1(v1), V2(v2), Weight(weight) {}
};
typedef PtrToEnode Edge;
void InsertEdge(MGraph Graph, Edge E) {	//2.�����
	Graph->G[E->V1][E->V2] = E->Weight;
	//��Ϊ����ͼ����Ӧ������ֵ
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
	MGraph Graph;
	int Nv, Ne;	//������������
	cin >> Nv;
	Graph = CreateGraph(Nv);
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
		cin >> Graph->Data[V];
	}
	return Graph;
}