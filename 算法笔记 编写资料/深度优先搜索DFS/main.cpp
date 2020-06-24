#include <cstdio>
const int maxn = 30;
int n, V, maxValue = 0;  //��Ʒ����n����������V������ֵmaxValue
int w[maxn], c[maxn];  //w[i]Ϊÿ����Ʒ��������c[i]Ϊÿ����Ʒ�ļ�ֵ
//DFS,indexΪ��ǰ�������Ʒ���
//sumW��sumC�ֱ�Ϊ��ǰ�������͵�ǰ�ܼ�ֵ
void DFS(int index, int sumW, int sumC){
    if(index == n){
        return;  //�Ѿ���ɶ�n����Ʒ��ѡ��
    }
    DFS(index + 1, sumW, sumC);  //��ѡ��index����Ʒ
    //ֻ�м����index����Ʒ��δ��������V�����ܼ���
    if(sumW + w[index] <= V){
        if(sumC + c[index] > maxValue){
            maxValue = sumC + c[index];  //��������ֵmaxValue
        }
        DFS(index + 1, sumW + w[index], sumC + c[index]);  //ѡ��index����Ʒ
    }

//    if(index == n){  //�Ѿ���ɶ�n����Ʒ��ѡ������ͬ��
//        if(sumW <= V && sumC > maxValue){
//            maxValue = sumC;  //��������������ʱ��������ֵmaxValue
//        }
//        return;
//    }
//    //��·��
//    DFS(index + 1, sumW, sumC);  //��ѡ��index����Ʒ
//    DFS(index + 1, sumW + w[index], sumC + c[index]);  //ѡ��index����Ʒ
}

int main()
{
    scanf("%d%d", &n, &V);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);  //ÿ����Ʒ������
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);  //ÿ����Ʒ�ļ�ֵ
    }
    DFS(0, 0, 0);  //��ʼʱΪ��0����Ʒ����ǰ���������ܼ�ֵ��Ϊ0
    printf("%d\n", maxValue);

    return 0;
}
