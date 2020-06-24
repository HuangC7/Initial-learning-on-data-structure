#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node{
    int data;
    node * lchild;
    node * rchild;
};
int pre[maxn], in[maxn], post[maxn];    //�������򡢺���
int n;  //������

//��ǰ�������ĺ�����������Ϊ[postL, postR],������������Ϊ[inL, inR]
//create�������ع������Ķ������ĸ�����ַ
node* create(int postL, int postR, int inL, int inR){
    if(postL > postR){
        return NULL;  //�������г���С�ڵ���0ʱ��ֱ�ӷ���
    }
    node* root = new node;  //�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����
    root->data = post[postR];  //�½���������Ϊ������ֵ
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR]){  //�������������ҵ�in[k] == pre[L]�Ľ��
            break;
        }
    }
    int numLeft = k - inL;  //�������Ľ�����
    //�����������ĸ�����ַ����ֵ��root����ָ��
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    //�����������ĸ�����ַ����ֵ��root����ָ��
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;  //���ظ�����ַ
}

int num = 0;  //������Ľ�����
void BFS(node* root){
    queue<node*> q;  //ע��������Ǵ��ַ
    q.push(root);  //��������ַ���
    while(!q.empty()){
        node* now = q.front();  //ȡ������Ԫ��
        q.pop();
        printf("%d", now->data);  //���ʶ���Ԫ��
        num++;
        if(num < n) printf(" ");
        if(now->lchild != NULL) q.push(now->lchild);  //�������ǿ�
        if(now->rchild != NULL) q.push(now->rchild);  //�������ǿ�
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);    //����
    BFS(root);      //�������

    return 0;
}
