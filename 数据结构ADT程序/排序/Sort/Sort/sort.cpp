#include "sort.h"

void InsertSort(int R[], int n) {//���Źؼ��ִ洢��R[]�У�Ĭ��Ϊ���ͣ�����Ϊn
	int i, j;
	int temp;
	for (i = 1; i < n; ++i) {
		temp = R[i];//��������ؼ����ݴ���temp��
		j = i - 1;
		/* �������ѭ������˴Ӵ��Źؼ���֮ǰ�Ĺؼ��ֿ�ʼɨ�裬������ڴ��Źؼ��֣������һλ */
		while (j >= 0 && temp < R[j]) {
			R[j + 1] = R[j];
			--j;
		}
		R[j + 1] = temp;
	}
}
void BInsertSort(int R[], int n) {
	int i, j;
	int temp;
	int low, high, m;
	for (i = 1; i < n; ++i) {
		temp = R[i];//��R[i]�ݴ浽temp
		low = 0; high = i - 1;
		while (low <= high) {//��R[low...high]���۰������������λ��
			m = (low + high) / 2;//�۰�
			if (temp < R[m]) high = m - 1;//������ڵͰ���
			else low = m + 1;//������ڸ߰���
		}
		for (j = i - 1; j >= high + 1; --j) R[j + 1] = R[j];//��¼����
		R[high + 1] = temp;//����
	}
}
void ShellSort(int R[], int n, int dlta[], int t) {
	//����������dlta[0...t-1]��˳���L��ϣ������
	for (int k = 0; k < t; ++k)
		ShellInsert(R, dlta[k], n);
}
void BubbleSort(int R[], int n) {//Ĭ�ϴ�����ؼ���Ϊ����
	int i, j, flag;
	int temp;
	for (i = n - 1; i >= 1; --i) {
		flag = 0;//����flag������Ǳ��������Ƿ����˽���
		for(j = 1; j <= i; ++j)
			if (R[j - 1] > R[j]) {
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				flag = 1;//���û��������,��flag��ֵΪ0;�����������,��flag��ֵΪ1
			}
		if (flag == 0)//һ�����������û�з����ؼ��ʽ�������֤�����������������
			return;
	}
}
void QuickSort(int R[], int low, int high) {//�Դ�R[low]��R[high]�Ĺؼ��ֽ�������
	int temp;
	int i = low, j = high;
	if (low < high) {
		temp = R[low];
		/* �������ѭ�������һ�����򣬼���������С��temp�Ĺؼ��ַ�����ߣ�����temp�Ĺؼ��ַ����ұ� */
		while (i < j) {
			while (j > i && R[j] >= temp) --j;//��������ɨ�裬�ҵ�һ��С��temp�Ĺؼ���
			if (i < j) {
				R[i] = R[j];//����temp���
				++i;//i����һλ
			}
			while (i < j && R[i] < temp) ++i;//��������ɨ�裬���ҵ�һ������temp�Ĺؼ���
			if (i < j) {
				R[j] = R[i];//����temp�ұ�
				--j;//j����һλ
			}
		}
		R[i] = temp;//��temp��������λ��
		QuickSort(R, low, i - 1);//�ݹ�ض�temp��ߵĹؼ��ֽ�������
		QuickSort(R, i + 1, high);//�ݹ�ض�temp�ұߵĹؼ��ֽ�������
	}
}
void SelectSort(int R[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n; ++i) {
		k = i;
		/* ���ѭ�����㷨�Ĺؼ���������������������һ����С�Ĺؼ��� */
		for (j = i + 1; j < n; ++j)
			if (R[k] > R[j])
				k = j;
		/* ����3�������С�ؼ������������е�һ���ؼ��ֵĽ��� */
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}
void heapSort(int R[], int n) {
	int i;
	int temp;
	for (i = n / 2; i >= 1; --i)//������ʼ��
		Sift(R, i, n);
	for (i = n; i >= 2; --i) {//����n-1��ѭ������ɶ�����
		/* ����3�任���˸�����еĹؼ��֣������������λ�� */
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i - 1);//�ڼ�����1���ؼ��ֵ����������н��е���
	}
}
void mergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(A, low, mid);//�鲢����ǰ���
		mergeSort(A, mid + 1, high);//�鲢�������
		merge(A, low, mid, high);//��A������low��mid��mid+1��high��Χ�ڵ������������й鲢��һ����������
	}
}