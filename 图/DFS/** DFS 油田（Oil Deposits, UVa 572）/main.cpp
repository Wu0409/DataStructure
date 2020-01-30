//书本：P162
//考察：图 - DFS（深度遍历）
//QUESTION: 油田

//备注：每次访问到一个格子给他写上连通分量编号（idx数组），可以在访问之前检查它是否已经有了编号，从而避免同一个格子访问多次

#include <iostream>
using namespace std;
int m = 5, n = 5;
int idx[5][5];
char input[5][5] = {{'*','*','*','*','@'},
                    {'*','@','@','*','@'},
                    {'*','@','*','*','@'},
                    {'@','@','@','*','@'},
                    {'@','@','*','*','*'}};   //样例输入

void dfs(int r, int c,int id){
    if(r < 0 || r > m || c < 0 || c >= n)   return; //超出边界
    if(idx[r][c] || input[r][c] != '@') return;
    idx[r][c] = id; //连通分量编号
    for(int dr = -1;dr <= 1;dr++){
        for(int dc = -1;dc <= 1;dc++){
            if(dr != 0||dc != 0){   //(r+dr(0),r+dc(0)) - 就是自己
                dfs(r+dr,c+dc,id);  //同一个编号，因为是相连的，是同一个八连块
            }
        }
    }

}
int main() {
    int cnt = 0;    //编号
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            if(idx[i][j] == 0 && input[i][j] == '@'){
                dfs(i,j,++cnt); //每个循环说明一个深度遍历完毕，没有相连的了，是新的八连块
            }
        }
    }
    cout<<"The number of connected components:"<<cnt<<endl;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cout<<idx[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}