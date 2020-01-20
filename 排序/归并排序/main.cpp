//功能：排序 - 归并排序
//设计者：Yuanchen Wu
//版本号：2019.1.20

#include <iostream>
using namespace std;

void merge(int* target,int l_pointer,int middle,int r_pointer){   //合并
    int l_sum = middle - l_pointer - 1; //左侧数组最大索引
    int r_sum = r_pointer - middle; //右侧数组最大索引
    if((r_pointer - l_pointer) == 1){   //相隔一个
        if(target[r_pointer] < target[l_pointer]){  //若前者大于后者，交换
            swap(target[r_pointer],target[l_pointer]);  //交换
            return; //返回
        }
    }
    int* leftlist = new int(middle - l_pointer);    //动态开辟内存，记录左边部分数组
    int* rightlist = new int(r_pointer - middle + 1);   //动态开辟内存，记录右边部分数组
    int l_count = 0;    //左侧数组计数器
    int r_count = 0;    //右侧数组计数器
    for(int i = l_pointer;i < middle;i++){  //遍历
        leftlist[l_count] = target[i];  //记录左边部分数组
        l_count++;  //计数器++，下一个
    }
    for(int i = middle;i <= r_pointer;i++){ //遍历
        rightlist[r_count] = target[i]; //记录右边部分数组
        r_count++;  //计数器++，下一个
    }
    l_count = 0;    r_count = 0;    //重置计数器
    int count = l_pointer;  //target的计数器（指针）
    while(count <= r_pointer){
        if(leftlist[l_count] < rightlist[r_count] && (l_count <= l_sum) && (r_count <= r_sum)){
            //左右数组都不空，且左头小于右头
            target[count] = leftlist[l_count];
            l_count++;  count++;    //左数组头元素并入（相当于pop出，到下一位）
            continue;
        }
        if(leftlist[l_count] >= rightlist[r_count] && (l_count <= l_sum) && (r_count <= r_sum)){
            //左右数组都不空，且左头小于右头
            target[count] = rightlist[r_count];
            r_count++;  count++;    //右数组头元素并入（相当于pop出，到下一位）
            continue;
        }
        if((l_count > l_sum) && (r_count <= r_sum)){   //左侧数组全部放入,只剩右侧数组
            target[count] = rightlist[r_count]; //只剩右数组，放入右数组元素
            r_count++;  count++;    //计数器++，下一位
            continue;
        }
        if((l_count <= l_sum) && (r_count > r_sum)){   //右侧数组全部放入,只剩左侧数组
            target[count] = leftlist[l_count];  //只剩左数组，放入左数组元素
            l_count++;  count++;    //计数器++，下一位
            continue;
        }
    }
}
void sort(int* target,int l_pointer,int r_pointer){
    if(l_pointer == r_pointer){ //左指针 == 右指针，即只有一个了，无需排序
        return;
    }
    else{
        int middle = (l_pointer + r_pointer) / 2;   //计算中间的索引值
        sort(target,l_pointer,middle);  //分割的左半部分，进行排序
        sort(target,middle + 1,r_pointer);  //分割的右半部分，进行排序
        merge(target,l_pointer,middle + 1,r_pointer);   //将两部分合并
    }
}

int main(){
    int a[] = {4,2,7,6,5,1,3,0};
    sort(a,0,7);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}