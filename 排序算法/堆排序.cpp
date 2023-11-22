#include<bits/stdc++.h>

using namespace std;

const int N =  100010;
int n,m,size;
int h[N];
void down(int v){
    int t = v;
    if(v * 2 <= size  && h[v] > h[v*2]) t = v*2;
    if(v * 2 + 1 <= size && h[t] > h[v*2 + 1]) t = v*2+1;
    if(t != v){
        swap(h[t],h[v]);
        down(t);
    } 
}//向下调整
void up(int v){
    //向上调整
    while( v / 2 && h[v/2]>h[v]){
        swap(h[v/2],h[v]);
        v = v/2;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    //从1开始
    for(int i = 1 ; i <= n ; i++) scanf("%d",&h[i]);
    size = n;
    //调整位置
    for(int i = n/2 ; i  ; i--) down(i);
    while(m--){
        printf("%d ",h[1]);
        h[1] = h[size];
        size--;
        down(1);//从第一个位置开始down
    }
    return 0;
}