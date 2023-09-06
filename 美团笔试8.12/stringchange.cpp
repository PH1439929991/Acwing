#include<bits/stdc++.h>
#include <vector>
using namespace std;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
const int N = 1100;
void dfs(vector<string> s,vector<vector<bool>> flag,int x,int y){
    if(x<0||x>=s.size()||y<0||y>=s[0].size()){
        return;
    }
    else{
        flag[x][y] = true;
        for(int i = 0 ; i < 4 ; i++){
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if(s[x1][y1]==s[x][y]&&!flag[x1][y1]){
                dfs(s,flag,x1,y1);
            }
        }
        return;
    }
}

int fun(vector<string> s){
    int num = 0;
    int n = s.size();
    int m = s[0].size();
    vector<vector<bool>> flag(n,vector<bool>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(!flag[i][j]){
                num++;
                dfs(s,flag,i,j);
            }
        }
    }
    return num;
}

int main(){
    vector<string> s;
    s.push_back("ab");
    s.push_back("aa");
    s.push_back("ba");
    s.push_back("ba");
    cout << fun(s);
    return 0;
}