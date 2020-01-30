//功能：查找 - 除留余数法 - 伪随机探测再散列
//设计者：Yuanchen Wu
//版本号：2019.1.22

//备注：简单例子，伪随机数序列 d = 2,3,5,8,12,17,23,30,38,47,57,68...

#include <iostream>
#include <cstdarg>

using namespace std;
class Hashmap{  //H()key = key mod p,此时p取5
private:
    int *d; //伪随机数序列
    int *element;
public:
    Hashmap(int count,...){   //初始化线性表，第一个参数为长度
        d = new int(20);
        int add = 0;
        int a = 2;
        for(int i = 0;i < 20;i++){ //生成伪随机数序列
            add += a;
            d[i] = add;
            a++;
        }
        for(int i = 0;i <= 11;i++){
            cout<<d[i]<<" ";
        }
        cout<<endl;
        element = new int(count);   //动态开辟内存
        for(int i = 0;i < count;i++){
            element[i] = -1; //将动态开辟的数组全部初始化为-1
        }
        va_list args;       //不定参数实现初始化,cstdarg库实现
        va_start(args,count);
        while(count--){
            int target = va_arg(args,int);  //通过迭代器获取当前元素
            int index = target % 5; //得到理论上不冲突存在的位置
            int *p = d;
            int num = 0 + index;    //当前取到的伪随机数
            while(1){   //循环
                cout<<element[num % count]<<endl;
                if(element[num % count] == -1){    //判读是否冲突
                    element[num % count] = target;    //不冲突，将该元素放入
                    for(int i = 0;i <= 5;i++){
                        cout<<element[i]<<" ";
                    }
                    cout<<endl;
                    break;
                }
                num = index + (*p);
                p++;
            }
        }
        va_end(args);
        for(int i = 0;i <= 5;i++){
            cout<<element[i]<<" ";
        }
        cout<<endl;
    }

    /*
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
     */
};
int main() {
    Hashmap test(6,12,39,18,24,33,21);
    /*
    cout<<test.search(12)<<endl;
    cout<<test.search(39)<<endl;
    cout<<test.search(18)<<endl;
    cout<<test.search(24)<<endl;
    cout<<test.search(33)<<endl;
    cout<<test.search(21)<<endl;
    cout<<test.search(99)<<endl;
     */
    return 0;
}