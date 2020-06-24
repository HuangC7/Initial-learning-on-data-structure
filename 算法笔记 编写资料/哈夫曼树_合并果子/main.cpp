#include <cstdio>
#include <queue>
using namespace std;

//����С���ѵ����ȶ���
priority_queue<long long, vector<long long>, greater<long long> > q;

int main(){
    int n;
    long long temp, x, y, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%I64d", &temp);
        q.push(temp);       //����ʼ����ѹ�����ȶ���
    }
    while(q.size() > 1){    //ֻҪ���ȶ���������������Ԫ��
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);      //ȡ���Ѷ�������Ԫ�أ���ͺ�ѹ�����ȶ���
        ans += x + y;       //�ۼ���͵Ľ��
    }
    printf("%I64d\n", ans);  //ans��Ϊ���ĵ���С����
    return 0;
}
