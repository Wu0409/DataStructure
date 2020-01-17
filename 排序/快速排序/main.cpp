//功能：排序 - 快速排序
//设计者：Yuanchen Wu
//版本号：2019.1.17

#include <iostream>
using namespace std;

void fast_sort(int* target,int start,int end){  //递归实现快速排序
    if(start > end){    //递归终止条件
        return; //返回
    }
    int pivot = target[start];  //设定枢轴量
    int l_pointer = start;  //左指针
    int r_pointer = end; //右指针
    while(l_pointer < r_pointer){   //直到左指针到右指针右边，即右指针为枢轴量所在位置
        while(l_pointer < r_pointer && target[r_pointer] >= pivot){  //从右，找到比枢轴量大的元素
            r_pointer--;    //向前移动一位
        }
        target[l_pointer] = target[r_pointer];  //交换
        while(l_pointer < r_pointer && target[l_pointer] <= pivot){  //从左，找到比枢轴量小的元素
            l_pointer++;    //向后移动一位
        }
        target[r_pointer] = target[l_pointer];  //交换
    }
    target[r_pointer] = pivot;  //左指针到右指针右边，右指针为枢轴量所在位置
    fast_sort(target,start,r_pointer-1);    //当前枢轴量左半部分，进行递归进行排序
    fast_sort(target,r_pointer+1,end);  //当前枢轴量右半部分，进行递归进行排序
}
int main() {
    int test[5] = {9,3,1,2,5};  //测试数列：3，9，1，2，5
    fast_sort(test,0,4);
    for(int i = 0;i <= 4;i++){  //遍历结果
        cout<<test[i];
    }
    return 0;
}