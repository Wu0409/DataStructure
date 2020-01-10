//功能：线性表的顺序储存
//设计者：Wu Yuanchen
//版本号：2019-1-10

#include <iostream>
#include <cstdarg>

using namespace std;
template <typename T>
class List{
private:
    int len;
    T * content;
public:
    List(int count,...){   //初始化线性表，第一个参数为长度
        len = count;    //赋值长度
        content = new T(100);   //动态开辟内存
        T * p = content;

        va_list args;       //不定参数实现初始化
        va_start(args,count);
        while(count--)
        {
            *p = va_arg(args,T);
            p++;
        }
        va_end(args);

    }
    void empty(){   //销毁线性表
        this->len = 0;  //将长度设置为0
        delete content; //清空内存
        cout<<"列表已销毁！"<<endl;
    }
    int length(){   //求长度
        return this->len;   //返回长度
    }
    void traverse(){    //遍历线性表
        T * head = content;
        for(int i = 0;i <= len-1;i++){  //for循环进行遍历，每次到下一个地址
            cout<<*content<<" ";
            content++;
        }
        cout<<endl;
        content = head;
    }
    int index(T target){    //获取内容的索引值
        T * p = content;
        for(int i = 0;i <= len-1;i++){  //for循环遍历查找
            if(target == *p){
                return i;   //若找到,返回索引
            }
            p++;    //下一个地址
        }
        return -1;  //未找到

    }
    T get(int target){
        T * temp = content;
        temp += target; //指针指向index位置
        return *temp;
    }
    void insert(int index,T target){
        int count = len - index;
        if(len < 100){  //长度小于100情况
            T *temp = content;
            temp += (len - 1);
            while(count--) {    //执行count次循环
                *(temp+1) = *temp;  //将目标位置后的元素向后移动一个
                temp --;
            }
            *(content+index) = target;  //将留出的空位置放入插入的值
            len++;
        }
        else{
            cout<<"长度超出初始化容量!"<<endl;
        }
    }
};
int main(){
    List <int> test(5,1,2,3,4,5); //  第一个参数是长度，后面是可变参数初始化线性表
    cout<<"长度："<<test.length()<<endl;
    cout<<"遍历：";    test.traverse();
    cout<<"1 所在的位置："<<test.index(1)<<endl;
    cout<<"获得index为1的变量："<<test.get(1)<<endl;
    cout<<"在index=0的位置插入1，";  test.insert(0,1);
    cout<<"插入后，遍历：";    test.traverse();
    return 0;
}
