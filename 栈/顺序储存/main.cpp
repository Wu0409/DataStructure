#include <iostream>
using namespace std;

template <typename T>
class stack{
private:
    T * content;  //堆栈元素
    int top;    //指向栈顶
    int size;   //记录大小
public:
    stack(int size){
        content = new T(size);
        top = 0;
        this->size = size;
    }
    bool isempty(){
        if(top == 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool isfull(){
        if(top == size){
            return true;
        }
        else{
            return false;
        }
    }
    void empty(){
        top = 0;    //将栈顶设置为0，即从头开始
    }
    void destroy(){
        delete content; //清空内存
        top = -1;
        cout<<"已销毁！"<<endl;
    }
    void traverse(){
        for(int i = 0;i <= top-1;i++){
            cout<<content[i]<<" ";
        }
        cout<<endl;
    }
    void push(T target){
        if(isfull()){
            cout<<"栈已满！"<<endl;
        }
        else{
            content[top] = target;
            top++;
        }
    }
    T pop(){
        top--;
        return content[top];
    }



};
int main() {
    stack <int> test(5);
    test.push(1);
    test.push(2);
    test.traverse();
    cout<<test.pop()<<test.pop()<<endl;
    cout<<test.isempty()<<endl;

    return 0;
}