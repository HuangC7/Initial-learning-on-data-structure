#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void ShellInsert(int R[], int dk, int n) {//一趟希尔排序
	int i, j;
	int temp;
	for (i = dk; i < n; ++i) {
		if (R[i] < R[i - dk]){//需将R[i]插入有序增量子表
			temp = R[i];//暂存在temp
			for (j = i - dk; j >= 0 && temp < R[j]; j -= dk)
				R[j + dk] = R[j];//记录后移，查找插入位置
			R[j + dk] = temp;
		}
	}
}
/* 本函数完成在数组R[low]到R[high]的范围内对在位置low上的结点进行调整 */
void Sift(int R[], int low, int high) {//这里关键字的存储设定为从数组下标1开始
	int i = low, j = 2 * i;//R[j]是R[i]的左孩子结点
	int temp = R[i];
	while (j <= high){
		if (j < high && R[j] < R[j + 1])//若右孩子较大，则把j指向右孩子
			++j;//j变为2*i+1
		if (temp < R[j]) {
			R[i] = R[j];//将R[j]调整到双亲结点的位置上
			i = j;//修改i和j的值，以便继续向下调整
			j = 2 * i;
		}else
			break;
	}//调整结束
	R[i] = temp;//被调整结点的值放入最终位置
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

/* 插入类排序 */
void InsertSort(int R[], int n);//直接插入排序算法
void BInsertSort(int R[], int n);//折半插入排序
void ShellSort(int R[], int n, int dlta[], int t);//希尔排序
/* 交换类排序 */
void BubbleSort(int R[], int n);//起泡排序算法
void QuickSort(int R[], int low, int high);//快速排序算法
/* 选择类排序 */
void SelectSort(int R[], int n);//简单选择排序算法
void heapSort(int R[], int n);//堆排序
/* 其他排序 */
void mergeSort(int A[], int low, int high);//二路归并排序
void RadixSort(int A[], int n);//基数排序
