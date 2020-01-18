//功能：排序 - 折半插入排序
//设计者：Yuanchen Wu
//版本好：2019.1.18

#include <iostream>
using namespace std;

void sort(int* target,int num){
    for(int i = 1;i < num;i++){ //i对应需要插入目标
        int pivotal = target[i];    //目标
        int l_pointer = 0;  //初始左指针
        int r_pointer = (i+1)/2;    //初始右指针
        while (l_pointer <= r_pointer)  //当左指针小于等于右指针时循环
        {
            int index = (l_pointer +r_pointer) / 2; //取中间的索引
            if(target[index] > pivotal) //index对应元素大于目标，说明在左侧
                r_pointer = index-1;    //重新设置右指针设定范围
            else
                l_pointer = index+1;    //index对应元素小于目标，说明在右侧，重新设置右指针设定范围
        }
        cout<<"result:"<<r_pointer<<endl;
        int pointer = r_pointer;    //设置指针(原先的插入排序使用，未作修改)
        //pointer+1就是插入的位置
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