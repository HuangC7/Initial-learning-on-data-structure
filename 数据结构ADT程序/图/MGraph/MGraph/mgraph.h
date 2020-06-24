#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType char
#define maxSize 100
#define INF 100//INF��һ���Ѿ�����ı�ͼ�����б�Ȩֵ����ĳ���
/* ��������(DFS,BFS)��Ҫ�ĸ������� */
int visit_DFS[maxSize], visit_BFS[maxSize]; /* ���ʱ�־���� */
/* Kruskal������Ҫ�Ľṹ�ͺ��� */
typedef struct {
	int a, b;//a��bΪһ������������������
	int w;//�ߵ�Ȩֵ
}Road;
Road road[maxSize];//���ͼ�и��߼��������ӵ������������Ϣ
int v[maxSize];//���岢�鼯����(�ж��Ƿ񹹳ɻ�·)
int getRoot(int a) {//�ڲ��鼯�в��Ҹ����ĺ���
	while (a != v[a])
		a = v[a];
	return a;
}
void sort(Road road[], int e) {//������(��Ψһ)

}
/* Dijkstra��������Ҫ�ĺ��� */
void printfPath(int path[], int a) {
	int stack[maxSize], top = -1;
	/* ���ѭ����Ҷ�ӽ�㵽������˳������ջ */
	while (path[a] != -1) {
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;
	while (top != -1)
		cout << stack[top--] << " ";//��ջ����ӡ��ջԪ�أ�ʵ���˶���������ӡ
	cout << endl;
}
/* Floyd��������Ҫ�ĺ��� */
void printPath(int u, int v, int path[][maxSize], MGraph g) {//�����u��v�����·���϶�������
	if (path[u][v] == -1)
		cout << g.edges[u][v];//ֱ�����
	else {
		int mid = path[u][v];
		printPath(u, mid, path, g);//����midǰ���·��
		printPath(mid, v, path, g);//����mid����·��
	}
}
/* �ڽӾ����ʾ��ͼ�Ķ��� */
typedef struct {
	int no;//������
	ElemType info;//����������Ϣ��Ĭ��Ϊchar����
}VertexType;//��������
typedef struct {//ͼ�Ķ���
	int edges[maxSize][maxSize];
	//�ڽӾ����壬�������Ȩͼ�����ڴ˾��н�int��Ϊfloat
	int n, e;//�ֱ�Ϊ�������ͱ���
	VertexType vex[maxSize];//��Ž����Ϣ
}MGraph;//ͼ���ڽӾ�������


void visit(int v);//���ʶ���v�Ĳ�������
void CreateMGraph(MGraph &G);//����һ���ڽӾ����ʾ��ͼ
void DFS(MGraph G, int v);//�ڽӾ�������������������
void DFSTrave(MGraph G);//���������������ͼG
void BFS(MGraph G, int v);//�ڽӾ���Ĺ��������������
void BFSTrave(MGraph G);//���������������ͼG
void Prim(MGraph g, int v0, int &sum);//����ķ�㷨�����ڽӾ����ʾ��ͼ����С������
void Kruskal(MGraph g, int &sum, Road road[]);////��³˹�����㷨�����ڽӾ����ʾ��ͼ����С������
void Dijkstra(MGraph g, int v, int dist[], int path[]);//�Ͻ�˹�����㷨���ڽӾ����ʾ��ͼ�����·��(ĳһ���㵽�������������·��)
void Floyd(MGraph g, int Path[][maxSize]);//���������㷨���ڽӾ����ʾ��ͼ�����·��(����һ�Զ��������·��)