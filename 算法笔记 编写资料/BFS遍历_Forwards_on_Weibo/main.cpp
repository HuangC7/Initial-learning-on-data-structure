#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1010;
struct Node{
    int id;     //�����
    int layer;  //�����
};

vector<Node> Adj[MAXV];     //�ڽӱ�
bool inq[MAXV] = {false};   //�����Ƿ��ѱ����������

int BFS(int s, int L){      //startΪ��ʼ��㣬LΪ��������
    int numForward = 0;     //ת����
    queue<Node> q;          //BFS����
    Node start;             //������ʼ���
    start.id = s;           //��ʼ�����
    start.layer = 0;        //��ʼ�����Ϊ0
    q.push(start);          //����ʼ���ѹ�����
    inq[start.id] = true;   //��ʼ���ı����Ϊ�ѱ����������
    while(!q.empty()){
        Node topNode = q.front();   //ȡ�����׽��
        q.pop();        //���׽�����
        int u = topNode.id;         //���׽��ı��
        for(int i = 0; i < Adj[u].size(); i++){
            Node next = Adj[u][i];  //��u�����ܵ���Ľ��next
            next.layer = topNode.layer + 1;     //next�Ĳ�ŵ��ڵ�ǰ����ż�1
            //���next�ı��δ����������У���next�Ĳ�β���������L
            if(inq[next.id] == false && next.layer <= L){
                q.push(next);       //��next���
                inq[next.id] = true;    //next�ı����Ϊ�ѱ����������
                numForward++;       //ת������1
            }
        }
    }
    return numForward;      //����ת����
}
int main(){
    Node user;
    int n, L, numFollow, idFollow;
    scanf("%d%d", &n, &L);          //����������������
    for(int i = 1; i <= n; i++){
        user.id = i;             //�û����Ϊi
        scanf("%d", &numFollow);    //i���û���ע������
        for(int j = 0; j < numFollow; j++){
            scanf("%d", &idFollow);     //i���û���ע���û����
            Adj[idFollow].push_back(user);  //��idFollow->i
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);             //��ѯ����
    for(int i = 0; i < numQuery; i++){
        memset(inq, false, sizeof(inq));    //inq�����ʼ��
        scanf("%d", &s);                    //��ʼ�����
        int numForward = BFS(s, L);         //BFS,����ת����
        printf("%d\n", numForward);         //���ת����
    }

    return 0;
}
