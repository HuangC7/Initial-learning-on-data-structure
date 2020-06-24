#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Node{  //���徲̬��������1��
    int address, data, next;
    bool flag;  //����Ƿ���������
}node[maxn];

bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false){
        return a.flag > b.flag;  //ֻҪa��b����һ����Ч���Ͱ����ź���ȥ
    }else{
        return a.data < b.data;  //���������Ч��㣬��Ҫ������
    }
}
int main(void)
{
    for(int i = 0; i < maxn; i++){  //��ʼ��������2��
        node[i].flag = false;
    }
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for(int i = 0; i < n; i++){
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int count = 0, p = begin;
    //ö��������flag���б�ǣ�ͬʱ������Ч������������3��
    while(p != -1){
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if(count == 0){  //���У���������û�н��ʱ���0 -1
        printf("0 -1");
    }else{
        //ɸѡ��Ч��㣬����data��С�������򣨲���4��
        sort(node, node + maxn, cmp);
        //������������5��
        //��ֹ-1��%05d������ǰ�ж�
        printf("%d %05d\n", count, node[0].address);
        for(int i = 0; i < count; i++){
            if(i != count - 1){
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
            }else{
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }

    return 0;
}

