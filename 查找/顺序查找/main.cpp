//功能：查找 - 顺序查找
//设计者：Yuanchen Wu
//版本号：2019.1.21

#include <iostream>
#include <cstdarg>
using namespace std;

typedef struct list{
    int *element;   //0号留空
    int length;
    list(int count,...){   //初始化线性表，第一个参数为长度
        length = count;    //赋值长度
        element = new int(count + 1);   //动态开辟内存,0位为空
        int *p = element;   //设置工作指针

        va_list args;       //不定参数实现初始化,cstdarg库实现
        va_start(args,count);
        while(count--){
            p++;
            *p = va_arg(args,int);
        }
        va_end(args);
    }
};
int search(list target,int key){
    target.element[0] = key;    //设置哨兵
    int i;  //计数器
    for(i = target.length;target.element[i] != key;--i);    //从后向前找
    return i;   //找不到时为0
}
int main() {
    list test(7,4,2,1,3,6,8,5);
    cout<<search(test,10)<<endl;
    cout<<search(test,3)<<endl;
}