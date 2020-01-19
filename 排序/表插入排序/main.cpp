//功能：排序 - 表插入排序
//设计者：Yuanchen Wu
//版本号：2019.1.19

#include <iostream>
using namespace std;
typedef struct node{
    int data;
    int pointer;    //设置数组指针
};
//备注list表，index = 0位置用于记录最小的元素所在的索引
int* sort(int* target,int num){
    node list[30];  //储存记录的链表(静态数组)
    for(int i = 0;i < num;i++){ //从数组头开始遍历
        list[i+1].data = target[i]; //将数组i位所在的元素放入"链表"
        if(i == 0){ //初始化"链表"
            list[1].pointer = 0;    //设定下一位为0，即链表结尾（当前只有这一个元素）
            list[0].pointer = 1;    //设定最小的指针为index=1（当前只有这一个元素）
            continue;
        }
        if(list[list[0].pointer].data > target[i]){ //比当前记录最小还要小;
            list[i+1].pointer = list[0].pointer;    //把当前元素的指针指向之前最小的元素位置，即原先index=0记录的位置
            list[0].pointer = i+1;  //此时最小元素的指针即为i+1
            continue;
        }
        int p = list[0].pointer;    //设置一个工作指针
        int pre;    //记录p的前驱i
        while(p != 0){  //若是中间元素
            if(list[p].data > target[i]){   //找到第一个比target[i]大的元素
                break;  //跳出循环
            }
            pre = p;    //记录前一个节点索引
            p = list[p].pointer;    //工作指针指向下一个节点
        }
        if(p == 0){ //p指到尾，即说明target[i+1]是最大的
            list[pre].pointer = i + 1;    //前一个索引修改为当前元素的索引
            list[i+1].pointer = 0;  //当前元素最大，是链表的尾，即设置为0
        }
        else{
            int temp = list[pre].pointer;   //记录前一个原本的后继
            list[pre].pointer = i+1;    //前一个节点后一个指向当前元素
            list[i+1].pointer = temp;   //当前元素下一个指向前一个原本的后继
        }
    }
    int p = list[0].pointer;    //设置工作指针
    int count = 0;  //计数器
    while(p != 0){  //循环
        target[count] = list[p].data;   //从0->Num对传入的数组重新赋值
        p = list[p].pointer;    //p到下一个节点
        count++;    //到数组下一个索引值
    }
}

int main() {
    int a[] = {4,8,3,1,2};
    cout<<"排序前：";
    for(int i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(a,5);
    cout<<"排序后：";
    for(int i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}