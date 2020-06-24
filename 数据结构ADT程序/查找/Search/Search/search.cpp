#include "search.h"

int Search(int a[], int n, int k) {
	int i;
	for (i = 1; i <= n; ++i)
		if (a[i] == k)
			return i;//查找成功返回i
	return 0;//查找失败返回0
}
int Bsearch(int R[], int low, int high, int k) {
	int mid;
	while (low <= high) {//当子表长度大于等于1时进行循环
		mid = (low + high) / 2;//取当前表的中间位置
		if (R[mid] == k)//找到后返回元素的位置
			return mid;
		else if (R[mid] > k)//说明需要在R[low,...,mid-1]中查找
			high = mid - 1;
		else//说明需要在R[mid+1,...,high]中查找
			low = mid + 1;
	}
	return 0;//查找不成功则返回0，数组R[]从下标1开始存
			 //查找失败返回0
}
int IndexSearch(indexElem index[], int n, int R[], int k) {
	int low = 0, high = n - 1, mid;
	int i;

	while (low <= high) {
		mid = (low + high) / 2;
		if(index[mid].key >= k)//注意这里是=，对比折半插入排序是不同的，因为此处相同表示就该在mid处查找，亦即high+1处查找
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
		return NULL;//来到了空指针域，查找不成功返回NULL
	else {
		if (bt->key == key)
			return bt;//等于根结点中的关键字，查找成功，返回关键字所在的结点指针
		else if (key < bt->key)//小于根结点中的关键字时到左子树中查找
			return BSTSearch(bt->lchild, key);//这里的return不要丢了
		else//大于根结点中的关键字时到右子树中查找
			return BSTSearch(bt->rchild, key);
	}
}
int BSTInsert(BTNode * &bt, int key) {//再次强调，因为指针bt要改变，所以要用引用型指针
	if (bt == NULL) {//当前为空指针时说明找到插入位置，创建新结点进行插入
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;//将待插关键字存入新结点内，插入成功，返回1
		return 1;
	}else {//如果结点不空，则查找插入位置，这部分和查找算法类似
		if (key == bt->key)//关键字已存在于树中，插入失败，返回0
			return 0;
		else if (key < bt->key)
			return BSTInsert(bt->lchild, key);
		else
			return BSTInsert(bt->rchild, key);
	}
}
void CreateBST(BTNode * &bt, int key[], int n) {
	int i;
	bt = NULL;//将树清空
	for (i = 0; i < n; ++i) {//调用插入函数。逐个插入关键字
		BSTInsert(bt, key[i]);
	}
}
int DeleteBST(BTNode * &bt, int key) {
	//若二叉排序树bt中存在关键字等于key的数据元素时，则删除该数据元素结点.并返回1，否则返回0
	if (bt == NULL)
		return 0;//不存在关键字等于key的数据元素
	else {
		if (key == bt->key)
			return Delete(bt);//找到关键字等于key的数据元素
		else if (key < bt->key)
			return DeleteBST(bt->lchild, key);
		else
			return DeleteBST(bt->rchild, key);
	}
}
int InsertAVL(BTNode * &bt, int key, bool &taller) {
	/*若在平衡的二叉排序树bt中不存在关键字key的结点，则插入一个数据元素为key的
	新结点，并返回1，否则返回0。若因插入而使二叉排序树失去平衡，则作平衡旋转
	处理，布尔变量taller反应bt长高与否
	*/
	if (bt == NULL) {//插入新结点，树“长高”，置taller为true
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		bt->bf = EH;
		taller = true;
	}else {
		if (key == bt->key) {//树中已存在关键字key的结点
			taller = false;
			return 0;//则不再插入
		}
		if (key < bt->key) {//应继续在*bt的左子树中进行搜索
			if (!InsertAVL(bt->lchild, key, taller)) return 0;//未插入
			if(taller)//已插入到*bt的左子树中且左子树“长高”
				switch (bt->bf){//检查*bt的平衡度
					case LH: {//原本左子树比右子树高，需要作左平衡处理
						LeftBalance(bt);
						taller = false;
						break;
					}
					case EH: {//原本左、右子树等高，现因左子树增高而使树增高
						bt->bf = LH;
						taller = true;
						break;
					}
					case RH: {//原本右子树比左子树高，现左、右子树等高
						bt->bf = EH;
						taller = false;
						break;
					}
				}
		}else {//应继续在*bt的右子树中进行搜索
			if (!InsertAVL(bt->rchild, key, taller)) return 0;//未插入
			if (taller)//已插入到*bt的右子树中且右子树“长高”
				switch (bt->bf) {//检查*bt的平衡度
					case LH: {//原本左子树比右子树高，现左、右子树等高
						bt->bf = EH;
						taller = false;
						break;
					}
					case EH: {//原本左、右子树等高，现因右子树增高而使树增高
						bt->bf = RH;
						taller = true;
						break;
					}
					case RH: {//原本右子树比左子树高，需要作右平衡处理
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
	bt = NULL;//将树清空
	for (i = 0; i < n; ++i) {//调用插入函数。逐个插入关键字
		InsertAVL(bt, key[i], taller);
	}
}