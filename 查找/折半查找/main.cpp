//功能：折半查找（有序表）
//设计者：Yuanchen Wu
//版本号：2019.1.21

#include <iostream>
using namespace std;

int search(int *list,int target,int start,int end){  //查找目标，查找范围
    int left = start;   //设置左指针
    int right = end;    //设置右指针
    while(left <= right){   //循环，左指针小于等于右指针
        int middle = (left + right) / 2;    //折半
        if(list[middle] == target){ //索引中间值对应元素是目标元素
            return middle;  //返回该索引值
        }
        else if(list[middle] < target){ //索引中间值对应元素小于目标元素，即目标值在middle的右边
            left = middle + 1;  //重新设置左指针
        }
        else{   //索引中间值对应元素大于目标元素，即目标值在middle的左边
            right = middle - 1; //重新设置右指针
        }
    }
    return -1;
}

int main() {
    int test[] = {2,4,5,6,7,8,9};
    cout<<search(test,2,0,6)<<endl;
    cout<<search(test,4,0,6)<<endl;
    cout<<search(test,5,0,6)<<endl;
    cout<<search(test,6,0,6)<<endl;
    cout<<search(test,7,0,6)<<endl;
    cout<<search(test,8,0,6)<<endl;
    cout<<search(test,9,0,6)<<endl;
}