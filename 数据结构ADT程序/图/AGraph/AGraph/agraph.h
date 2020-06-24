#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define maxSize 100
int visited[maxSize]; /* 访问标志数组 */

typedef struct ArcNode {
	int adjvex;//该边所指向的结点的位置
	struct ArcNode * nextarc;//指向下一条边的指针
	int info;//该边的相关信息（如权值），这一句用得不多，题目不做特殊要求可以不写
}ArcNode;
typedef struct {
	char data;//顶点信息
	ArcNode * firstarc;//指向第一条边的指针
}VNode;
typedef struct {
	VNode adjlist[maxSize];//邻接表
	int n, e;//顶点数和边数
}AGraph;//图的邻接表类型

void Visit(int v);//访问顶点v的操作函数
void CreateAGraph(AGraph * &G);//创建一个邻接表表示的图
void PrintAGraph(AGraph * G);//打印邻接表表示的图
void DFS(AGraph * G, int v);//邻接表的深度优先搜索遍历
void BFS(AGraph * G, int v);//邻接表的广度优先搜索遍历