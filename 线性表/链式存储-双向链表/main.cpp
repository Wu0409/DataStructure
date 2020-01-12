//功能：线性表的链式储存（双向链表）
//设计者：Wu Yuanchen
//版本号：2019-1-11

#include <iostream>
#include <cstdarg>
using namespace std;
template <typename T>
typedef struct node{    //定义节点
    T data; //模板定义数据类型
    node *pre;
    node *next; //链域指针
};
template <typename T>
class List{
private:
    int len;    //长度
    node <T> * head;    //头节点
    node <T> * tail;    //尾节点
public:
    List(int count,...){   //初始化线性表，第一个参数为长度
        this->head = NULL;  //头指针初始化
        this->tail = NULL;  //尾指针初始化
        node <T> * p = NULL;    //用于创建链表
        node <T> * temp = NULL; //temp用于创建链表
        len = count;    //赋值长度
        va_list args;       //不定参数实现初始化,cstdarg实现
        count++;    //++一次，0while语句不执行，但是实际上这一次是要执行的
        va_start(args,count);   //不定参数进行初始化，使用cstdarg头文件
        while(count--) {
            if (head == NULL) { //  如果head为空，即为第一次
                p = new node<T>;    //动态开辟内存
                p->data = va_arg(args, T);
                p->pre = NULL;
                p->next = NULL;
                this->head = p; //p赋值给head指针，记录头结点位置
                temp = p;   //记录这次的地址，下次temp->next指向新节点完成链接
                count--;    //次数-1
            }
            else {  //非头结点
                p = new node<T>;    //动态开辟
                p->data = va_arg(args, T);
                p->pre = temp;
                p->next = NULL;
                temp->next = p; //前驱链接向该节点
                temp = p;   //记录这次的地址，下次temp->next指向新节点完成链接
            }
        }
        tail = temp;    //记录尾部节点
        va_end(args);
    }
    bool empty(){   //销毁
        node <T> *p;
        if(head==NULL){
            return 0;
        }
        while(head) //一个个delete
        {
            p=head->next;
            delete head;
            head=p; //将下一个作为头
        }
        len = 0;    //长度设置为0
        return 1;
    }
    void traverse(int argument = 0){    //遍历(参数0（默认的）- 顺序，参数1逆序)
        if(argument == 0) { //顺序
            if (len == NULL) {
                cout << "null" << endl;
            }
            node<T> *p = head;  //p工作指针
            while (p != NULL) {   //直到NULL，即到了最后一个
                cout << p->data << " ";
                p = p->next;    //指向后继
            }
            cout << endl; //换行
        }
        else if(argument == 1){ //逆序
            node<T> *p = tail;  //p工作指针
            while (p != NULL) {   //直到NULL，即到了最后一个
                cout << p->data << " ";
                p = p->pre;    //指向前驱
            }
            cout << endl; //换行
        }
        else{   //参数错误
            cout<<"参数错误："<<argument<<endl;
        }
    }
    int length(){
        return len; //返回长度
    }
    int index(T target){    //获取内容的索引值
        int num = 0;
        node <T> *p = head; //工作指针
        while(p != NULL){   //一个个向下遍历
            if(p->data == target){  //检索到目标
                return num; //返回index值
            }
            p = p->next;
            num++;  //num(index)+1
        }
        return -1;  //未找到
    }
    T get(int index){
        node <T> *p = head; //工作指针
        for(int i = 0;i < index;i++){   //将指针移动到目标index值前一个
            p = p->next;
        }
        return p->data; //返回该元素
    }
    void del(int index){    //删除元素
        node <T> *p = head; //工作指针
        for(int i = 0;i < index-1;i++){ //将指针移动到目标index值前一个
            p = p->next;
        }
        node <T> *temp = p->next->next; //记录被删除的节点的后继
        delete p->next; //释放目标内存
        p->next = temp; //将被删除的节点的后继链接起来
        temp->pre = p;  //将被删除节点的后继的前驱设置为被删除的节点的前驱
        len--;
    }
    void insert(int index,T target){
        node <T> *p = head; //工作指针
        node <T> *temp = new node <T>;  //创建插入元素节点
        node <T> *temp1 = NULL; //定义temp指针，记录未添加前后继节点地址
        temp->data = target;    //赋值
        for(int i = 0;i < index-1;i++){ //移动到需要插入的位置
            p = p->next;
        }
        temp1 = p->next;    //记录未添加前的后继节点地址
        temp1->pre = temp;  //记录原p后继现在的前驱，即插入的元素
        p->next = temp; //将前驱节点与添加节点链接
        temp->next = temp1; //将添加的节点后继赋值为未添加前后继节点地址
        temp->pre = p;  //记录插入元素前驱
        len++;
    }
    T operator [](int index){   //运算符重载方式写get()方法
        node <T> *p = head; //工作指针
        for(int i = 0;i < index;i++){   //移动到目标位置
            p = p->next;
        }
        return p->data; //返回目标元素
    }
};


int main() {
    List <int> test(5,1,2,3,4,5);
    cout<<"顺序遍历： "; test.traverse();
    cout<<"逆序遍历： "; test.traverse(1);   //体现双向链表的优势
    cout<<"长度是："<<test.length()<<endl;
    cout<<"3的index："<<test.index(3)<<endl;
    cout<<"第一种：index=4的值为："<<test.get(4)<<endl;
    //test.get第二种方法-运算符重载
    cout<<"第二种：index=4的值为："<<test[4]<<endl;
    cout<<"删除index=2的元素"<<"删除后遍历:";
    test.del(2);    test.traverse();
    cout<<"在index=3加入元素6"<<"删除后遍历:";
    test.insert(3,6);    test.traverse();
    test.empty();
    test.traverse();
    return 0;
}