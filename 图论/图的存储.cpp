#include<iostream>
#include <cstring>
using namespace std;

const int N = 501;
const int M = N * 2;
int h[N];//头结点的链表
int e[M];//存边
int ne[M];//下一个点
int q[N],d[N];//入度
int n,m;
int idx = 0;


void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort(){
    int hh = 0 ,tt = -1;//t对头 h是队�?
    for(int i = 1 ; i <= n ;i++){
        if(!d[i]) q[++tt] = i;//入度不为0 加入队列
    }

    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t] ; i != -1 ; i = ne[i]){
            int j = e[i];//拿到边的终点 a->b  b是终�?
            d[j]--;
            if(d[j]==0) q[++tt] = j;//入队;
        } 
    }
    return tt == n - 1;
}

int main(){
    memset(h,-1,sizeof h);//初始化为-1
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b);
        d[b]++;
    }    

    if(topsort()){
        cout << "sort:" << endl;
        for(int i = 0 ; i < n ; i++){
            cout << q[i] << " ";
        }
    }else cout << "-1";

    return 0;
}