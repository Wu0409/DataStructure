//功能：排序 - 直接插入排序
//设计者：Yuanchen Wu
//版本好：2019.1.18

#include <iostream>
using namespace std;

void sort(int* target,int num){
    for(int i = 1;i < num;i++){ //i对应需要插入目标
        int pivotal = target[i];
        int pointer = i-1;    //设置指针
        while(pointer >= 0){    //循环遍历
            if(target[i] >= target[pointer]){   //前面部分是有序的，遍历到比目标小，即到达所需要插入的位置
                break;  //跳出循环
            }
            pointer--;  //遍历到比目标大，说明需要插入的位置还在前面，向前移动
        }   //pointer+1就是插入的位置
        int temp = target[pointer + 1]; //记录前一个值
        int temp1;  //记录被覆盖的原本的值
        for(int j = pointer + 1;j < i;j++){
            temp1 = target[j+1];    //记录被覆盖前target的i+1位的值
            target[j+1] = temp; //用temp向后覆盖
            temp = temp1;   //将前一次记录被覆盖前target的i+1位的值赋值给temp
        }
        target[pointer+1] = pivotal;    //插入目标，完成一次排序，i前的都是有序的，i后的都是无序的
    }
}


int main() {
    int test[] = {9,4,6,3,7,1}; //测试数组
    sort(test,6);   //调用插入排序
    for(int i = 0;i < 6;i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    return 0;
}