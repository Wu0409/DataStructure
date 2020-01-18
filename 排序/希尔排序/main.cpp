//功能：排序 - 希尔排序
//设计者：Yuanchen Wu
//版本号：2019.1.18
//备注：希尔排序每个gap是直接插入排序！！！不是冒泡排序！例如：gap=5相当于5个5个一直接插入排序（最大情况下），有5组

#include <iostream>
using namespace std;

void sort(int* target,int num){
    int gap = 5;
    for(int n = 0;n <= 2;n++){  //计数器，每次gap递减2：5->3->1
        //直接插入排序
        for(int count = 0; count <= gap;count++) {  //每趟排序的组数 5-有5组，3-有2组，1-有1组
            for (int i = count; i < num; i += gap) { //i对应需要插入目标
                int pivotal = target[i];
                int pointer = i - gap;    //设置指针
                while (pointer >= 0) {    //循环遍历
                    if (pointer < 0) {  //防止数组越界
                        continue;
                    }
                    if (target[i] >= target[pointer]) {   //前面部分是有序的，遍历到比目标小，即到达所需要插入的位置
                        break;  //跳出循环
                    }
                    pointer -= gap;  //遍历到比目标大，说明需要插入的位置还在前面，向前移动
                }
                int temp = target[pointer + gap]; //记录前一个值
                int temp1;  //记录被覆盖的原本的值
                for (int j = pointer + gap; j < i; j += gap) {
                    temp1 = target[j + gap];    //记录被覆盖前target的i+gap位的值
                    target[j + gap] = temp; //用temp向后覆盖
                    temp = temp1;   //将前一次记录被覆盖前target的i+gap位的值赋值给temp
                }
                target[pointer + gap] = pivotal;    //插入目标，完成一次排序，i前的都是有序的，i后的都是无序的
            }
        }
        /*  测试每趟希尔排序
        for(int i = 0;i < 15;i++){
            cout<<target[i]<<" ";
        }
        cout<<endl;
         */
        gap -= 2;
    }
}

int main() {
    int test[] = {8,3,6,10,2,4,9,7,11,0,17,19,1,14,16}; //测试数组
    cout<<"未排序前："<<endl;
    for(int i = 0;i < 15;i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    sort(test,15);   //调用插入排序
    cout<<"排序后"<<endl;
    for(int i = 0;i < 15;i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    return 0;
}