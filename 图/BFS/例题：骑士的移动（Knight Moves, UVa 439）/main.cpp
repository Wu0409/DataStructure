//书本P177
//考察：BFS
//QUESTION：骑士的移动
//备注：虽然没有说不可以重复走，但是你走到过走过的地方，必然前面有更短的路径到这里

#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
typedef struct node{
    int r,c;
    node(int r1 = 0,int c1 = 0):r(r1),c(c1){}
};

int Distance[8][8]; //距离
node pre[8][8];
map <int,node> direction;
int r0 = 7,c0 = 0;  //起点
int r1 = 6,c1 = 1;  //终点

void create_move(){ //将马的几种移动方式，转换为映射关系，顺时针
    node temp;
    temp.r = -2;    temp.c = 1;  direction[0] = temp;
    temp.r = -1;    temp.c = 2;  direction[1] = temp;
    temp.r = 1;     temp.c = 2;  direction[2] = temp;
    temp.r = 2;     temp.c = 1;  direction[3] = temp;
    temp.r = 2;     temp.c = -1; direction[4] = temp;
    temp.r = 1;     temp.c = -2; direction[5] = temp;
    temp.r = -1;    temp.c = -2; direction[6] = temp;
    temp.r = -2;    temp.c = -1; direction[7] = temp;
}
bool is_boundary(int r,int c){
    return r < 8 && c < 8 && r > 0 && c > 0;
}

void print_result(node u){
    vector <node> list;
    int result[8][8];
    memset(result,0,sizeof(result));
    node temp = u;
    list.push_back(temp);
    while(1){
        if(temp.r == r0 && temp.c == c0){
            break;
        }
        node p = pre[temp.r][temp.c];
        list.push_back(p);
        temp = p;
    }
    int count = 1;  //显示这是第几步
    for(int i = list.size() - 1;i >= 0;i--){
        result[list[i].r][list[i].c] = count;
        count++;
    }
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"共需要："<<count - 2<<"步！"<<endl;
}
void solve(){
    queue <node> q;
    node u(r0,c0);
    q.push(u);
    while(!q.empty()){
        node u = q.front(); q.pop();
        if(u.r == r1 && u.c == c1){
            print_result(u);
            return;
        }
        for(int i = 0;i <= 7;i++){  //8种移动方式
            node move = direction[i];
            node v(u.r + move.r, u.c + move.c);
            if(is_boundary(v.r,v.c) && Distance[v.r][v.c] == -1){
                pre[v.r][v.c] = u;
                Distance[v.r][v.c] = Distance[u.r][u.c] + 1;
                q.push(v);
            }
        }
    }
}



int main() {
    cout<<"输入起始位置(0 - 7)"<<endl;
    cin>>r0>>c0;
    cout<<"输入终点位置(0 - 7)"<<endl;
    cin>>r1>>c1;
    r0 = 7 - r0;
    r1 = 7 - r1;
    memset(Distance,-1, sizeof(Distance));
    create_move();
    solve();
    return 0;
}