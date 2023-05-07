#include<bits/stdc++.h>

using namespace std;
const int N = 11;
vector<int> edge[N];//结点
int in[N] = {0};//入度 
int len = 0;
int main(){
    cin >> len;
    int n;
    cout << "Input 0 exit" << endl;
    while(cin >> n){
        if(n==0) break;
        else{
            int node;
            while(cin >> node){
                if(node == -1) break;
                if(node == n) continue;
                edge[n].push_back(node); 
                in[node]++;  
            }
        }
    }
    for(int i = 1 ; i <= len ;i++){
        cout << in[i] << " ";
    }
    cout << endl;
    //创图过程
    priority_queue<int,vector<int>,greater<int>> q;//小顶堆
    for(int i = 1 ; i <= len ; i++){
        if(in[i] == 0) q.push(i);
    }
    //初始化
    vector<int> ans;
    while(!q.empty()){
        int p = q.top();
        q.pop();
        ans.push_back(p);
        cout << p << " ";
        for(int i = 0 ; i < edge[p].size();i++){
            in[edge[p][i]]--;
            if(in[edge[p][i]]==0){
                q.push(edge[p][i]);
            }
        }
    }
    cout << "Ans:" << endl;
    if(ans.size() == len){
        for(int i = 0 ; i < len; i++){
            cout << ans[i] << " ";
        }
    }
    else{
        cout << "not find the path" << endl;
    }
    return 0;
}