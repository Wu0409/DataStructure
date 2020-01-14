//待提高：子串查找使用朴素方式
#include <iostream>
#include <string>
using namespace std;

class String{
private:
    int len;
    char * content;
public:
    String(const char * target = NULL){
        if(target == NULL){ //空串
            len = 0;
        }
        else {
            int count = 0;
            len = strlen(target) + 1;
            content = new char(30);
            for (int i = 0; i < len; i++) {
                content[i] = target[i];
            }
            content[len] = '\0';
        }
    }
    int length(){   //求长度
        return len-1;
    }
    bool isempty(){ //判断串是否为空
        return len == 0;
    }
    void add(String & other){ //字符串的连接
        int need_length = len + other.len -1;
        char * temp = new char(need_length);
        for (int i = 0; i < len-1; i++) {
            temp[i] = content[i];
        }
        for (int i = len-1; i < len + other.len-2; i++) {
            temp[i] = other.content[i-len+1];
        }
        temp[len + other.len-2] = '\0';
        delete content;
        content = temp;
    }
    void copy(String other){
        len = other.len;
        content = new char(len);
        for(int i = 0;i <= len;i++){
            content[i] = other.content[i];
        }
    }
    bool compare(String other){
        if(len != other.len){
            return false;
        }
        else{
            for(int i = 0;i <= len-1;i++){
                if(content[i] != other.content[i]){
                    return false;
                }
            }
            return true;
        }
    }
    int index(char target){
        for(int i = 0;i < len;i++){
            if(target == content[i]){
                return i;
            }
        }
        return -1;
    }
    int search(const char * target){   //子串查找,朴素方式
        int target_length = strlen(target);
        int target_count = 1;
        for(int i = 0;i <= len;i++){
            if(content[i] == target[0]){
                int content_count = i+1;
                while(target_count != target_length){
                    if(content[content_count] != target[target_count]){
                        break;
                    }
                    target_count++;
                    content_count++;
                }
                if(target_count == target_length){
                    return i;
                }
                else{
                    break;
                }
            }
        }
        return -1;
    }
    void replace(char target,char modify_content){
        for(int i = 0;i <= len-1;i++){
            if(content[i] == target){
                content[i] = modify_content;
            }
        }
    }
    String &operator =(String & other){
        content = other.content;
        return *this;
    }
    friend ostream & operator <<(ostream &out,String str);
};
ostream & operator <<(ostream &out,String str){
    cout<<str.len<<endl;
    for(int i = 0;i < str.len -1;i++){
        cout<<str.content[i];
    }
    return out;
}

int main() {
    //子串查找
    String test1("abcdefghijklmn");
    cout<<test1.search("jkl")<<endl;
    String test2("aabbccddee");
    test2.replace('c','g');
    cout<<test2<<endl;

    return 0;
}