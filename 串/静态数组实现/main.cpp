//功能：串-静态数组实现
//设计者：Yuanchen Wu
//版本号：2019.1.14
//待提高：目前子串查找使用朴素方式，index（）方法可以进行重载限制查找的索引范围

#include <iostream>
#include <string>
using namespace std;

class String{
private:
    int len;    //长度，从1开始计数
    char * content; //内容的地址
public:
    String(const char * target = NULL){ //初始化字符串
        if(target == NULL){ //空串
            len = 0;    //长度设置为0
        }
        else {
            len = strlen(target) + 1;   //求初始化内容参数长度
            content = new char(30); //动态分配内存
            for (int i = 0; i < len; i++) { //循环赋值
                content[i] = target[i]; //将初始化内容参数赋值给content
            }
            content[len] = '\0';    //末尾加上\0，
            // ******PS：运算符已经重载，不是判断\0判断结尾，但是保留
        }
    }
    int length(){   //求长度
        return len-1;   //返回长度
    }
    bool isempty(){ //判断串是否为空
        return len == 0;    //长度为0，即空
    }
    void add(String & other){ //字符串的连接
        int need_length = len + other.len -1;   //计算重新动态分配内存的长度
        char * temp = new char(need_length);    //动态分配内存temp作为新content
        for (int i = 0; i < len-1; i++) {   //将第一个字符串的内容放入新开辟的内存中
            temp[i] = content[i];   //第一个字符串的内容赋值给temp（新content）
        }
        for (int i = len-1; i < len + other.len-2; i++) {   //将第二个字符串的内容放入新开辟的内存中
            temp[i] = other.content[i-len+1];   //第二个字符串的内容赋值给temp（新content）
        }
        temp[len + other.len-2] = '\0'; //字符串末尾添加'\0作结尾'
        delete content; //清理原content内存
        content = temp; //将新的已经连接两字符串内存的地址赋值给content，作为新的content
        len = need_length;  //长度设置为两个长度之和
        //****PS：原本用静态数组实现，怕内存分配不够，姑动态分配了内存
    }
    void copy(String other){    //深赋值一个新的String
        len = other.len;    //长度设置
        content = new char(len);    //动态开辟内存（原本空字符串，未开辟）
        for(int i = 0;i <= len;i++){    //将原字符串内容复制给新的字符串
            content[i] = other.content[i];  //将原字符串内容依次复制给新的字符串
        }
    }
    bool compare(String other){ //对比
        if(len != other.len){   //如果连长度都不一致，那么必然不相等
            return false;   //返回false
        }
        else{
            for(int i = 0;i <= len-1;i++){  //循环遍历检索两个字符串内容是否相等
                if(content[i] != other.content[i]){ //一旦检索到不一致的地方
                    return false;   //返回false
                }
            }
            return true;    //检索完毕，内容都一致，返回true
        }
    }
    int index(char target){ //检索字符在哪个位置
        for(int i = 0;i < len;i++){ //循环进行检索
            if(target == content[i]){   //若检索到第一个
                return i;   //返回index值
            }
        }
        return -1;  //未检索到的情况
    }
    int search(const char * target){   //子串查找,朴素方式
        int target_length = strlen(target); //获取目标长度
        int target_count = 1;   //目标计数器
        int result = -1;    //记录index的位置，用于返回（若是子串的话）
        for(int i = 0;i <= len;i++){    //循环检索
            if(content[i] == target[0]){    //若第一个字符匹配到，则向后匹配target的字符
                result = i;
                int content_count = i + 1;
                while(target_count != target_length){   //循环，指导检索到target尾
                    if(content[content_count] != target[target_count]){//一旦检索到不匹配
                        break;  //跳出循环
                    }
                    target_count++; //target计数器++
                    content_count++;    //content计数器++
                }
                if(target_count == target_length){  //如果长度相等，说明检索完毕
                    return result;  //内容都一致，返回index值
                }
                else{
                    break;  //不一致，跳出循环，检索下一个字符串与子串的第一个字符匹配情况
                }
            }
        }
        return -1;  //检索完毕，未发现匹配，返回-1
    }
    void replace(char target,char modify_content){  //替换字符
        for(int i = 0;i <= len-1;i++){  //遍历进行检索
            if(content[i] == target){   //匹配到需要被替换的字符串内容
                content[i] = modify_content;    //替换为需要修改的内容
            }
        }
    }
    void replace(const char * target,const char * modify_content){  //替换字符串
        int position = -1;  //position默认值-1（未找到）
        int target_length = strlen(target);
        int target_count = 1;
        int result = -1;
        for(int i = 0;i <= len;i++){    //朴素的方式匹配字符串
            if(content[i] == target[0]){    //若匹配到第一个字母
                result = i; //记录子串第一个字母出现的位置，若完全匹配，则返回result
                int content_count = i+1;    //匹配内容的计数器
                while(target_count != target_length){   //匹配子串第二个内容开始是否匹配
                    if(content[content_count] != target[target_count]){ //一旦有不匹配的内容跳出循环
                        break;
                    }
                    target_count++; //目标计数器++
                    content_count++;    //源字符串内容计数器++
                }
                if(target_count == target_length){
                    position = result;  //计数器长度与子串长度相等，即是该字符串的子串
                }
                else{
                    break;  //未匹配到，跳出循环源字符串向后检索
                }
            }
        }
        //替换字符串阶段
        if(position != -1){ //如果找到了字串
            if(target_count == strlen(modify_content)){ //如果修改的字符串长度与需要的一样
                int modify_count = 0;   //修改内容的计数器
                if(strlen(modify_content) == 1){    //若长度为1
                    content[position] = modify_content[modify_count];
                }
                else {  //修改长度内容不为1
                    for (int i = position - 1;i < position + (strlen(target)) - 1; modify_count++, i++) {
                        //从修改的位置开始遍历
                        content[i] = modify_content[modify_count];   //赋值为需要修改的内容
                    }
                }
            }
            else if(target_count < strlen(modify_content)){ //如果修改的字符串长度大于需要被修改的
                int modify_count = 0;   //修改内容的计数器
                int back_num = strlen(modify_content) - target_count;   //记录需要把字符串向后移动几位
                char temp_front = content[position + target_count - 2];
                char temp_rear; //用于向后平移的temp变量
                for (int j = 0; j < back_num; j++) {   //每次向后平移1位
                    for (int i = position + target_count + j - 1; i <= len + back_num - 1; i++) {   //每次向后移动一位
                        temp_rear = content[i]; //记录后一次的内容
                        content[i] = temp_front;    //赋值front
                        temp_front = temp_rear; //把rear赋值给front，为了下次content赋值
                    }
                }
                content[len + back_num] = '\0'; //将末尾添加结束标识符
                if(strlen(target) == 1){
                    for(int i = position;i <= position + (strlen(modify_content)) - 1;modify_count++,i++){
                        //从修改的位置开始遍历
                        content[i] = modify_content[modify_count];   //赋值为需要修改的内容
                    }
                }
                else {
                    for (int i = position - 1; i < position + (strlen(modify_content)) - 1; modify_count++, i++) {
                        //从修改的位置开始遍历
                        content[i] = modify_content[modify_count];   //赋值为需要修改的内容
                    }
                }
                len += back_num;    //长度加上modify增加的长度
            }
            else{   //如果修改的字符串长度小于需要被修改的
                int modify_count = 0;   //修改内容的计数器
                int front_num = target_count - strlen(modify_content);   //记录需要把字符串向前移动几位
                for(int j = 0;j < front_num;j++) {  //每次向前缩进一个
                    for (int i = position - target_length + strlen(modify_content) +1; i <= len - 2; i++) {
                        content[i] = content[i + 1];  //后一个替换前一个内容
                    }
                }
                content[len - front_num - 1] = '\0';    //将末尾添加结束标识符
                for(int i = position - target_length + 1;i < position - target_length + strlen(modify_content)+ 1;
                    modify_count++,i++){
                    //从修改的位置开始遍历
                    content[i] = modify_content[modify_count];   //赋值为需要修改的内容
                }
                len -= front_num;   //长度减去缩进的长度（替换的字符串短）
            }
        }
    }
    char* substring(int index_begin,int index_end){
        int count = 0;  //result计数器
        char * result = new char((index_end - index_begin));    //动态开辟内存
        for(int i = index_begin;i < index_end;i++){ //遍历，将content的index所在的内容对应赋值给result
            result[count] = content[i];
            count++;    //计数器++，result移到下一个
        }
        return result;  //返回result地址
    }
    void del(char target){  //删除特定字符串
        for(int i = 0;i < len;i++){
            if(content[i] == target){
                for (int j = i; j < len - 1; j++) {
                    content[j] = content[j + 1];  //后一个替换前一个内容
                }
                len--;
                content[len-1] = '\0';
            }
        }
    }
    void insert(int index,char target){ //插入特定字符串
        char temp_front = content[index];
        char temp_rear; //用于向后平移的temp变量
        for (int i = index; i <= len; i++) {   //每次向后移动一位
            temp_rear = content[i]; //记录后一次的内容
            content[i] = temp_front;    //赋值front
            temp_front = temp_rear; //把rear赋值给front，为了下次content赋值
        }
        content[index] = target;    //将目标位置插入需要插入的字符串
        len++;
    }
    String &operator =(String & other){ //对等号进行重载
        content = other.content;    //把other内容赋值给对象
        return *this;
    }
    friend ostream & operator <<(ostream &out,String str);  //ostream友元函数重载
};
ostream & operator <<(ostream &out,String str){
    for(int i = 0;i < str.len -1;i++){  //通过长度进行遍历
        cout<<str.content[i];
    }
    return out;
    //其实可以不需要结束符'\0'，但还是添加了
}

int main() {
    String test("abcdefg");
    cout<<"测试查找字符串功能：查找def"<<endl;
    cout<<test.search("def")<<endl;
    cout<<"取子串功能：（2，4）"<<endl;  //取不到index=4
    cout<<test.substring(2,4)<<endl;
    String test2("aabbccddee");
    cout<<"原字符串："<<endl;
    cout<<test2<<endl;
    cout<<"测试替换长度比被替换长度长的字符串：cc替换为ggggggg"<<endl;
    test2.replace("cc","ggggggg");
    cout<<test2<<endl;
    cout<<"测试替换长度比被替换长度短的字符串：ggggggg替换为c"<<endl;
    test2.replace("ggggggg","c");
    cout<<test2<<endl;
    cout<<"测试替换长度与替换长度等长的字符串：c替换为d"<<endl;
    test2.replace("c","f");
    cout<<test2<<endl;
    cout<<"测试比较功能：(test,test2)"<<endl;
    cout<<test.compare(test2)<<endl;
    cout<<"测试求长度功能：(test)"<<endl;
    cout<<test.length()<<endl;
    cout<<"测试删除字符串特定字符功能：删除c"<<endl;
    test.del('c');
    cout<<test<<endl;
    cout<<"测试插入字符串功能：（index = 3，target = 'z'）"<<endl;
    test.insert(3,'z');
    cout<<test<<endl;
    cout<<"测试字符串的连接："<<endl;
    test.add(test2);
    cout<<test<<endl;
    cout<<"测试深复制功能："<<endl;
    String test3;
    test3.copy(test2);
    cout<<"test2地址："<<&test2<<"  test3地址："<<&test3<<endl;
    return 0;
}