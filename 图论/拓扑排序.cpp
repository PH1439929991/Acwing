#include<iostream>
#include<cstring>

using namespace std;
const int N = 500;
int h[N];
int e[N*2];
int ne[N*2];
int q[N],d[N];
int idx = 0;
int n;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool topsort(){
    int hh = 0 , tt = -1;
    for(int i = 1 ; i <= n;i++){
        if(!d[i]) q[++tt] = i;
    }
    while(hh<=tt){
        int t = d[hh++];
        for(int i = h[t] ; i!=-1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(dp[j]==0) q[++tt] = j;
        }
    }

    return tt == n -1;
}

int main(){

}