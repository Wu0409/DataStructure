//功能：次优查找树
//设计者：Yuanchen Wu
//版本号：2019.1.21

//备注：选出一个结点，使得它左右两侧的子数组的权值累加和之差的绝对值最小。
// 把这个结点当做根节点，递归地用刚才的左右字数组构造它的左右子树。

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct treenode{
    int weight;
    treenode *l_child;
    treenode *r_child;
};
class SOStree{
private:
    treenode *root; //该次优查找树的根节点
    int find_root(int *weight_list,int start,int end){  //用于找到选哪个权值作为当前根节点
        vector <int> difference;    //创建记录 左边的权值之和与右边权值之和的差值 的容器
        for(int i = start;i <= end;i++){    //计算i左边的权值之和与右边权值之和的差值
            int left = 0;   //设左指针
            int right = 0;  //设右指针
            for(int j = start;j < i;j++){   //左边的权值之和
                left += weight_list[j]; //累加
            }
            for(int j = i + 1;j <= end;j++){   //右边的权值之和
                right += weight_list[j];    //累加
            }
            difference.push_back(abs(left - right));
        }
        /*  检查 i左边的权值之和与右边权值之和的差值 是否有误
        for(int n = 0; n <difference.size();n++){
            cout<<difference[n]<<" ";
        }
        cout<<endl;
         */
        int temp = difference[0];   //记录当前权值最小的大小
        int index = 0;  //记录当前权值最小对应的索引
        for(int n = 0; n <difference.size();n++){   //返回差值最小对应的的索引值
            if(temp >= difference[n]){  //找到比当前最小的还要小的差
                temp = difference[n];   //temp更新为当前的差值
                index = n;  //更新为当前索引
            }
        }
        return index;   //返回最小的索引
    }
public:
    treenode * create(int *weight_list, int start, int end){    //递归创建次优查找树
        if(start == end){   //如果左 == 右，即递归到只剩下一个
            treenode *root = new treenode;  //动态开辟节点
            root->weight = weight_list[start];  //节点的权
            root->l_child = NULL;   //没有左孩子
            root->r_child = NULL;   //没有右孩子
            return root;
        }
        treenode *root = new treenode;
        int pivotal = find_root(weight_list,start,end); //找到根节点的权值索引
        root->weight = weight_list[pivotal];    //当前节点的权
        //被index = pivotal 拆分成左右两边
        root->l_child = create(weight_list,start,pivotal - 1);  //递归左半部分的树
        root->r_child = create(weight_list,pivotal + 1,end);    //递归右半部分的树
        return root;    //返回
    }

    void traverse(treenode *root){  //中序遍历
        if(root == NULL){   //root==NULL，即到尾，直接返回
            return;
        }
        cout<<root->weight<<" ";    //输出该节点权值
        traverse(root->l_child);    //递归遍历左子树
        traverse(root->r_child);    //递归遍历右子树
    }

    SOStree(int *weight_list,int num){  //构造函数，初始化次优二叉树
        root = create(weight_list,0,4); //递归构造次优二叉树
        traverse(root); //中序遍历次优二叉树
    }
};

int main() {
    int weight_list[] = {3,1,2,5,4};
    SOStree tree(weight_list,5);
    return 0;
}