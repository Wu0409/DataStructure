#include <iostream>
#include <string>

using namespace std;
typedef struct listnode{
    int tag;    //0表示内容，1表示子表
    union { //共用体——表示原子或子表
        char element;  //atom原子内容
        listnode * subnext; //子表
    };
    listnode * next;    //同层的下一个节点
};
class GeneralizedList{
private:
    listnode * head1;    //头结点,与head方法不起冲突
    bool isvalue(const char ch){ //判断是否是原子内容
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    listnode * create(char* target){    //用于递归初始化广义表
        if(strlen(target) == 1) {   //此步主要是为了取head（）调用方便而写——参数长度为1的时候
            listnode *head1 = NULL; //初始化，这里我也用了head1，屏蔽了外部的head1（可修改）
            head1 = new listnode;   //动态开辟内存
            head1->tag = 0; //标签设置为原子0
            head1->element = *target;   //将*target赋值给element
            head1->next = NULL;
            return head1;
        }
        static int count = 0;   //字符串计数器，设置static使得递归不会从头开始
        count++;    //跳过第一个（
        listnode *head1 = NULL;  //初始化，这里我也用了head1，屏蔽了外部的head1（可修改）
        listnode *cur = NULL;   //存放
        while(target[count] != '\0'){ //遍历到头
            if(isvalue(target[count]))  //判断是否符合原子内容
            {   //符合的情况
                listnode *p = new listnode; //设置工作节点
                p->tag = 0; //原子：标签设置为0
                p->element = target[count]; //开辟内存
                if(head1 == NULL){   //判断是否是第一个节点
                    head1 = p;   //将工作节点赋值给头结点
                    cur = p;    //将记录前一个节点的指针赋值为工作指针p
                }
                else {  //不是作为头结点
                    cur->next = p;  //将前一个节点指针指向该节点
                    cur = p;    //将该节点设置为前一个节点
                }
                count++;    //计数器++，字符串向后读取一位
            }
            else if(target[count] == '(')   //判断为子表
            {
                listnode *p = new listnode();   //设置工作节点
                p->tag = 1; //子表将标签设置为1
                p->subnext = NULL;  //初始化共用体中的subnext节点
                if(head1 == NULL){   //判断是否是第一个节点
                    head1 = p;   //将工作节点赋值给头结点
                    cur = p;    //将记录前一个节点的指针赋值为工作指针p
                }
                else {
                    cur->next = p;  //将前一个节点指针指向该节点
                    cur = p;    //将该节点设置为前一个节点
                    cur->subnext = create(target);  //递归调用创建子表
                }
            }
            else if(target[count] == ')')   //广义表（子表）的结束
            {
                count++;    //字符串计数器++，即向后读取一位字符串
                return head1;    //返回地址
            }
            else {  //如果都不是，如","，跳过
                count++;    //字符串计数器++，即向后移动一位字符串
            }
        }
        return head1;    //结束，返回地址
    }
    void pr(listnode * head1){//用于递归调用，输出字符串
        listnode* cur = head1;   //将工作指针设置为传入的指针（地址）
        while(cur != NULL)  //循环，直至为空指针，即到尾
        {
            if(cur->tag == 0 )  //标签为0 — 原子
            {
                cout<<cur->element; //输出原子的内容
                if(cur->next != NULL)   //不是最后一个，则向后添加","
                {
                    cout<<",";  //输出","
                }
            }
            else if(cur->tag == 1)  //标签为1 - 子表
            {
                cout<<"(";  //先输出"（"
                pr(cur->subnext);   //递归调用输出子表内容
                if(cur->next != NULL )  //不是最后一个，则向后添加","
                {
                    cout<<",";  //输出","
                }
            }
            cur = cur->next ;   //移动到下一个节点
        }
        cout<<")";
    }
    char * get_head(char *target){
        listnode *cur = head1->subnext;   //将工作指针设置为传入的指针（地址）
        static int count = 1;  //计数器
        target[0] = '(';
        while(cur != NULL)  //循环，直至为空指针，即到尾
        {
            if(cur->tag == 0 )  //标签为0 — 原子
            {
                target[count] = cur->element; //赋值原子的内容
                count++;
                if(cur->next != NULL)   //不是最后一个，则向后添加","
                {
                    target[count] = ',';  //输出","
                    count++;
                }
            }
            else if(cur->tag == 1)  //标签为1 - 子表
            {
                target[count] = '(';  //先输出"（"
                count++;
                pr(cur->subnext);   //递归调用输出子表内容
                if(cur->next != NULL )  //不是最后一个，则向后添加","
                {
                    target[count] = ',';  //输出","
                    count++;
                }
            }
            cur = cur->next ;   //移动到下一个节点
        }
        target[count] = ')';
        target[count+1] = '\0';
    }
    int dep(listnode* head){	//表的最大深度
        listnode* cur = head;
        int maxdepth = 1;
        while(cur)
        {
            int depth = 1;
            if (cur->tag == 1)
            {
                depth += dep(cur->subnext);
                if (depth > maxdepth){
                    maxdepth = depth;
                }
            }
            cur = cur->next;
        }
        return maxdepth;
    }
public:
    GeneralizedList(char* target){  //广义表的输出，pr（）需要递归调用，故封装一个display方法
        head1 = create(target);
    }
    GeneralizedList& head(){
        if(head1->tag == 0){
            return *new GeneralizedList(&head1->element);   //返回动态开辟的内存地址
        }
        else {  //说明是子表
            char * target = new char(50);
            target = get_head(target);
            return *new GeneralizedList(target);
        }
    }
    int length(){   //获得广义表深度
        int count = 0;  //计数器
        listnode * p = head1;   //设置工作指针
        while(p != NULL){   //遍历第一层
            count++;    //计数器++
            p = p->next;    //到下一个节点
        }
        return count;
    }
    int depth(){
        return dep(this->head1);
    }
    friend ostream & operator <<(ostream &out,GeneralizedList &list);   //运算符重载实现广义表的输出
};
ostream & operator <<(ostream &out,GeneralizedList &list){
    if(list.head1->tag == 0 && list.head1->next == NULL){   //如果只有一个元素，不作为子表
        out<<list.head1->element;
        return out;
    }
    //运算符重载实现广义表的输出
    out<<"(";  //输出第一个"（"
    list.pr(list.head1); //调用pr递归方式输出广义表
    return out;
}
int main() {
    cout<<"初始化:\"(a,b,(c,d,(e,f)))\""<<endl;
    GeneralizedList test("(a,b,(c,d,(e,f)))");
    cout<<"遍历测试："<<endl;
    cout<<test<<endl;
    cout<<"head（）方法测试:"<<endl;
    cout<<test.head()<<endl;
    cout<<"length()方法测试:"<<endl;
    cout<<test.length()<<endl;
    cout<<"depth()方法测试:"<<endl;
    cout<<test.depth()<<endl;
    return 0;
}