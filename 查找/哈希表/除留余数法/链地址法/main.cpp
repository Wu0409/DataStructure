//功能：查找 - 哈希表 - 除留余数法 - 链地址法
//设计者：Yuanchen Wu
//版本号：2019.1.22

//备注：简单例子,没有自定义取几的余，该例子里是 mod5

#include <iostream>
#include <cstdarg>
#include <cmath>
#include <vector>

using namespace std;
typedef struct node{    //定义节点
    int data;   //存放元素
    node *next; //指向下一个节点的指针域
    node(int a){    //构造函数
        data = a;   //data赋值为传入的参数a
        next = NULL;    //next默认设置为空指针
    }
};
class Hashmap{  //H()key = key mod p,此时p取5
private:
    vector <node *> list;   //记录节点头的容器
    vector <node *> list_pre;   //记录前驱节点的容器
public:
    Hashmap(int count,...){   //初始化表，第一个参数为长度
        for(int i = 0;i < count;i++){   //初始化容器
            node *p = new node(-1); //默认元素值设置为-1
            list.push_back(p);  //把p放入容器list，相当于"占位"
            list_pre.push_back(p);  //把p放入容器list_pre，相当于"占位"
        }
        va_list args;   //不定参数实现初始化,cstdarg库实现
        va_start(args,count);
        while(count--){
            int target = va_arg(args,int);  //通过迭代器获取当前元素
            int index = target % 5; //得到理论上不冲突存在的位置
            if(list[index]->data == -1){    //如果记录头节点的容器头结点的元素值为-1，即此时target是第一个放在该索引上的元素
                node *p = new node(target); //创建临时工作节点
                list[index] = p;    //将p赋值给list[index]作为该索引值的链表头
                list_pre[index] = p;    //记录把当前节点作为下一个的前驱，为了后续链表
            }
            else{   //target不是第一个放在该索引上的元素
                node *p = new node(target); //创建临时工作节点
                list_pre[index]->next = p;  //把前驱的后继指向当前节点
                list_pre[index] = p;    //当前节点作为下一个节点的后继
            }
        }
        va_end(args);
    }
    int search(int target){ //查找
        int index = target % 5; //得到理论上不冲突存在的位置
        node *p = list[index];  //创建工作指针
        while(p != NULL){   //遍历至链表尾
            if(p->data == target){  //如果找到目标元素
                return index;   //返回索引值
            }
            p = p->next;    //到下一个节点
        }
        return -1;  //遍历完依旧未找到
    }
};
int main() {
    Hashmap test(7,12,39,18,24,33,21,26);
    cout<<"26在哈希表中的位置："<<test.search(26)<<endl;
    cout<<"21在哈希表中的位置："<<test.search(21)<<endl;
    cout<<"12在哈希表中的位置："<<test.search(12)<<endl;
    cout<<"18在哈希表中的位置："<<test.search(18)<<endl;
    cout<<"39在哈希表中的位置："<<test.search(39)<<endl;
    cout<<"24在哈希表中的位置："<<test.search(24)<<endl;
    cout<<"33在哈希表中的位置："<<test.search(33)<<endl;
    return 0;
}