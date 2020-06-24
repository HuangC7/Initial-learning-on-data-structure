#include "mgraph.h"
void visit(int v) {
	cout << v << " ";
}
void CreateMGraph(MGraph &G) {
	cout << "请输入图的顶点数和边数：";
	cin >> G.n >> G.e;
	for (int i = 0; i < G.n; ++i)//初始化图
		for (int j = 0; j < G.n; ++j)
			G.edges[i][j] = 0;
	cout << "\n" << "请输入图的顶点之间的关系或权值:";
	for (int i = 0; i < G.n; ++i)//建立图
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
	int que[maxSize], front = 0, rear = 0;//定义一个队列

	memset(visit_BFS, 0, sizeof(int));
	visit(v);
	visit_BFS[v] = true;
	rear = (rear + 1) % maxSize;//当前顶点v入队
	que[rear] = v;
	while (front != rear) {//队空时遍历完成
		front = (front + 1) % maxSize;//顶点出队
		v = que[front];
		for(int vj = 0; vj < G.n; ++vj)
			if (!visit_BFS[vj] && G.edges[v][vj] == 1) {
				visit(vj);
				visit_BFS[vj] = true;
				rear = (rear + 1) % maxSize;//当前顶点v入队
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
	vset[v0] = 1;//将v0并入树中
	for (i = 0; i < g.n - 1; ++i) {
		cout << v << " ";
		min = maxSize;
		/* 下面这个循环用于选出候选边中的最小者 */
		for (j = 0; j < g.n; ++j) 
			if (vset[j] == 0 && lowcost[j] < min) {//选出当前生成树到其余顶点最短边中的最短一条
				min = lowcost[j];
				k = j;
			}
		
		cout << v << k << endl;
		vset[k] = 1;
		v = k;
		sum += min;//这里用sum记录了最小生成树的权值
		/* 下面这个循环以刚并入的顶点v为媒介更新候选边 */
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
	sort(road, E);//对road数组中的E条边按其权值从小到大排序
	for (i = 0; i < E; ++i) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			sum += road[i].w;//求生成树的权值，这句并不是本算法的固定
							 //写法，也可以改成其他的。例如，将生成树中的
							 //各边输出，或者存放在数组里
		}
	}
}
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
	int set[maxSize];
	int min, i, j, u;
	/* 从这句开始对各数组进行初始化 */
	for (i = 0; i < g.n; ++i) {
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	set[v] = 1; path[v] = -1;
	/* 初始化结束 */
	/* 关键操作开始 */
	for (i = 0; i < g.n; ++i) {
		min = INF;
		/* 这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的 */
		for(j = 0; j < g.n; ++j)
			if (set[j] == 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		set[u] = 1;//将选出的顶点并入最短路径
		/* 这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检查 */
		for (j = 0; j < g.n; ++j) {
			/* 这个if语句判断顶点u的加入是否会出现通往顶点j的更短的路径，如果出现，则改变原来路径及其长度，否则什么都不做 */
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}
	}
	/* 关键操作结束 */
}
/* 函数结束时，dist[]数组中存放了v点到其余顶点的最短路径长度,path[]中存放v点到其余各顶点的最短路径 */
void Floyd(MGraph g, int Path[][maxSize]) {
	int i, j, k;
	int A[maxSize][maxSize];
	/* 这个双循环对数组A[][]和Path[][]进行了初始化 */
	for(i = 0; i < g.n; ++i)
		for (j = 0; j < g.n; ++j) {
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}
	/* 下面这个三层循环是本算法的主要操作，完成了以k为中间点对所有的顶点对{i,j}进行检测和修改 */
	for(k = 0; k < g.n; ++k)
		for (i = 0; i < g.n; ++i)
			for (j = 0; j < g.n; ++j)
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					Path[i][j] = k;
				}
}