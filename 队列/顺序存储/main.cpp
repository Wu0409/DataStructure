//功能：队列-顺序储存
//设计者：Yuanchen Wu
//版本号：2019.1.12

#include <iostream>
using namespace std;
template <typename T>
class queue{
private:
    T * content;    //储存内容
    const int HEAD; //常量，表示头
    int rear;   //尾指针
    int size;   //记录该队列大小
public:
    queue(int size):HEAD(0){    //初始化队列
        this->rear = 0;  //队头
        this->size = size;  //记录队列大小
        content = new T(size);  //动态分配内存
    }
    bool isempty(){
        return HEAD == rear;    //如果头==尾，即队列为空
    }
    bool isfull(){
        return rear == size;    //如果尾和大小一致，即对列为满
    }
    void push_back(T target){   //入队
        if(isfull()){   //判断队列是否为满
            cout<<"队列已满！"<<endl;
        }
        else {
            content[rear] = target; //入队
            rear++; //队尾指针++
        }
    }
     T pop(){ //出队
        T target = content[HEAD];
        for(int i = 0;i < rear;i++){
            //每个向前移动，避免产生空移除
            content[i] = content[i+1];
        }
        rear--; //出队，队尾指针--
        return target;  //返回pop出的元素
    }
    void tarverse() const{  //遍历
        if(rear == 0){  //如果判断为空
            cout<<"null"<<endl;
            return;
        }
        else if(rear == -1){    //如果判断队列已经销毁
            cout<<"队列已被销毁！"<<endl;
            return;
        }
        for(int i = 0;i < rear;i++){    //循环遍历
            cout<<content[i]<<" ";
        }
        cout<<endl;
    }
    T head(){   //取队头元素
        return content[HEAD];   //返回第一个元素
    }
    void empty(){   //清空队列
        rear = 0;   //只需要将队尾放在队头即可，原先储存的会被覆盖，无影响
    }
    void destroy(){ //销毁队列
        delete content; //清空content指针内存（销毁）
        rear = -1;   //只需要将队尾放在队头即可，原先储存的会被覆盖，无影响
    }
};

int main() {
    //测试功能是否实现
    queue <int> test(3);
    cout<<"1,2,3,4入队"<<endl;
    test.push_back(1);  test.push_back(2);    test.push_back(3);  test.push_back(4);
    cout<<"队列是否已满："<<test.isfull()<<endl;
    test.tarverse();
    cout<<"出队操作执行两次：\n遍历：";
    test.pop(); test.pop();
    test.tarverse();
    cout<<"4入队：\n遍历：";
    test.push_back(4);
    test.tarverse();
    cout<<"队首："<<test.head()<<endl;
    test.empty();
    test.tarverse();
    test.destroy();
    test.tarverse();
}