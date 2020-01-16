//功能：二叉树 - 线索二叉树
//设计者：Yuanchen Wu
//版本号：2019.1.16
//备注：以中序遍历实现线索二叉树
//参考：https://blog.csdn.net/g15827636417/article/details/52967949

#include<iostream>
#include <queue>
using namespace std;
typedef struct treenode{    //数的节点
    char data;
    int ltag;    //孩子-0，线索-1
    int rtag;    //孩子-0，线索-1
    treenode *l_child = NULL;    //指向左孩子
    treenode *r_child = NULL;    //指向右孩子
};
class binarytree{
private:
    void create_tree(treenode* &root,string a){ //递归调用该函数创建树
        char ch;    //count计数器所在的字符
        static int i=0; //设置静态的计数器，实现在递归调用时对于字符串的向后遍历
        ch=a[i++];  //取count计数器所在的字符
        if(i > (a.length()-1)){ //读取到尾
            cout<<"创建完毕！"<<endl;    //创建完毕
            return; //返回
        }
        if(ch == '#') //读取到#，说明该位置是空
        {
            root  = NULL;   //取NULL
            return; //返回
        }
        else    //读取到内容
        {
            root = new treenode;    //动态开辟新的内存
            root->data = ch;  //初始化该节点内容
            create_tree(root->l_child,a);   //递归调用向下创建左孩子
            create_tree(root->r_child,a);   //递归调用向下创建右孩子
        }
    }
    treenode * pre = NULL;  //定义一个数据成员指向线索二叉树的前驱节点，用于将二叉树线索化
    void add_clue(treenode* &root){ //通过中序遍历将二叉树线索化
        if(root == NULL){
            return;
        }
        add_clue(root->l_child);    //左
        if(root->l_child == NULL){  //左孩子为空，记录前驱
            root->ltag = 1;  //标签设置为1
            root->l_child = pre;    //此时，左孩子记录前驱结点
        }
        else{
            root->ltag = 0;  //标签设置为0
        }

        if(pre != NULL && root->r_child == NULL){  //右孩子为空，记录后继
            pre->rtag = 1;   //标签设置为1
            pre->r_child = root;    //此时，右孩子记录后继结点
        }
        else{
            root->rtag = 0;  //标签设置为0
        }
        pre = root; //将前驱设置root
        add_clue(root->r_child);    //右
    }
    treenode *findpre(treenode* p){  //在中序二叉树上寻找任意节点的前驱节点
        treenode* pre;  //记录前驱结点
        pre = p->l_child;   //左标签为1，左指针所指向的节点便是它的前驱节点
        if(p->ltag != 1){   //左标签不为1（0），即是记录了元素
            //前驱节点是以该节点的左孩子为根节点的子树的最右节点
            //沿着其左子树的右指针链向下查找，当某节点的右标志域为1时，它就是所要找的前驱节点
            while(pre->rtag == 0){
                pre = pre->r_child;
            }
        }
        return pre;
    }
    treenode *findpost(treenode* p){  //在中序二叉树上寻找任意节点的后继节点
        treenode* post; //记录后继结点
        post = p->r_child ; //右标签为1，右指针所指向的节点便是它的后继节点
        if(p->rtag != 1){   //右标签不为1（0），即是记录了元素
            //后继节点是以该节点的右孩子为根节点的子树的最左节点
            //沿着其右子树的左指针链向下查找，当某节点的左标志域为1时，它就是所要找的后继节点
            while(post->rtag == 0){
                post = post->l_child ;
            }
        }
        return post;
    }
    void inorder(treenode* head){
        treenode* p;
        p = head->l_child;
        while(p->ltag != 1){    //左标签为0，找到第一个元素
            p = p->l_child; //下一个元素
        }
        while(p != NULL && p != head){
            cout<<p->data;  //输出第一个元素内容
            p = findpost(p);
        }
    }
public:
    treenode * root;    //树的根节点
    binarytree(string a){
        create_tree(root,a);
        add_clue(root);
    }
    void display_in(){
        treenode* p = root;
        inorder(p);
    }
};

int main(){
    cout<<"测试二叉树：AB#C##D##"<<endl;
    binarytree tree("AB#C##D##");
    cout<<tree.root->rtag;
    //tree.display_in();
    return 0;
}
