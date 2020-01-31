//书本P177
//考察：最短路径
//QUESTION：巡逻机器人

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef struct node{    //记录状态
    int r,c;
    node(int r1 = 0,int c1 = 0,int dir1 = 0):r(r1),c(c1){}
};

int map[4][6] = {{0, 1, 1, 0, 0, 0},
                 {0, 0, 1, 0, 1, 1},
                 {0, 1, 1, 1, 1, 0},
                 {0, 1, 1, 1, 0, 0}};
int dis[4][6];  //-1没有走过
node pre[4][6]; //记录该点前驱，用于回溯
int r0 = 0, c0 = 0; //起点
int r1 = 3, c1 = 5; //终点

bool is_boundry(int r,int c){   //判断是否超出边界
    return r < 4 && c < 6 && r >= 0 && c >= 0;
}

void print_result(node& v){
    //回溯
    vector <node> list;
    list.push_back(v);
    node p,temp = v;
    do{
        p = pre[temp.r][temp.c];
        list.push_back(p);
        temp = p;
    }while(!(temp.c == r0 && temp.r == 0));

    //输出
    char result[4][6];
    memset(result,'o', sizeof(result));
    for(int i = list.size() - 1;i >= 0;i--){
        result[list[i].r][list[i].c] = '*';
    }
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 6;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve(){
    queue <node> q;
    node u(r0,c0);
    dis[r0][c0] = 0;    //起点-长度设置为0
    q.push(u);
    while(!q.empty()){
        node v = q.front(); q.pop();
        if(v.r == r1 && v.c == c1){ //到达终点
            print_result(v);
        }
        if(is_boundry(v.r + 1,v.c) && dis[v.r + 1][v.c] == -1){   //判断是否可以向上
            if(map[v.r + 1][v.c] == 1 && map[v.r + 2][v.c] == 0 &&
               dis[v.r + 2][v.c] == -1 && is_boundry(v.r + 2,v.c)){
                //上面是障碍，但在上面一个不是障碍，可以翻过去,且没有走过
                node temp(v.r + 2,v.c); //记录状态
                dis[v.r + 2][v.c] = dis[v.r][v.c] + 1;
                pre[v.r + 2][v.c] = v;
                q.push(temp);
            }
            if(map[v.r + 1][v.c] == 0){
                node temp(v.r + 1,v.c); //记录状态
                dis[v.r + 1][v.c] = dis[v.r][v.c] + 1;
                pre[v.r + 1][v.c] = v;
                q.push(temp);
            }
        }
        if(is_boundry(v.r,v.c + 1) && dis[v.r][v.c + 1] == -1){   //判断是否可以向右
            if(map[v.r][v.c + 1] == 1 && map[v.r][v.c + 2] == 0 &&
               dis[v.r][v.c + 2] == -1 && is_boundry(v.r,v.c + 2)){
                node temp(v.r,v.c + 2); //记录状态
                dis[v.r][v.c + 2] = dis[v.r][v.c] + 1;
                pre[v.r][v.c + 2] = v;
                q.push(temp);
            }
            if(map[v.r][v.c + 1] == 0){
                node temp(v.r,v.c + 1); //记录状态
                dis[v.r][v.c + 1] = dis[v.r][v.c] + 1;
                pre[v.r][v.c + 1] = v;
                q.push(temp);
            }
        }
        if(is_boundry(v.r -1,v.c) && dis[v.r - 1][v.c] == -1){   //判断是否可以向下
            if(map[v.r - 1][v.c] == 1 && map[v.r - 2][v.c] == 0 &&
               dis[v.r - 2][v.c] == -1 && is_boundry(v.r - 2,v.c)){
                node temp(v.r - 2,v.c); //记录状态
                dis[v.r - 2][v.c] = dis[v.r][v.c] + 1;
                pre[v.r - 2][v.c] = v;
                q.push(temp);
            }
            if(map[v.r - 1][v.c] == 0){
                node temp(v.r - 1,v.c); //记录状态
                dis[v.r - 1][v.c] = dis[v.r][v.c] + 1;
                pre[v.r - 1][v.c] = v;
                q.push(temp);
            }
        }
        if(is_boundry(v.r,v.c - 1) && dis[v.r][v.c - 1] == -1){   //判断是否可以向左
            if(map[v.r][v.c - 1] == 1 && map[v.r][v.c - 2] == 0 &&
               dis[v.r][v.c - 2] == -1 && is_boundry(v.r,v.c - 2)){
                node temp(v.r,v.c - 2); //记录状态
                dis[v.r][v.c - 2] = dis[v.r][v.c] + 1;
                pre[v.r][v.c - 2] = v;
                q.push(temp);
            }
            if(map[v.r][v.c - 1] == 0){
                node temp(v.r,v.c - 1); //记录状态
                dis[v.r][v.c - 1] = dis[v.r][v.c] + 1;
                pre[v.r][v.c - 1] = v;
                q.push(temp);
            }
        }
    }
}


int main() {
    memset(dis,-1,sizeof(dis));
    solve();
    return 0;
}