//功能：二叉树 - 二叉链表实现
//设计者：Yuanchen Wu
//版本号：2019.1.16

#include<iostream>
#include <queue>
using namespace std;
typedef struct treenode{    //数的节点
    char data;
    treenode *l_child = NULL;    //指向左孩子
    treenode *r_child = NULL;    //指向右孩子
};
class binarytree{
private:
    treenode * root;    //树的根节点
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
    void preorder(treenode* root){   //前序遍历
        if(root != NULL)    //如果节点不为空
        {
            cout<<root->data;   //输出内容
            preorder(root->l_child);    //从左孩子向下递归遍历
            preorder(root->r_child);    //从右孩子向下递归遍历
        }
    }
    void inorder(treenode* root){    //中序遍历
        if(root != NULL)    //如果节点不为空
        {
            inorder(root->l_child); //从左孩子向下递归遍历
            cout<<root->data;   //输出内容
            inorder(root->r_child); //从右孩子向下递归遍历
        }
    }
    void postorder(treenode* root){  //后续遍历
        if(root != NULL)    //如果节点不为空
        {
            postorder(root->l_child);   //从左孩子向下递归遍历
            postorder(root->r_child);   //从右孩子向下递归遍历
            cout<<root->data;   //输出内容
        }
    }
    int maxDepth(treenode* root) {  //求最大深度
        if(root == NULL) {
            return 0;
        }
        return max(maxDepth(root->l_child), maxDepth(root->r_child)) + 1;  //每次递归调用取左右子树最大深度+1
    }
/*    如果一个树只有一个节点，它的深度为1；
      如果根节点只有左子树而没有右子树，那么树的深度应该是其左子树的深度+1；
      如果根节点只有右子树而没有左子树，那么树的深度应该是其右子树的深度+1；
      如果根节点既有左子树又有右子树，那么
      树的深度应该是左右字数深度的较大值+1.
*/
    void copy(treenode *root,treenode * &new_copy){  //深复制
        if(root == NULL){   //遍历为空
            new_copy = NULL;    //复制也为空
            return; //返回
        }
        else{   //不为空
            new_copy = new treenode;  //动态开辟
            new_copy->data = root->data;    //复制的内容
            copy(root->l_child,new_copy->l_child);  //向下复制左孩子
            copy(root->r_child,new_copy->r_child);  //向下复制右孩子
        }
    }
public:
    binarytree(string input){   //树的初始化
        create_tree(root,input);    //递归调用create_tree()实现
    }
    binarytree(const binarytree &other){    //拷贝构造函数
        copy(other.root,root);
    }
    void display_pre(){ //前序遍历
        treenode * p = root;    //工作指针
        preorder(p); //递归调用preorder()实现
        cout<<endl; //换行
    }
    void display_in(){  //中序遍历
        treenode * p = root;    //工作指针
        inorder(p); //递归调用inorder()实现
        cout<<endl; //换行
    }
    void display_post(){    //后序遍历
        treenode * p = root;    //工作指针
        postorder(p); //递归调用preorder()实现
        cout<<endl; //换行
    }
    void sequence_traverse(){   //层序遍历,使用队列
        treenode * p = root;    //工作指针
        queue <treenode *> queue;   //创建空队列，用于层序输出
        queue.push(p);  //将树的根节点入队
        while(!queue.empty()){
            if(queue.front() == NULL){  //若为空地址，即该节点是空节点，也没有左孩子与有孩子
                cout<<"";
            }
            else {  //具有内容的节点
                cout << queue.front()->data;    //输出队头的内容
                queue.push(queue.front()->l_child); //将队头节点的左孩子入队
                queue.push(queue.front()->r_child); //将队头节点的右孩子入队
            }
            queue.pop();    //将队头pop
        }
        cout<<endl; //换行
    }
    int depth(){
        return maxDepth(root);  //递归调用maxDepth()实现
    }
};

int main(){
    cout<<"测试二叉树：AB#C##D##"<<endl;
    binarytree tree("AB#C##D##");
    cout<<"前序遍历："<<endl;    tree.display_pre();
    cout<<"中序遍历："<<endl;    tree.display_in();
    cout<<"后序遍历："<<endl;    tree.display_post();
    cout<<"深度："<<tree.depth()<<endl;
    cout<<"层序遍历："<<endl;    tree.sequence_traverse();
    return 0;
}
