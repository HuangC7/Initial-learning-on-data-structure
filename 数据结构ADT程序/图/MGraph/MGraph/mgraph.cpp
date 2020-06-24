#include "mgraph.h"
void visit(int v) {
	cout << v << " ";
}
void CreateMGraph(MGraph &G) {
	cout << "������ͼ�Ķ������ͱ�����";
	cin >> G.n >> G.e;
	for (int i = 0; i < G.n; ++i)//��ʼ��ͼ
		for (int j = 0; j < G.n; ++j)
			G.edges[i][j] = 0;
	cout << "\n" << "������ͼ�Ķ���֮��Ĺ�ϵ��Ȩֵ:";
	for (int i = 0; i < G.n; ++i)//����ͼ
		for (int j = 0; j < G.n; ++j)
			cin >> G.edges[i][j];
}
void DFS(MGraph G, int v) {
	memset(visit_DFS, 0, sizeof(int));
	visit(v);
	visit_DFS[v] = true;
	for (int vj = 0; vj < G.n; ++vj)
		if (!visit_DFS[vj] && G.edges[v][vj] == 1)
			DFS(G, vj);
}
void DFSTrave(MGraph G) {
	for (int v = 0; v < G.n; ++v)
		if (!visit_DFS[v])
			DFS(G, v);
}
void BFS(MGraph G, int v) {
	int que[maxSize], front = 0, rear = 0;//����һ������

	memset(visit_BFS, 0, sizeof(int));
	visit(v);
	visit_BFS[v] = true;
	rear = (rear + 1) % maxSize;//��ǰ����v���
	que[rear] = v;
	while (front != rear) {//�ӿ�ʱ�������
		front = (front + 1) % maxSize;//�������
		v = que[front];
		for(int vj = 0; vj < G.n; ++vj)
			if (!visit_BFS[vj] && G.edges[v][vj] == 1) {
				visit(vj);
				visit_BFS[vj] = true;
				rear = (rear + 1) % maxSize;//��ǰ����v���
				que[rear] = vj;
			}
	}
}
void BFSTrave(MGraph G) {
	for (int v = 0; v < G.n; ++v)
		if (!visit_BFS[v])
			BFS(G, v);
}
void Prim(MGraph g, int v0, int &sum) {
	int lowcost[maxSize], vset[maxSize], v;
	int i, j, k, min;
	v = v0;
	for (i = 0; i < g.n; ++i) {
		lowcost[i] = g.edges[v0][i];
		vset[i] = 0;
	}
	vset[v0] = 1;//��v0��������
	for (i = 0; i < g.n - 1; ++i) {
		cout << v << " ";
		min = maxSize;
		/* �������ѭ������ѡ����ѡ���е���С�� */
		for (j = 0; j < g.n; ++j) 
			if (vset[j] == 0 && lowcost[j] < min) {//ѡ����ǰ�����������ඥ����̱��е����һ��
				min = lowcost[j];
				k = j;
			}
		
		cout << v << k << endl;
		vset[k] = 1;
		v = k;
		sum += min;//������sum��¼����С��������Ȩֵ
		/* �������ѭ���Ըղ���Ķ���vΪý����º�ѡ�� */
		for (j = 0; j < g.n; ++j)
			if (vset[j] == 0 && g.edges[v][j] < lowcost[j])
				lowcost[j] = g.edges[v][j];
	}
	cout << endl;
}
void Kruskal(MGraph g, int &sum, Road road[]) {
	int i;
	int N, E, a, b;
	N = g.n;
	E = g.e;
	sum = 0;
	for (i = 0; i < N; ++i)
		v[i] = i;
	sort(road, E);//��road�����е�E���߰���Ȩֵ��С��������
	for (i = 0; i < E; ++i) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			sum += road[i].w;//����������Ȩֵ����䲢���Ǳ��㷨�Ĺ̶�
							 //д����Ҳ���Ըĳ������ġ����磬���������е�
							 //������������ߴ����������
		}
	}
}
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
	int set[maxSize];
	int min, i, j, u;
	/* ����俪ʼ�Ը�������г�ʼ�� */
	for (i = 0; i < g.n; ++i) {
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	set[v] = 1; path[v] = -1;
	/* ��ʼ������ */
	/* �ؼ�������ʼ */
	for (i = 0; i < g.n; ++i) {
		min = INF;
		/* ���ѭ��ÿ�δ�ʣ�ඥ����ѡ��һ�����㣬ͨ����������·����ͨ������ʣ�ඥ���·�����ǳ�����̵� */
		for(j = 0; j < g.n; ++j)
			if (set[j] == 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		set[u] = 1;//��ѡ���Ķ��㲢�����·��
		/* ���ѭ���Ըղ���Ķ�����Ϊ�м�㣬������ͨ��ʣ�ඥ���·�����м�� */
		for (j = 0; j < g.n; ++j) {
			/* ���if����ж϶���u�ļ����Ƿ�����ͨ������j�ĸ��̵�·����������֣���ı�ԭ��·�����䳤�ȣ�����ʲô������ */
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}
	}
	/* �ؼ��������� */
}
/* ��������ʱ��dist[]�����д����v�㵽���ඥ������·������,path[]�д��v�㵽�������������·�� */
void Floyd(MGraph g, int Path[][maxSize]) {
	int i, j, k;
	int A[maxSize][maxSize];
	/* ���˫ѭ��������A[][]��Path[][]�����˳�ʼ�� */
	for(i = 0; i < g.n; ++i)
		for (j = 0; j < g.n; ++j) {
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}
	/* �����������ѭ���Ǳ��㷨����Ҫ�������������kΪ�м������еĶ����{i,j}���м����޸� */
	for(k = 0; k < g.n; ++k)
		for (i = 0; i < g.n; ++i)
			for (j = 0; j < g.n; ++j)
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					Path[i][j] = k;
				}
}