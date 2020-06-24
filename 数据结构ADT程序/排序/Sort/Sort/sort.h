#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void ShellInsert(int R[], int dk, int n) {//һ��ϣ������
	int i, j;
	int temp;
	for (i = dk; i < n; ++i) {
		if (R[i] < R[i - dk]){//�轫R[i]�������������ӱ�
			temp = R[i];//�ݴ���temp
			for (j = i - dk; j >= 0 && temp < R[j]; j -= dk)
				R[j + dk] = R[j];//��¼���ƣ����Ҳ���λ��
			R[j + dk] = temp;
		}
	}
}
/* ���������������R[low]��R[high]�ķ�Χ�ڶ���λ��low�ϵĽ����е��� */
void Sift(int R[], int low, int high) {//����ؼ��ֵĴ洢�趨Ϊ�������±�1��ʼ
	int i = low, j = 2 * i;//R[j]��R[i]�����ӽ��
	int temp = R[i];
	while (j <= high){
		if (j < high && R[j] < R[j + 1])//���Һ��ӽϴ����jָ���Һ���
			++j;//j��Ϊ2*i+1
		if (temp < R[j]) {
			R[i] = R[j];//��R[j]������˫�׽���λ����
			i = j;//�޸�i��j��ֵ���Ա�������µ���
			j = 2 * i;
		}else
			break;
	}//��������
	R[i] = temp;//����������ֵ��������λ��
}
void merge(int A[], int low, int mid, int high) {
	int i, j;
	int s = low, e = high;
	int B[maxSize];
	for (i = mid + 1, j = low; low <= mid && i <= high; ++j) {
		if (A[low] < A[i]) A[j] = A[low++];
		else A[j] = A[i++];
	}
	if (low <= mid) 
		for(int l = 0; l <= mid - low; ++l)
			A[j] = A[low];
	if (i <= high) 
		for(int l = 0; l <= high - i; ++l)
			A[j] = A[i];
	for(int k = s; k <= e; ++k)
       		 A[k] = B[k];
}

/* ���������� */
void InsertSort(int R[], int n);//ֱ�Ӳ��������㷨
void BInsertSort(int R[], int n);//�۰��������
void ShellSort(int R[], int n, int dlta[], int t);//ϣ������
/* ���������� */
void BubbleSort(int R[], int n);//���������㷨
void QuickSort(int R[], int low, int high);//���������㷨
/* ѡ�������� */
void SelectSort(int R[], int n);//��ѡ�������㷨
void heapSort(int R[], int n);//������
/* �������� */
void mergeSort(int A[], int low, int high);//��·�鲢����
void RadixSort(int A[], int n);//��������
