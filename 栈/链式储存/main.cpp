//功能：栈-链式储存
//设计者：Yuanchen Wu
//版本号：2019.1.12

#include <iostream>
using namespace std;

template <typename T>
typedef struct node{    //储存元素内容的节点
    T content;  //记录元素内容，类型T
    node * next;    //指向下一个元素地址
};
template <typename T>
class stack{
private:
    node <T> * head;  //堆栈元素
    node <T> * temp = NULL;
public:
    stack(){    //初始化空栈
        head = NULL;    //初始化头结点
    }
    void push(T target){    //压栈
        node <T> * p = NULL;
        if(head == NULL){
            p = new node <T>;
            p->content = target;
            p->next = NULL;
            //创建节点
            head = p;
            temp = p;
        }
        else{
            p = new node <T>;
            p->content = target;
            p->next = NULL;
            //创建节点
            head = p;
            p->next = temp;
            temp = p;
        }
    }
    T pop(){    //pop出栈，返回栈顶元素
        T temp1 = head->content;  //记录栈顶元素
        node <T> *temp2 = head->next;    //记录新栈顶
        delete head;    //清空原头结点节点内存
        head = temp2;   //移动至新栈顶
        return temp1;   //返回原栈顶内容
    }
    T top(){    //取栈顶元素，不出栈
        return head->content;   //返回栈顶元素
    }
    void traverse(){    //从栈顶开始遍历
        if(this->isempty()){    //判断是否为空
            cout<<"null"<<endl; //如果为空，显示NULL
        }
        node <T> * p = head;
        while(p != NULL){   //循环遍历，直到p == NULL，即到尾
            cout<<p->content<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    int search(T target){
        node <T> * p = head;    //工作指针
        int index = 0;
        while(p != NULL){   //循环遍历
            if(target == p->content){   //如果和target内容一致，返回索引
                return index;
            }
            p = p->next;    //不一致，移动至下一个元素
            index++;    //索引值++
        }
        return -1;  //未找到改元素
    }
    bool isempty(){ //判断栈是否为空
        if(head == NULL){   //头为空，即栈为空
            return true;
        }
        else{
            return false;   //不为空
        }
    }
    void empty(){   //清空栈
        node <T>* p = head; //工作指针
        node <T>* temp1 = NULL; //用于记录下一个节点
        while(p != NULL){
            temp1 = p->next;    //记录下一节点
            delete p;   //清空当前p的内容
            p = temp1;
        }
        cout<<"栈已清空！"<<endl;
        head = NULL;    //清空栈，头指针不指向任何地址
    }
};

int main() {
    stack <int> test;   //初始化
    cout<<"压栈1，2，3"<<endl;
    test.push(1);
    test.push(2);
    test.push(3);
    test.traverse();
    cout<<"pop出栈后："<<endl;
    test.pop();
    test.traverse();
    cout<<"栈顶：\n"<<test.top()<<endl;
    cout<<test.search(2)<<endl;
    test.empty();
    cout<<test.isempty()<<endl;
    test.traverse();
    return 0;
}