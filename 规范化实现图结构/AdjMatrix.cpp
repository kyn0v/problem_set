#include <iostream>
using namespace std;

typedef int WeightType;
typedef int DataType;	//结点储存的数据类型
typedef int Vertex;	//定义顶点类型，为整型，与整型的逻辑含义不同

#define MaxVertexNum 100

//图结构的定义
typedef struct GNode *PtrToGno;
struct GNode	//应以一名“攻城狮”的标准要求自己，注重代码的封装
{
	int Ne;	//顶点数
	int Nv;	//边数
	WeightType G[MaxVertexNum][MaxVertexNum]; //邻接矩阵
	DataType Data[MaxVertexNum];	//存储顶点的数据
};
typedef PtrToGno MGraph;

//图的建立：1.建立图的定点 2.插入图的边

MGraph CreateGraph(int VertexNum) {	//1.建立有结点无边的图
	Vertex V, W;
	MGraph Graph = new GNode;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	
	//默认顶点编号是从0开始
	for (Vertex V = 0; V < Graph->Nv; V++) {
		for (Vertex W = 0; W < Graph->Nv; W++) {
			Graph->G[V][W] = 0;	//或INFINITY
		}
	}
	return Graph;
}

typedef struct ENode *PtrToEnode;//定义边结构
struct ENode
{
	Vertex V1, V2;	//有向边
	WeightType Weight;	//权重
	ENode() :V1(0), V2(0), Weight(0) {}
	ENode(int v1, int v2, int weight) :V1(v1), V2(v2), Weight(weight) {}
};
typedef PtrToEnode Edge;
void InsertEdge(MGraph Graph, Edge E) {	//2.插入边
	Graph->G[E->V1][E->V2] = E->Weight;
	//若为无向图，还应继续赋值
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
	MGraph Graph;
	int Nv, Ne;	//顶点数、边数
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
	//如果结点中存有数据，还要读入数据
	for (Vertex V = 0; V < Graph->Nv; V++) {
		cin >> Graph->Data[V];
	}
	return Graph;
}