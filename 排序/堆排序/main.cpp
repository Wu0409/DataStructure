//功能：排序 - 堆排序
//设计者：Yuanchen Wu
//版本号：2019.1.20
//备注：使用静态数组作"二叉树"，STL库有完整的堆排序算法（建堆等），参考：https://zhuanlan.zhihu.com/p/45725214

#include <iostream>
using namespace std;

void swap(int &a, int &b){  //设置交换函数，使用引用，节省空间
    int temp = a;   //中间变量，记录a被覆盖前的值
    a = b;  //b覆盖a
    b = temp;   //temp赋值给b
}
void buildtree(int* tree,const int* input,int num){ //用数组
    for(int i = 0;i < num;i++){  //for循环遍历
        tree[i] = input[i];  //将索引值所对应的内容放入数列，index起始值为0
    }
}
void adjust(int* tree,int num){ //调整为大顶堆
    for(int i = num - 1;i >= 0;i--){    //最底层最右边从前一次比较根节点大小
        if(i % 2 == 1){ //对应节点所在数组下标为奇数
            if(tree[(i-1)/2] < tree[i] && (i-1)/2 >= 0){    //如果根节点小
                swap(tree[(i-1)/2],tree[i]);    //交换根节点与该节点的值
            }
        }
        else{   //对应节点所在数组下标为偶数
            if(tree[(i-2)/2] < tree[i] && (i-2)/2 >= 0){    //最底层最右边从前一次比较根节点大小
                swap(tree[(i-1)/2],tree[i]);    //交换根节点与该节点的值
            }
        }
    }
}
void to_SmallTopHeap(int* tree,int num){    //调整为小顶堆
    for(int i = num - 1;i >= 0;i--){    //最底层最右边从前与根节点交换
        swap(tree[i],tree[0]);  //交换
        adjust(tree,i); //再次调整为小顶堆
    }
}
void sort(int* target,int num){ //堆排序
    int* tree = new int(num);   //动态开辟一个数组（作"二叉树"）
    buildtree(tree,target,num); //建树
    adjust(tree,num);   //建大顶堆
    to_SmallTopHeap(tree,num);  //调整为小顶堆
    for(int i = 0;i < num;i++){ //排序后的赋值给排序前的
        target[i] = tree[i];    //赋值
    }
}
int main(){
    int a[] = {57,40,38,11,13,34,48,75,6,19,9,7};
    cout<<"排序前："<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(a,12);
    cout<<"排序后："<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}