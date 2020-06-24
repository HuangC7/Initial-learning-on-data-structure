#include <cstdio>
const int N = 110;
int father[N];  //��Ÿ��׽��
bool isRoot[N]; //��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����
int findFather(int x){  //����x���ڼ��ϵĸ����
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    //·��ѹ�����ɲ�д��
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

void Union(int a, int b){   //�ϲ�a��b���ڵļ���
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

void init(int n){   //��ʼ��father[i]Ϊi����flag[i]Ϊfalse
    for(int i = 1; i <= n; i++){
        father[i] = i;
        isRoot[i] = false;
    }
}

int main(){
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    init(n);    //Ҫ�ǵó�ʼ��
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        Union(a, b);    //�ϲ�a��b���ڵļ���
    }
    for(int i = 1; i <= n; i++){
        isRoot[findFather(i)] = true;   //i�ĸ������findFather(i)
    }
    int ans = 0;    //��¼������Ŀ
    for(int i = 1; i <= n; i++){
        ans += isRoot[i];
    }
    printf("%d\n", ans);

    return 0;
}
