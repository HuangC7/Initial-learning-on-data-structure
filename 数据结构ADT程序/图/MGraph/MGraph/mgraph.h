#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType char
#define maxSize 100
#define INF 100//INF是一个已经定义的比图中所有边权值都大的常量
/* 遍历函数(DFS,BFS)需要的辅助数组 */
int visit_DFS[maxSize], visit_BFS[maxSize]; /* 访问标志数组 */
/* Kruskal函数需要的结构和函数 */
typedef struct {
	int a, b;//a和b为一条边所连的两个顶点
	int w;//边的权值
}Road;
Road road[maxSize];//存放图中各边及其所连接的两个顶点的信息
int v[maxSize];//定义并查集数组(判断是否构成回路)
int getRoot(int a) {//在并查集中查找根结点的函数
	while (a != v[a])
		a = v[a];
	return a;
}
void sort(Road road[], int e) {//排序函数(不唯一)

}
/* Dijkstra函数所需要的函数 */
void printfPath(int path[], int a) {
	int stack[maxSize], top = -1;
	/* 这个循环以叶子结点到根结点的顺序将其入栈 */
	while (path[a] != -1) {
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;
	while (top != -1)
		cout << stack[top--] << " ";//出栈并打印出栈元素，实现了顶点的逆序打印
	cout << endl;
}
/* Floyd函数所需要的函数 */
void printPath(int u, int v, int path[][maxSize], MGraph g) {//输出从u到v的最短路径上顶点序列
	if (path[u][v] == -1)
		cout << g.edges[u][v];//直接输出
	else {
		int mid = path[u][v];
		printPath(u, mid, path, g);//处理mid前半段路径
		printPath(mid, v, path, g);//处理mid后半段路径
	}
}
/* 邻接矩阵表示的图的定义 */
typedef struct {
	int no;//顶点编号
	ElemType info;//顶点其他信息，默认为char类型
}VertexType;//顶点类型
typedef struct {//图的定义
	int edges[maxSize][maxSize];
	//邻接矩阵定义，如果是有权图，则在此句中将int改为float
	int n, e;//分别为顶点数和边数
	VertexType vex[maxSize];//存放结点信息
}MGraph;//图的邻接矩阵类型


void visit(int v);//访问顶点v的操作函数
void CreateMGraph(MGraph &G);//创建一个邻接矩阵表示的图
void DFS(MGraph G, int v);//邻接矩阵的深度优先搜索遍历
void DFSTrave(MGraph G);//深度优先搜索遍历图G
void BFS(MGraph G, int v);//邻接矩阵的广度优先搜索遍历
void BFSTrave(MGraph G);//广度优先搜索遍历图G
void Prim(MGraph g, int v0, int &sum);//普里姆算法构造邻接矩阵表示的图的最小生成树
void Kruskal(MGraph g, int &sum, Road road[]);////克鲁斯卡尔算法构造邻接矩阵表示的图的最小生成树
void Dijkstra(MGraph g, int v, int dist[], int path[]);//迪杰斯特拉算法求邻接矩阵表示的图的最短路径(某一顶点到其余各顶点的最短路径)
void Floyd(MGraph g, int Path[][maxSize]);//弗洛伊德算法求邻接矩阵表示的图的最短路径(任意一对顶点间的最短路径)