//功能：排序 - 简单选择排序
//设计者：Yuanchen Wu
//版本号：2019.1.19

#include <iostream>
using namespace std;
void sort(int* target,int num){ //简单选择排序
    for(int i = num -1;i >= 0;i--){
        int index = 0;
        for(int j = 0;j <= i;j++){
            if(target[index] < target[j]){
                index = j;
            }
            int temp = 0;
            temp = target[i];
            target[i] = target[index];
            target[index] = temp;
        }
    }
}
int main() {
    int test[] = {9,4,6,2,1,3};
    sort(test,6);
    for(int i:test){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}