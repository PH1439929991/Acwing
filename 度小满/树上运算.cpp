#include<bits/stdc++.h>
using namespace std;
int p[50000];
int c[50000];
int n;
int main(){
    cin >> n; 
    //1是蓝色，2是红色
    vector<int> v(n+1,1);
    for(int i = 2 ; i <= n;i++) cin >> p[i]; //0是父节点 1 2 3 4  
    for(int i = 1 ; i <= n ; i++) cin >> c[i];
    //需要从后往前
    for(int i = n ; i >= 2 ;){
        if(p[i]==p[i-1]){
            int node = p[i];
            if(c[node] == 1){
               v[node] = v[i] + v[i-1];
            }
            else{
               v[node] = v[i] * v[i-1]; 
            }
            i-=2;
        }
        else{
            i--;
        }
    }
    cout << v[1] <<endl;
    return 0;
}