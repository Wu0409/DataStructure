//功能：查找 - 哈希表 - 直接定址法
//设计者：Yuanchen Wu
//版本号：2019.1.21

//备注：简单例子

#include <iostream>
#include <cstdarg>
using namespace std;
class Hashmap{  //班级人数, H(key) = key - 1
    int *element;
public:
    Hashmap(int count,...){   //初始化线性表，第一个参数为长度
        element = new int(count + 1);   //动态开辟内存,0位为空
        int *p = element;   //设置工作指针

        va_list args;       //不定参数实现初始化,cstdarg库实现
        va_start(args,count);
        while(count--){
            *p = va_arg(args,int);
            p++;
        }
        va_end(args);
    }
    int get(int key){   //通过键返回对应的值
        return element[key-1];  //H(key) = key - 1
    }
};
int main() {
    Hashmap class_map(8,31,31,32,33,31,30,32,33,31);    //各班级人数
    for(int i = 1;i <= 8;i++){
        cout<<i<<"班人数："<<class_map.get(i)<<endl;
    }
    return 0;
}