#include "agraph.h"
void Visit(int v) {
	cout << v << " ";
}
void CreateAGraph(AGraph * &G) {
	cout << "请输入图的顶点数和边数：";
	cin >> G->n >> G->e;
	cout << "请输入图包含的顶点：";
	for (int i = 0; i < G->n; ++i) {//输入邻接图的顶点
		scanf("%c", &G->adjlist[i]);
		G->adjlist[i].firstarc = NULL;
	}
	cout << "输入各边的顶点队<i, j>:";
	int i, j;
	for (int k = 0; k < G->e; k++) {
		ArcNode * p;
		scanf("%d%d", &i, &j);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = G->adjlist[i].firstarc;
		G->adjlist[i].firstarc = p;
		//无向图需要下列操作
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
	visited[v] = 1;//置已访问标记
	Visit(v);//访问函数Visit()代表了一类访问顶点v的操作
	p = G->adjlist[v].firstarc;//p指向顶点v的第一条边
	while (p != NULL) {
		if (visited[p->adjvex] == 0)//若顶点未访问，则递归访问它
			DFS(G, p->adjvex);
		p = p->nextarc;//p指向顶点v的下一条边的终点
	}
}
void BFS(AGraph * G, int v) {
	ArcNode * p;
	int que[maxSize], front = 0, rear = 0;
	int j;
	Visit(v);//任意访问顶点v的函数
	visited[v] = 1;
	rear = (rear + 1) % maxSize;//当前顶点v进队
	que[rear] = v;
	while (front != rear) {//队空的时候说明遍历完成
		front = (front + 1) % maxSize;//顶点出队
		j = que[front];
		p = G->adjlist[j].firstarc;//p指向出队顶点j的第一条边
		while (p != NULL) {//将p的所有邻接点中未被访问的入队
			if (visited[p->adjvex] == 0) {//当前邻接顶点未被访问，则进队
				Visit(p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % maxSize;//该顶点进队
				que[rear] = p->adjvex;
			}
			p = p->nextarc;//p指向j的下一条边
		}
	}
	
}