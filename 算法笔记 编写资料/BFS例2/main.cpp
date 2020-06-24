#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100;
struct node{
    int x, y;   //λ��(x, y)
    int step;   //stepΪ�����S�����λ�õ����ٲ���(������)
}S, T, Node;

int n, m;       //nΪ�У�mΪ��
char maze[maxn][maxn];          //�Թ���Ϣ
bool inq[maxn][maxn] = {false};     //��¼λ��(x, y)�Ƿ��������
int X[4] = {0, 0, 1, -1};          //��������
int Y[4] = {1, -1, 0, 0};

//���λ��(x, y)�Ƿ���Ч
bool test(int x, int y){
    if(x >= n || x < 0 || y >= m || y < 0) return false;    //�����߽�
    if(maze[x][y] == '*') return false;     //ǽ��*
    if(inq[x][y] == true) return false;     //�������
    return true;  //��Чλ��
}

int BFS(){
    queue<node> q;      //�������
    q.push(S);          //�����S���
    while(!q.empty()){
        node top = q.front();  //ȡ������Ԫ��
        q.pop();               //����Ԫ�س���
        if(top.x == T.x && top.y == T.y){
             return top.step;   //�յ㣬ֱ�ӷ������ٲ���
        }
        for(int i = 0; i < 4; i++){     //ѭ��4�Σ��õ�4������λ��
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(test(newX, newY)){       //λ��(newX, newY)��Ч
                //����Node������Ϊ(newX, newY)
                Node.x = newX, Node.y = newY;
                Node.step = top.step + 1;       //Node����Ϊtop�Ĳ�����1
                q.push(Node);                   //�����Node�������
                inq[newX][newY] = true;    //����λ��(newX, newY)�������
            }
        }
    }
    return -1;  //�޷������յ�Tʱ����-1
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        getchar();  //���˵�ÿ�к���Ļ��з�
        for(int j = 0; j < m; j++){
            maze[i][j] = getchar();
        }
        maze[i][m + 1] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);    //�����յ������
    S.step = 0;     //��ʼ�����Ĳ���Ϊ0����S��S�����ٲ���Ϊ0
    printf("%d\n", BFS());

    return 0;
}
