//功能 - 排序 - 起泡排序
//设计者：Yuanchen Wu
//版本号：2019.1.19

#include <iostream>
using namespace std;
void sort(int* target,int n){   //起泡排序
    int i = n;  //设置循环册数
    while(i >= 1){  //循环条件
        int last_index = 1; //记录上一次交换的位置
        for(int j = 0;j < i;j++){
            if(target[j+1] < target[j]){    //如果后者小于前者，交换
                int temp = target[j];   //设置中间变量，记录target[j]
                target[j] = target[j+1];    //覆盖target[j]
                target[j+1] = temp; //将target[j+1]赋值为原先target[j]的值
                last_index = j;
            }
        }
        i = last_index; //将i重新设置为上一次交换的位置,后面的内容已经有序，无需在排序
    }
}
int main() {
    int test[] = {4,9,3,2,6,1};
    cout<<"排序前："<<endl;
    for(int i:test){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(test,6);
    cout<<"排序后："<<endl;
    for(int i:test){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
