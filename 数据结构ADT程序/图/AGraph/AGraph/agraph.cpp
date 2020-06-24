#include "agraph.h"
void Visit(int v) {
	cout << v << " ";
}
void CreateAGraph(AGraph * &G) {
	cout << "������ͼ�Ķ������ͱ�����";
	cin >> G->n >> G->e;
	cout << "������ͼ�����Ķ��㣺";
	for (int i = 0; i < G->n; ++i) {//�����ڽ�ͼ�Ķ���
		scanf("%c", &G->adjlist[i]);
		G->adjlist[i].firstarc = NULL;
	}
	cout << "������ߵĶ����<i, j>:";
	int i, j;
	for (int k = 0; k < G->e; k++) {
		ArcNode * p;
		scanf("%d%d", &i, &j);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = G->adjlist[i].firstarc;
		G->adjlist[i].firstarc = p;
		//����ͼ��Ҫ���в���
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = G->adjlist[j].firstarc;
		G->adjlist[j].firstarc = p;
	}

	
}
void PrintAGraph(AGraph * G) {
	for (int i = 0; i < G->n; ++i)
	{
		ArcNode * p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			printf("(%c,%c)", G->adjlist[i].data, G->adjlist[p->adjvex].data);
			p = p->nextarc;
		}
		printf("\n");
	}
}
void DFS(AGraph * G, int v) {
	ArcNode * p;
	visited[v] = 1;//���ѷ��ʱ��
	Visit(v);//���ʺ���Visit()������һ����ʶ���v�Ĳ���
	p = G->adjlist[v].firstarc;//pָ�򶥵�v�ĵ�һ����
	while (p != NULL) {
		if (visited[p->adjvex] == 0)//������δ���ʣ���ݹ������
			DFS(G, p->adjvex);
		p = p->nextarc;//pָ�򶥵�v����һ���ߵ��յ�
	}
}
void BFS(AGraph * G, int v) {
	ArcNode * p;
	int que[maxSize], front = 0, rear = 0;
	int j;
	Visit(v);//������ʶ���v�ĺ���
	visited[v] = 1;
	rear = (rear + 1) % maxSize;//��ǰ����v����
	que[rear] = v;
	while (front != rear) {//�ӿյ�ʱ��˵���������
		front = (front + 1) % maxSize;//�������
		j = que[front];
		p = G->adjlist[j].firstarc;//pָ����Ӷ���j�ĵ�һ����
		while (p != NULL) {//��p�������ڽӵ���δ�����ʵ����
			if (visited[p->adjvex] == 0) {//��ǰ�ڽӶ���δ�����ʣ������
				Visit(p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % maxSize;//�ö������
				que[rear] = p->adjvex;
			}
			p = p->nextarc;//pָ��j����һ����
		}
	}
	
}