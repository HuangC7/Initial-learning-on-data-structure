#include "sort.h"

void InsertSort(int R[], int n) {//待排关键字存储在R[]中，默认为整型，个数为n
	int i, j;
	int temp;
	for (i = 1; i < n; ++i) {
		temp = R[i];//将待插入关键字暂存于temp中
		j = i - 1;
		/* 下面这个循环完成了从待排关键字之前的关键字开始扫描，如果大于待排关键字，则后移一位 */
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
		temp = R[i];//将R[i]暂存到temp
		low = 0; high = i - 1;
		while (low <= high) {//在R[low...high]中折半查找有序插入的位置
			m = (low + high) / 2;//折半
			if (temp < R[m]) high = m - 1;//插入点在低半区
			else low = m + 1;//插入点在高半区
		}
		for (j = i - 1; j >= high + 1; --j) R[j + 1] = R[j];//记录后移
		R[high + 1] = temp;//插入
	}
}
void ShellSort(int R[], int n, int dlta[], int t) {
	//按增量序列dlta[0...t-1]对顺序表L做希尔排序
	for (int k = 0; k < t; ++k)
		ShellInsert(R, dlta[k], n);
}
void BubbleSort(int R[], int n) {//默认待排序关键字为整型
	int i, j, flag;
	int temp;
	for (i = n - 1; i >= 1; --i) {
		flag = 0;//变量flag用来标记本趟排序是否发生了交换
		for(j = 1; j <= i; ++j)
			if (R[j - 1] > R[j]) {
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				flag = 1;//如果没发生交换,则flag的值为0;如果发生交换,则flag的值为1
			}
		if (flag == 0)//一趟排序过程中没有发生关键词交换，则证明序列有序，排序结束
			return;
	}
}
void QuickSort(int R[], int low, int high) {//对从R[low]到R[high]的关键字进行排序
	int temp;
	int i = low, j = high;
	if (low < high) {
		temp = R[low];
		/* 下面这个循环完成了一趟排序，即将数组中小于temp的关键字放在左边，大于temp的关键字放在右边 */
		while (i < j) {
			while (j > i && R[j] >= temp) --j;//从右往左扫描，找到一个小于temp的关键字
			if (i < j) {
				R[i] = R[j];//放在temp左边
				++i;//i右移一位
			}
			while (i < j && R[i] < temp) ++i;//从左往右扫描，，找到一个大于temp的关键字
			if (i < j) {
				R[j] = R[i];//放在temp右边
				--j;//j左移一位
			}
		}
		R[i] = temp;//将temp放在最终位置
		QuickSort(R, low, i - 1);//递归地对temp左边的关键字进行排序
		QuickSort(R, i + 1, high);//递归地对temp右边的关键字进行排序
	}
}
void SelectSort(int R[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n; ++i) {
		k = i;
		/* 这个循环是算法的关键，它从无序序列中挑出一个最小的关键字 */
		for (j = i + 1; j < n; ++j)
			if (R[k] > R[j])
				k = j;
		/* 下面3句完成最小关键字与无序序列第一个关键字的交换 */
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}
void heapSort(int R[], int n) {
	int i;
	int temp;
	for (i = n / 2; i >= 1; --i)//建立初始堆
		Sift(R, i, n);
	for (i = n; i >= 2; --i) {//进行n-1次循环，完成堆排序
		/* 以下3句换出了根结点中的关键字，将其放入最终位置 */
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i - 1);//在减少了1个关键字的无序序列中进行调整
	}
}
void mergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(A, low, mid);//归并排序前半段
		mergeSort(A, mid + 1, high);//归并排序后半段
		merge(A, low, mid, high);//把A数组中low到mid和mid+1到high范围内的两段有序序列归并成一段有序序列
	}
}