//书本P165
//考察：BFS
//QUESTION：用BFS求最短路

#include <iostream>
#include <queue>
typedef struct Next{
    int r,c;
    Next(int r1 = 0,int c1 = 0):r(r1),c(c1){}
};
using namespace std;
int Distance[6][5];
const int map[6][5] = {  {1, 1, 0, 1, 1},
                         {1, 0, 1, 1, 1},
                         {1, 0, 1, 0, 0},
                         {1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {1, 1, 1, 1, 1}};
int r0 = 0, c0 = 0;

bool is_inside(int r,int c){
    return r <= 5 && c <= 4 && r >= 0 && c >= 0;
}

void solve(){
    queue <Next> q;
    memset(Distance, -1, sizeof(Distance));
    Next start(r0,c0);    //起点
    Distance[r0][c0] = 0;   //起点距起点为0
    q.push(start);
    while(!q.empty()){
        Next u = q.front(); q.pop();
        for(int i = -1;i <= 1;i += 2){  //上下
            Next v(u.r + i,u.c);
            if(is_inside(v.r,v.c) && map[v.r][v.c] != 0 && Distance[v.r][v.c] == -1){
                Distance[v.r][v.c] = Distance[u.r][u.c] + 1;    //距离+1
                q.push(v);
            }
        }
        for(int i = -1;i <= 1;i += 2){  //左右
            Next v(u.r,u.c + i);
            if(is_inside(v.r,v.c) && map[v.r][v.c] != 0 && Distance[v.r][v.c] == -1){
                Distance[v.r][v.c] = Distance[u.r][u.c] + 1;    //距离+1
                q.push(v);
            }
        }
    }
}

int main() {
    cout<<"设置初始点："<<endl;
    cin>>r0>>c0;
    solve();
    for(int i = 0;i <= 5;i++){  //输出
        for(int j = 0;j <= 4;j++){
            cout<<Distance[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}