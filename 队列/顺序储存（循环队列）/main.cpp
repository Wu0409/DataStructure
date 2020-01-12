//功能：队列-顺序储存(循环队列)
//设计者：Yuanchen Wu
//版本号：2019.1.12
//备注：顺序表的对列遍历暂时没有想出什么好办法，在pop后，rear和front位置变化，原先比较哪个在前，再对应写输出，
//     无法判断哪里是原先已经pop掉的元素，依旧会被输出。因此，添加了num记录了队列中的数目来约束遍历的次数。
//     感觉不是最好的解决办法。

#include <iostream>
using namespace std;
template <typename T>
class queue{
private:
    T * content;    //储存内容
    int front; //常量，表示头
    int rear;   //尾指针
    int size;   //记录该队列大小
    int num;    //备注已写明，用于记录对列元素个数，约束遍历的次数
public:
    queue(int size){    //初始化队列
        this->front = 0; //初始化队头
        this->rear = 0; //队头
        this->size = size+1;  //记录队列大小
        num = 0;    //初始化，个数为0
        content = new T(size+1);  //动态分配内存
    }
    bool isempty(){
        return front == rear;    //如果头==尾，即队列为空
    }
    bool isfull(){
        return (rear + 1) % size == front;  //队满
    }
    void push_back(T target){   //入队
        if(isfull()){   //判断队列是否为满
            cout<<"队列已满！"<<endl;
        }
        else {
            rear = (rear+1) % size;	//队尾后移
            content[rear] = target;		//插入数据
            num++;
        }
    }
    T pop(){ //出队
        if(isempty()){  //队空的情况
            cout<<"队列已空！"<<endl;
        }
        else {  //队未空的情况
            T target = content[front + 1];  //记录队首元素，用于最后返回
            front = (front + 1) % size; //front向后移动一个位置
            num--;  //元素个数--
            return target;  //返回pop出的元素
        }
    }
    void traverse(){  //遍历
        int count = 1;  //用于记录遍历的次数
        if(isempty()){  //判断对列是否为空，若为空，返回"null"
            cout<<"null"<<endl;
        }
        if(front < rear){   //front指针在rear前
            for(int i = front + 1;i <= rear;i++){   //从front开始遍历即可
                if(count <= num) {  //遍历次数小于元素个数
                    cout << content[i] << " ";  //每次遍历一个元素
                }
                else{
                    break;  //遍历次数超过了元素个数，跳出循环
                }
                count++;    //遍历次数++
            }
            cout<<endl; //换行，为了输出和格式美观
        }
        if(rear < front){   //尾指针在front前
            for(int i = front;i < size -1;i++){ //先从front遍历到rear
                if(count <= num) {  //遍历次数小于元素个数
                    cout << content[i] << " ";
                }
                else{   //遍历次数大于元素个数，跳出循环
                    break;
                }
                count++;
            }
            for(int i = 0;i < front;i++){   //再从头遍历至rear，可能会遇到已经pop的元素，因此使用count约束遍历次数
                if(count <= num) {  //遍历次数小于元素个数
                    cout << content[i] << " ";  //每次输出一个
                }
                else{   //遍历次数大于元素个数
                    break;
                }
                count++;    //遍历次数++
            }
            cout<<endl; //换行，为了输出和格式美观
        }
    }
    void head(){   //取队头元素
        if(isempty()){  //如果队列为空
            cout<<"队列为空！"<<endl;
        }
        else {
            cout<<content[front + 1]<<endl;
        }//返回第一个元素
    }
    void empty(){   //清空队列
        front = 0;  //相当于初始化队列
        rear = 0;   //相当于初始化队列
    }
    void destroy(){ //销毁队列
        delete content; //清空content指针内存（销毁）
        rear = -1;   //只需要将队尾放在队头即可，原先储存的会被覆盖，无影响
        cout<<"队列已销毁"<<endl;
    }
};

int main() {
    //测试功能是否实现
    queue <int> test(4);
    cout<<"1,2,3,4入队"<<endl;
    test.push_back(1);  test.push_back(2);    test.push_back(3);  test.push_back(4);
    test.traverse();
    cout<<"每次pop一个元素："<<endl;
    test.pop(); test.traverse();
    test.pop(); test.traverse();
    test.pop(); test.traverse();
    test.pop(); test.traverse();
    cout<<"取队头：";   test.head();
    cout<<"1,2,3入队"<<endl;
    test.push_back(1);  test.push_back(2);    test.push_back(3);
    test.traverse();
    test.empty();
    cout<<"empty(),队列是否为空："<<test.isempty()<<endl;
    test.traverse();
    test.destroy();

}