//功能：查找 - 除留余数法 - 二次探测再散列
//设计者：Yuanchen Wu
//版本号：2019.1.22

//备注：简单例子,没有自定义取几的余，该例子里是mod5，开辟数组长度设置为了count+1

#include <iostream>
#include <cstdarg>
#include <cmath>

using namespace std;
class Hashmap{  //H()key = key mod p,此时p取5
private:
    int *element;   //数组指针
    int length;
public:
    Hashmap(int count,...){   //初始化线性表，第一个参数为长度
        length = count + 1;
        element = new int(length);   //动态开辟内存,0位为空
        for(int i = 0;i <= count;i++){
            element[i] = -1; //将动态开辟的数组全部初始化为-1
        }
        va_list args;       //不定参数实现初始化,cstdarg库实现
        va_start(args,count);
        while(count--){
            int target = va_arg(args,int);  //通过迭代器获取当前元素
            int index = target % 5; //得到理论上不冲突存在的位置
            int sym = 1;    //用于记录冲突时是+/-（即向前还是向后）
            int judge = 0;  //判断是第一次还是第二次（+/-），若是第二次，则基数向后取（1->2->3->4->...）
            int num = 1;    //向前或向后的大小
            while(1){   //循环
                if(element[index % length] == -1){    //判读是否冲突
                    element[index % length] = target;    //不冲突，将该元素放入
                    break;
                }
                else{   //冲突
                    index = target % 5; //index重置为理论上未冲突的位置，为后面计算
                }
                if(judge == 0){ //第一次
                    index += (sym * pow(num,2));    //二次探测
                    if(index < 0){  //如index < 0
                        index = (count + 1) - (abs(index) - 1); //计算index小于0后，从尾部向前移动后的位置
                    }
                    sym *= -1;  //正变负，负变正
                    judge++;
                }
                else{   //第二次（下一次基数要++，1->2->3->4->...）
                    index += (sym * pow(num,2));
                    if(index < 0){  //如index < 0
                        index = (count + 1) - (abs(index) - 1); //计算index小于0后，从尾部向前移动后的位置
                    }
                    num++;  //基数++（1->2->3->4->...）
                    sym *= -1;  //正变负，负变正
                    judge = 0;  //重置judge，重新开始判断
                }
            }
        }
        va_end(args);
        /*
        //测试哈希表创建的是否正确
        for(int i = 0;i < 8;i++){
            cout<<element[i]<<" ";
        }
        cout<<endl;
         */
    }
    int search(int target){ //查找
        int index = target % 5; //得到理论上不冲突存在的位置
        int sym = 1;    //用于记录冲突时是+/-（即向前还是向后）
        int judge = 0;  //判断是第一次还是第二次（+/-），若是第二次，则基数向后取（1->2->3->4->...）
        int num = 1;    //向前或向后的大小
        while(1){   //循环
            if(element[index % length] == target){    //判读是否冲突
                return index;
            }
            else{   //冲突
                index = target % 5; //index重置为理论上未冲突的位置，为后面计算
            }
            if(judge == 0){ //第一次
                index += (sym * pow(num,2));    //二次探测
                if(index < 0){  //如index < 0
                    index = length - (abs(index) - 1); //计算index小于0后，从尾部向前移动后的位置
                }
                sym *= -1;  //正变负，负变正
                judge++;
            }
            else{   //第二次（下一次基数要++，1->2->3->4->...）
                index += (sym * pow(num,2));
                num++;  //基数++（1->2->3->4->...）
                sym *= -1;  //正变负，负变正
                judge = 0;  //重置judge，重新开始判断
            }
        }
    }
};
int main() {
    Hashmap test(7,12,39,18,24,33,21,26);
    cout<<"26在哈希表中的位置："<<test.search(26)<<endl;
    cout<<"21在哈希表中的位置："<<test.search(21)<<endl;
    cout<<"12在哈希表中的位置："<<test.search(12)<<endl;
    cout<<"18在哈希表中的位置："<<test.search(18)<<endl;
    cout<<"39在哈希表中的位置："<<test.search(39)<<endl;
    cout<<"24在哈希表中的位置："<<test.search(24)<<endl;
    cout<<"33在哈希表中的位置："<<test.search(33)<<endl;
    return 0;
}