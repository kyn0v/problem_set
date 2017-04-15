#include <iostream>
using namespace std;

#define MaxVertexNum 100
typedef int DataType;
typedef int Vertex;
typedef int WeightType;

//各个结构的定义
typedef struct AdjVNode {
	Vertex AdjV;	//邻接点下标
	WeightType Weight;	//边权重
	AdjVNode* Next;
} *PtrToAdjVNode;

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;	//
	DataType data;	//存顶点的数据
} AdjList[MaxVertexNum];	//此乃C语言结构体数组声明方法

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;	//顶点数
	int Ne;	//边数
	AdjList G;	//邻接表
};
typedef PtrToGNode LGgaph;

//LGraph的初始化：1.初始化有顶点没有边的图 2.插入边
LGgaph Create(int VertexNum) {
	Vertex V, W;
	LGgaph Graph = new GNode;
	Graph->Ne = 0;
	Graph->Nv = VertexNum;
	for (V = 0; V < Graph->Nv; V++) {
		Graph->G[V].FirstEdge = NULL;	//初始化所有的空边
	}
	return Graph;
}

typedef struct ENode {
	Vertex V1, V2;	//有向边
	WeightType Weight;	//权重
	ENode():V1(0), V2(0), Weight(0) {}
	ENode(int v1, int v2, int weight) :V1(v1), V2(v2), Weight(weight) {}
} *PtrToENode;
typedef PtrToENode Edge;
//插入边
void InsertEdge(LGgaph Graph, Edge E) {
	//插入边<V1,V2>:
	//初始化待插入的邻接表结点
	PtrToAdjVNode NewNode = new AdjVNode;
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//插入结点至表头
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	//若为无向图，还要插入边<V2,V1>:
	NewNode = new AdjVNode;
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}


LGgaph BuildGraph() {
	LGgaph Graph;
	int Nv, Ne;	//顶点数、边数
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
	//如果结点中存有数据，还要读入数据
	for (Vertex V = 0; V < Graph->Nv; V++) {
		cin >> Graph->G[V].data;
	}
	return Graph;
}
/*
总结：邻接表的存储结构相当于将一个个链，挂在相应的数组元素上
				口口口口口口
				| | | | | |  <------FirstEdge
				@ # @ @ # #
				| | | | | |
				# @ # # @ #
				|     |   |
				#     @   #
*/
