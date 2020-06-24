#include "search.h"

int Search(int a[], int n, int k) {
	int i;
	for (i = 1; i <= n; ++i)
		if (a[i] == k)
			return i;//���ҳɹ�����i
	return 0;//����ʧ�ܷ���0
}
int Bsearch(int R[], int low, int high, int k) {
	int mid;
	while (low <= high) {//���ӱ��ȴ��ڵ���1ʱ����ѭ��
		mid = (low + high) / 2;//ȡ��ǰ����м�λ��
		if (R[mid] == k)//�ҵ��󷵻�Ԫ�ص�λ��
			return mid;
		else if (R[mid] > k)//˵����Ҫ��R[low,...,mid-1]�в���
			high = mid - 1;
		else//˵����Ҫ��R[mid+1,...,high]�в���
			low = mid + 1;
	}
	return 0;//���Ҳ��ɹ��򷵻�0������R[]���±�1��ʼ��
			 //����ʧ�ܷ���0
}
int IndexSearch(indexElem index[], int n, int R[], int k) {
	int low = 0, high = n - 1, mid;
	int i;

	while (low <= high) {
		mid = (low + high) / 2;
		if(index[mid].key >= k)//ע��������=���Ա��۰���������ǲ�ͬ�ģ���Ϊ�˴���ͬ��ʾ�͸���mid�����ң��༴high+1������
			high = mid - 1;
		else
			low = mid + 1;
	}
	i = index[high + 1].low;
	while (i <= index[high + 1].high) {
		if (R[i] == k)
			return i;
		++i;
	}
	return 0;
}
BTNode * BSTSearch(BTNode * bt, int key) {
	if (bt == NULL)
		return NULL;//�����˿�ָ���򣬲��Ҳ��ɹ�����NULL
	else {
		if (bt->key == key)
			return bt;//���ڸ�����еĹؼ��֣����ҳɹ������عؼ������ڵĽ��ָ��
		else if (key < bt->key)//С�ڸ�����еĹؼ���ʱ���������в���
			return BSTSearch(bt->lchild, key);//�����return��Ҫ����
		else//���ڸ�����еĹؼ���ʱ���������в���
			return BSTSearch(bt->rchild, key);
	}
}
int BSTInsert(BTNode * &bt, int key) {//�ٴ�ǿ������Ϊָ��btҪ�ı䣬����Ҫ��������ָ��
	if (bt == NULL) {//��ǰΪ��ָ��ʱ˵���ҵ�����λ�ã������½����в���
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;//������ؼ��ִ����½���ڣ�����ɹ�������1
		return 1;
	}else {//�����㲻�գ�����Ҳ���λ�ã��ⲿ�ֺͲ����㷨����
		if (key == bt->key)//�ؼ����Ѵ��������У�����ʧ�ܣ�����0
			return 0;
		else if (key < bt->key)
			return BSTInsert(bt->lchild, key);
		else
			return BSTInsert(bt->rchild, key);
	}
}
void CreateBST(BTNode * &bt, int key[], int n) {
	int i;
	bt = NULL;//�������
	for (i = 0; i < n; ++i) {//���ò��뺯�����������ؼ���
		BSTInsert(bt, key[i]);
	}
}
int DeleteBST(BTNode * &bt, int key) {
	//������������bt�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��.������1�����򷵻�0
	if (bt == NULL)
		return 0;//�����ڹؼ��ֵ���key������Ԫ��
	else {
		if (key == bt->key)
			return Delete(bt);//�ҵ��ؼ��ֵ���key������Ԫ��
		else if (key < bt->key)
			return DeleteBST(bt->lchild, key);
		else
			return DeleteBST(bt->rchild, key);
	}
}
int InsertAVL(BTNode * &bt, int key, bool &taller) {
	/*����ƽ��Ķ���������bt�в����ڹؼ���key�Ľ�㣬�����һ������Ԫ��Ϊkey��
	�½�㣬������1�����򷵻�0����������ʹ����������ʧȥƽ�⣬����ƽ����ת
	������������taller��Ӧbt�������
	*/
	if (bt == NULL) {//�����½�㣬�������ߡ�����tallerΪtrue
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		bt->bf = EH;
		taller = true;
	}else {
		if (key == bt->key) {//�����Ѵ��ڹؼ���key�Ľ��
			taller = false;
			return 0;//���ٲ���
		}
		if (key < bt->key) {//Ӧ������*bt���������н�������
			if (!InsertAVL(bt->lchild, key, taller)) return 0;//δ����
			if(taller)//�Ѳ��뵽*bt�����������������������ߡ�
				switch (bt->bf){//���*bt��ƽ���
					case LH: {//ԭ�����������������ߣ���Ҫ����ƽ�⴦��
						LeftBalance(bt);
						taller = false;
						break;
					}
					case EH: {//ԭ�����������ȸߣ��������������߶�ʹ������
						bt->bf = LH;
						taller = true;
						break;
					}
					case RH: {//ԭ�����������������ߣ������������ȸ�
						bt->bf = EH;
						taller = false;
						break;
					}
				}
		}else {//Ӧ������*bt���������н�������
			if (!InsertAVL(bt->rchild, key, taller)) return 0;//δ����
			if (taller)//�Ѳ��뵽*bt�����������������������ߡ�
				switch (bt->bf) {//���*bt��ƽ���
					case LH: {//ԭ�����������������ߣ������������ȸ�
						bt->bf = EH;
						taller = false;
						break;
					}
					case EH: {//ԭ�����������ȸߣ��������������߶�ʹ������
						bt->bf = RH;
						taller = true;
						break;
					}
					case RH: {//ԭ�����������������ߣ���Ҫ����ƽ�⴦��
						RightBalance(bt);
						taller = false;
						break;
					}
				}
		}
	}
	return 1;
}
int CreateAVL(BTNode * &bt, int key[], int n, bool &taller) {
	int i;
	bt = NULL;//�������
	for (i = 0; i < n; ++i) {//���ò��뺯�����������ؼ���
		InsertAVL(bt, key[i], taller);
	}
}