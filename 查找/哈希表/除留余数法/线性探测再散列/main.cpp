//功能：查找 - 除留余数法 - 线性探测再散列
//设计者：Yuanchen Wu
//版本号：2019.1.22

//备注：简单例子

#include <iostream>
#include <cstdarg>

using namespace std;
class Hashmap{  //H()key = key mod p,此时p取5
private:
    int *element;   //数组指针
public:
    Hashmap(int count,...){   //初始化线性表，第一个参数为长度
        element = new int(count);   //动态开辟内存,0位为空
        for(int i = 0;i < count;i++){
            element[i] = 0; //将动态开辟的数组全部初始化为0
        }
        va_list args;       //不定参数实现初始化,cstdarg库实现
        va_start(args,count);
        while(count--){
            int target = va_arg(args,int);  //通过迭代器获取当前元素
            int index = target % 5; //得到理论上不冲突存在的位置
            while(1){   //循环
                if(element[index % 6] == 0){    //判读是否冲突
                    element[index % 6] = target;    //不冲突，将该元素放入
                    break;
                }
                index ++;   //冲突向后移一位
            }
        }
        va_end(args);
    }
    int search(int target){ //查找
        int index = target % 5; //理论上不冲突存在的位置
        if(element[index] == target){   //理论上不冲突存在的位置是否是该元素
            return index;   //是该元素，返回索引
        }
        else{   //不是该元素，即发生冲突
            index++;    //
            while((index % 6) != target % 5){   //向后遍历至理论上不冲突存在的位置前一个
                if(element[index % 6] == target){   //判断当前元素是否是目标元素
                    return index % 6 ;  //是该元素，返回索引
                }
                index++;    //不是该元素，向后移动
            }
        }
        return -1;  //未找到
    }
};
int main() {
    Hashmap test(6,12,39,18,24,33,21);
    cout<<test.search(12)<<endl;
    cout<<test.search(39)<<endl;
    cout<<test.search(18)<<endl;
    cout<<test.search(24)<<endl;
    cout<<test.search(33)<<endl;
    cout<<test.search(21)<<endl;
    cout<<test.search(99)<<endl;
    return 0;
}