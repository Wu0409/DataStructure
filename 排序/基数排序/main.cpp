//功能：排序 - 基数排序
//设计者：Yuanchen Wu
//版本号：2019.1.20
//备注：使用了vector记录1-9的链表头

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef struct node{    //定义链表节点
    int data;   //存放数据
    node* next; //记录下一个节点地址
};
int get(int target,int digit){  //digit - 1，10，100
    return (target % (digit*10)) / digit;   //获取所需位置的值（个位，十分位，百分位...）
}
void sort(int *a,int num,int digit){
    for(int i = 1;i <= digit;i++){  //个位起
        vector <node *> list;   //创建存放node*记录1-9的链表头的容器
        vector <node *> list_pre;   //创建存放node*记录1-9的前驱的容器
        for(int k = 0;k <= 9;k++){  //初始化列表，元素为1-9的头结点
            node *p = NULL; //设置空指针
            list.push_back(p);  //放入list
            list_pre.push_back(p);  //放入list_pre
        }
        int bit = pow(10,i-1);  //得到当前所需的位数（1，10，100...）
        /*  测试每一次排序使用
         cout<<"位数："<<bit<<endl;
         */
        for(int j = 0; j < num;j++){
            int temp = get(a[j],bit);   //记录当前元素第i位（从右到左）
            node *p = new node; //创建临时工工作指针
            p->data = a[j];    p->next = NULL;  //初始化工作指针
            if(list[temp-1] == NULL){   //如果对应数字的头结点为空
                list[temp-1] = p;   //即此时的p即为链表头
                list_pre[temp-1] = p;   //将下一个前驱设置为当前节点
            }
            else{   //如果对应数字的头结点不为空
                list_pre[temp-1]->next = p; //将前驱的next指向当前节点
                list_pre[temp-1] = p;   //将下一个前驱设置为当前节点
            }
        }
        int count = 0;  //a的计数器
        for(int n = 0;n <= 9;n++){  //重新覆盖a
            if(list[n] != NULL){    //如果当前头结点不为空，即有数字放在了该节点
                node *p = list[n];  //创建工作指针
                while(p != NULL){   //输出该节点的链表
                    a[count] = p->data; //将a覆盖（进行一次排序）
                    /*  测试每一次排序使用
                    cout<<p->data<<" ";
                     */
                    count++;    //计数器++，到下一位
                    p = p->next;    //指针指向下一个节点
                }
                /*  测试每一次排序使用
                cout<<endl;
                 */
            }
        }
    }
}

int main() {
    int a[] = {369,367,167,239,237,138,230,139};
    sort(a,8,3);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}