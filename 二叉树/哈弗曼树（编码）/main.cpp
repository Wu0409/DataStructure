//功能：二叉树 - 哈弗曼树（编码）
//设计者：Yuanchen Wu
//版本号：2019.1.17

#include <iostream>
#include <vector>

typedef struct treenode{
    double weight;
    int tag;    //存储编码
    treenode* l_child;  //左节点
    treenode* r_child;  //右节点
};
bool compare(const treenode * p1, const treenode * p2) {    //自定义比较函数，用于容器的排序
    return p1->weight > p2->weight; //前者大于后者，返回true
}
using namespace std;
class huffmancode{  //创建哈夫曼类
private:
    treenode* root; //记录根节点
    vector <treenode*> list;    //创建存放节点的容器
    vector <double> weight_list;    //记录权值
    void code(treenode * root){ //用于递归，实现代码
        if(root->l_child != NULL){  //左孩子为空
            root->l_child->tag = 0; //标记为0
            code(root->l_child);    //向下递归调用
        }
        if(root->r_child != NULL){  //右孩子为空
            root->r_child->tag = 1; //标记为1
            code(root->r_child); //向下递归调用
        }
    }
public:
    huffmancode(vector <double> weight_list){   //初始化，创建哈弗曼树
        this->weight_list = weight_list;    //记录权值，存放至weight_list成员
        for(int i = 0;i < weight_list.size();i++){  //将每个权值初始化为一个无左右孩子的子树
            treenode *p = new treenode; //动态开辟
            p->weight = weight_list[i]; p->l_child = NULL;  p->r_child = NULL;  //初始化节点
            list.push_back(p);  //放入list容器
        }
        sort(list.begin(),list.end(),compare);  //从大到小排序
        /*  验证比较函数是否正确
        for(int i = 0;i < list.size();i++){
            cout<<list[i]->weight<<endl;
        }
         */
        while(list.size() != 1){    //循环实现，每次找出权值最小的两个，合并成一颗子树，最后留下的一棵树即为哈弗曼树
            treenode* p = new treenode; //动态开辟
            p->weight = list[list.size()-1]->weight + list[list.size()-2]->weight;  //合并权值
            p->l_child = list[list.size()-1];   //将其中一颗作为左孩子
            p->r_child = list[list.size()-2];   //将其中一颗作为右孩子
            list.pop_back();    list.pop_back();    //将权值最小的两棵树删除
            list.push_back(p);  //将合并的树放入容器
            sort(list.begin(),list.end(),compare);  //重新排序
        }
        /*  用于测试生成哈弗曼树是否正确
         cout<<list[i]->weight<<endl;
         */
        root = list[0]; //记录根节点
        root->tag = 0;  //设置标签为0
        code(root); //进行编码
    }
    void find(double weight,treenode* root,string str){ //找某个权值对应的哈夫曼编码
        str  = str + to_string(root->tag);  //添加该节点tag
        /*  遍历路径
        cout<<str<<" ";
        cout<<endl;
         */
        if(root->weight == weight){ //遍历到所需要的节点内容的节点
            for(int i = 1;i < str.length();i++){    //第一个root根节点tag不需要输出
                cout<<str[i];   //输出对应权值的哈夫曼码
            }
            cout<<endl; //换行
        }
        if((root->tag != weight) && (root->l_child == NULL) && (root->r_child == NULL)){
            //如果遍历到叶子节点但不是目标内容，返回
            return; //！！！返回就相当于路径退回前面的节点
        }
        if(root->l_child != NULL){  //左孩子不空
            find(weight,root->l_child,str); //递归调用
        }
        if(root->r_child != NULL){  //右孩子不空
            find(weight,root->r_child,str); //递归调用
        }
    }
    void display(){ //输出所有权值的哈夫曼编码
        treenode* p = root; //工作指针
        for(int i = 0;i < weight_list.size();i++){  //遍历每个权值（叶子节点）
            string result = ""; //创建字符串用于记录路径
            cout<<"权值"<<weight_list[i]<<"对应的编码：";   //输出
            find(weight_list[i],p,result);  //找到当前节点的路径
        }
    }
};
int main(){
    //测试代码
    vector <double> weight_list = {1,2,4,6};
    huffmancode test(weight_list);
    test.display();

    /*  自定义权值
    cout<<"输出权值的个数："<<endl;
    int num;    cin>>num;   //记录权值的个数
    vector <double> weight_list;
    cout<<"依次输入权值："<<endl;
    for(int i = 0;i < num;i++){ //for循环依次输入权值
        double temp;    cin>>temp;
        weight_list.push_back(temp);
    }
    */
}

