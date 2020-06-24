#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 110;
struct node{
    int weight;         //������
    vector<int> child;  //ָ����
}Node[MAXN];
bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;     //�����������Ӵ�С����
}
int n, m, S;        //������������������ĺ�
int path[MAXN];     //��¼·��

//��ǰ���ʽ��Ϊindex��numNodeΪ��ǰ·��path�ϵĽ�����
//sumΪ��ǰ�Ľ���Ȩ��
void DFS(int index, int numNode, int sum){
    if(sum > S) return;     //��ǰ��sum����S��ֱ�ӷ���
    if(sum == S){           //��ǰ��sum����S
        if(Node[index].child.size() != 0) return;   //��û��Ҷ�ӽ�㣬ֱ�ӷ���
        //����Ҷ�ӽ�㣬��ʱpath[]�д����һ��������·���������
        for(int i = 0; i < numNode; i++){
            printf("%d", Node[path[i]].weight);
            if(i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return;     //����
    }
    for(int i = 0; i < Node[index].child.size(); i++){      //ö�������ӽ��
        int child = Node[index].child[i];       //���index�ĵ�i���ӽ����
        path[numNode] = child;      //�����child�ӵ�·��pathĩβ
        DFS(child, numNode + 1, sum + Node[child].weight);  //�ݹ������һ��
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &S);
    for(int i = 0; i < n; i++){
        scanf("%d", &Node[i].weight);
    }
    int id, k, child;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &id, &k);     //����š����Ӹ���
        for(int j = 0; j < k; j++){
            scanf("%d", &child);
            Node[id].child.push_back(child);    //childΪ���id�ĺ���
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);    //����
    }
    path[0] = 0;    //·���ĵ�һ���������Ϊ0�Ž��
    DFS(0, 1, Node[0].weight);  //DFS���

    return 0;
}
