#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define maxSize 100
int visited[maxSize]; /* ���ʱ�־���� */

typedef struct ArcNode {
	int adjvex;//�ñ���ָ��Ľ���λ��
	struct ArcNode * nextarc;//ָ����һ���ߵ�ָ��
	int info;//�ñߵ������Ϣ����Ȩֵ������һ���õò��࣬��Ŀ��������Ҫ����Բ�д
}ArcNode;
typedef struct {
	char data;//������Ϣ
	ArcNode * firstarc;//ָ���һ���ߵ�ָ��
}VNode;
typedef struct {
	VNode adjlist[maxSize];//�ڽӱ�
	int n, e;//�������ͱ���
}AGraph;//ͼ���ڽӱ�����

void Visit(int v);//���ʶ���v�Ĳ�������
void CreateAGraph(AGraph * &G);//����һ���ڽӱ��ʾ��ͼ
void PrintAGraph(AGraph * G);//��ӡ�ڽӱ��ʾ��ͼ
void DFS(AGraph * G, int v);//�ڽӱ�����������������
void BFS(AGraph * G, int v);//�ڽӱ�Ĺ��������������