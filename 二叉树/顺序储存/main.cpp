//功能：二叉树 - 顺序储存实现
//设计者：Yuanchen Wu
//版本：2019.1.16

#include <iostream>
#include<math.h>
using namespace std;

class binarytree{   //二叉树类
private:
    char content[100];  //创建char型数列
    int depth;
    void inorder(int index){    //中根序遍历
        if(index >= pow(2,depth)+1){    //索引超过该满二叉树所能达到的最大索引
            return; //返回
        }
        if(content[index] == '#'){  //遍历到'#'
            return; //返回
        }
        else{
            inorder(index*2+1); //左孩子
            cout<<content[index];   //输出元素
            inorder(index*2+2); //右孩子
        }
    }
    void preorder(int index){   //先根序遍历
        if(index >= pow(2,depth)+1){    //索引超过该满二叉树所能达到的最大索引
            return; //返回
        }
        if(content[index] == '#'){  //遍历到'#'
            return; //返回
        }
        else{
            cout<<content[index];   //输出元素
            preorder(index*2+1); //左孩子
            preorder(index*2+2); //右孩子
        }
    }
    void postorder(int index){   //先根序遍历
        if(index >= pow(2,depth)+1){    //索引超过该满二叉树所能达到的最大索引
            return; //返回
        }
        if(content[index] == '#'){  //遍历到'#'
            return; //返回
        }
        else{
            postorder(index*2+1); //左孩子
            postorder(index*2+2); //右孩子
            cout<<content[index];   //输出元素
        }
    }
public:
    binarytree(string input){   //创建二叉树，input参数为按层序遍历的内容,满二叉树的形式
        depth = log(input.length()) / log(2) + 1;   //计算树的深度
        for(int i = 0;i < input.length();i++){  //for循环遍历
            content[i] = input[i];  //将索引值所对应的内容放入数列，index起始值为0
        }
    }
    void display_pre(){ //先根序遍历
        preorder(0);    //递归调用preorder(）
        cout<<endl; //换行
    }
    void display_in(){ //中根序遍历
        inorder(0); //递归调用inorder(）
        cout<<endl; //换行
    }
    void display_post(){ //后根序遍历
        postorder(0);   //递归调用postorder(）
        cout<<endl; //换行
    }
    void sequent_traverse(){    //层序遍历
        for(int i = 0;i <= pow(2,depth)+1;i++){
            if((content[i] >= '0' && content[i] <= '9')||(content[i] >= 'a' && content[i] <= 'z')||
               (content[i] >= 'A' && content[i] <= 'Z')){   //符合输出内容的进行输出
                cout<<content[i];   //输出内容
            }
        }
        cout<<endl; //换行
    }
    int maxdepth(){
        return depth;   //返回深度
    }
};
int main() {
    cout<<"测试二叉树：\"ABD#C##\""<<endl;
    binarytree tree("ABD#C##"); //参数为满二叉树的形式
    tree.display_pre(); //先根序遍历
    tree.display_in();  //中根序遍历
    tree.display_post();    //后根序遍历
    tree.sequent_traverse();    //层序遍历
    cout<<"二叉树的深度："<<tree.maxdepth()<<endl; //二叉树的深度
    return 0;
}