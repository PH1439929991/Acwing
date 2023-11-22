#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> ans;
bool col[20],dg[20],udg[20];
vector<string> s;
void dfs(int u,int n){
    if(n == u){
        ans.push_back(s);
        return;

    }
    for(string t : s){
        cout << t << endl;
    }
    for(int i = 0 ; i < n ; i++){
        if(!col[i] && !dg[i+u] && !udg[n - u + i]){
            s[u][i] = 'Q';
            col[i] = dg[i+u] = udg[n - u + i] = true;
            dfs(u+1,n);
            col[i] = dg[i+u] = udg[n - u + i] = false;
            s[u][i] = '.';
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n) {
    for(int i = 0 ; i < n ;i++){
        string s1 = "";
        for(int j = 0 ; j < n ; j++){
            s1 += '.';
        }
        s.push_back(s1);
    }
    for(string t : s){
        cout << t << endl;
    }
    dfs(0,n);
    return ans;
}
int main(){
    int m;
    cin >> m;
    vector<vector<string>> res = solveNQueens(m);
    for(vector<string> s: res){
        for(string t : s){
            cout << t << endl;
        }
        cout << " " << endl;
    }
}