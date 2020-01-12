//功能：栈-顺序存储
//设计者：Yuanchen Wu
//版本号：2019-1-12

#include <iostream>
using namespace std;

template <typename T>
class stack{
private:
    T * content;  //堆栈元素
    int top_pointer;    //栈顶指针，指向栈顶
    int size;   //记录大小
public:
    stack(int size){    //初始化空栈，参数size为大小，即初始化堆栈的大小
        content = new T(size);  //动态分配内存
        top_pointer = 0;    //栈顶指针初始化为0
        this->size = size;  //记录栈大小
    }
    bool isempty(){ //判断栈是否为空
        if(top_pointer == 0){   //栈顶指针为0，即栈为空
            return true;
        }
        else{   //栈不为空
            return false;
        }
    }
    bool isfull(){  //判断栈是否为满
        if(top_pointer == size){
            return true;
        }
        else{
            return false;
        }
    }
    void empty(){   //清空栈，这里直接将栈顶设置为0即可，后面的覆盖不产生影响
        top_pointer = 0;    //将栈顶设置为0，即从头开始
    }
    void destroy(){ //销毁栈，清理内存
        delete content; //清空内存
        top_pointer = -1;
        cout<<"已销毁！"<<endl;
    }
    void traverse(){    //遍历栈
        if(top_pointer == 0){   //栈空的情况
            cout<<"null"<<endl;
            return;
        }
        else if(top_pointer == -1){ //栈被销毁的情况
            cout<<"栈已销毁无法遍历"<<endl;
            return;
        }
        for(int i = 0;i <= top_pointer-1;i++){  //从index=0开始遍历，到栈顶
            cout<<content[i]<<" ";
        }
        cout<<endl;
    }
    void push(T target){    //压栈
        if(isfull()){   //如果判断栈为满，不进行压栈操作
            cout<<"栈已满！"<<endl;
        }
        else{   //未满，压栈
            content[top_pointer] = target;  //栈顶指针所在位置（即后面一个空位），赋值target
            top_pointer++;  //栈顶指针向后一个
        }
    }
    T pop(){    //pop出栈，返回栈顶元素
        top_pointer--;  //出栈，栈顶指针向前一个
        return content[top_pointer];
    }
    T top(){    //取栈顶元素，不出栈
        return content[top_pointer-1];  //返回栈顶元素
    }
    int search(T target){
        for(int i = 0;i <= top_pointer-1;i++){  //for循环，到栈顶
            if(content[i] == target){ //判断是否相同
                return i;   //如果相同，返回索引
            }
        }
        return -1;  //未找到的情况
    }
};
int main() {
    cout<<"初始化栈大小为3"<<endl;
    stack <int> test(3);
    cout<<"压栈1，2"<<endl;
    test.push(1);
    test.push(2);
    cout<<"遍历："<<endl;
    test.traverse();
    cout<<"返回栈顶元素：\n"<<test.top()<<endl;
    cout<<"pop两次"<<endl;
    cout<<test.pop()<<test.pop()<<endl;
    cout<<"判断栈是否为空："<<endl;
    cout<<test.isempty()<<endl;
    cout<<"压栈3，4，5，6（栈满）"<<endl;
    test.push(3);   test.push(4);   test.push(5);   test.push(6);//此时栈已满
    cout<<"遍历："<<endl;
    test.traverse();
    cout<<"查找4所在位置："<<endl;
    cout<<test.search(4)<<endl;
    cout<<"清空栈,遍历"<<endl;
    test.empty();   test.traverse();
    test.destroy();
    test.traverse();
    //测试其他类型
    cout<<"其他类型测试："<<endl;
    stack <char> test1(3);
    test1.push('a');    test1.push('b');    test1.push('c');
    test1.traverse();
    return 0;
}