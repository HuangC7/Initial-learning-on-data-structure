#include <cstdio>
#include <vector>
using namespace std;
struct node{
    int data;                 //数据域
    node *left, *right;       //指针域
};

void insert(node* &root, int data){
    if(root == NULL){       //到达空结点时，即为需要插入的位置
        root = new node;
        root->data = data;
        root->left = root->right = NULL;    //此句不能漏
        return;
    }
    if(data < root->data) insert(root->left, data);     //插在左子树
    else insert(root->right, data);     //插在右子树
}

void preOrder(node* root, vector<int>&vi){      //先序遍历，结果存在vi
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

//镜像树先序遍历，结果存放于vi
void preOrderMirror(node* root, vector<int>&vi){
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int>&vi){     //后序遍历，结果存放于vi
    if(root == NULL) return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

//镜像树后序遍历，结果存放于vi
void postOrderMirror(node* root, vector<int>&vi){
    if(root == NULL) return;
    postOrder(root->right, vi);
    postOrder(root->left, vi);
    vi.push_back(root->data);
}

//origin存放初始序列
//pre、post为先序、后序，preM、postM为镜像树先序、后序
vector<int> origin, pre, post, preM, postM;
int main()
{
    int n, data;
    node* root = NULL;      //定义头结点
    scanf("%d", &n);        //输入结点个数
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        origin.push_back(data);     //将数据加入origin
        insert(root, data);         //将data插入二叉树
    }
    preOrder(root, pre);         //求先序
    preOrderMirror(root, preM);  //求镜像树先序
    postOrder(root, post);       //求后序
    postOrderMirror(root, postM);//求镜像树后序
    if(origin == pre){          //初始序列等于先序序列
        printf("YES\n");
        for(int i = 0; i < post.size(); i++){
            printf("%d", post[i]);
            if(i < post.size() - 1) printf(" ");
        }
    }else if(origin == preM){   //初始序列等于镜像树先序序列
        printf("YES\n");
        for(int i = 0; i < postM.size(); i++){
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    }else{
        printf("NO\n");     //否则输出NO
    }

    return 0;
}
