#include<bits/stdc++.h>

using namespace std;
const int N = 50;
char graph[N][N] = {'0'};
int graph1[N][N] = {0};
int n;
char dir[4] = {'z','r','s','x'};
int dir1[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
vector<char> path;
//创建地图 .可走 #不可走

void DFS(int startx,int starty){
    if(startx == n-1&&starty == n-1){
        for(int i = 0 ; i < path.size() ;i++){
            cout << path[i];
        }
        return;
    }
    else{
        for(int i = 0 ; i < 4;i++){
            int x = startx + dir1[i][0];
            int y = starty + dir1[i][1];
            if(x>=0&&x<n&&y>=0&&y<n&&graph[x][y]!='#'&&graph1[x][y]!=1){
                path.push_back(dir[i]);
                graph1[x][y] = 1;
                DFS(x,y);
                path.pop_back();
                graph[x][y] = 0;
            }
        }
        return;
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j < n ; j++){
            cin>>graph[i][j];
        }
    }
    DFS(0,0);
    return 0;
}
