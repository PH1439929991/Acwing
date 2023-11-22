#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
int a[N];
int res;

int v(int l,int r){
    int ans = 0;
    int t = 1;
    for(int i = l ; i <= r ; i++){
        ans += t * a[i];
        t++;
    }
    return ans;
}


void backTrace(int indexstart,int n){
    if(indexstart>n) return;
    for(int i = indexstart ; i <= n ; i++){
        res+=v(indexstart,i);
        cout << v(indexstart,i) << endl;
    }
    backTrace(indexstart+1,n);
}

int main(){
    //1 x b1 + 2 x b2 + 3 x b3 + 4 x b4 + ...... + m x bm
    int n = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    backTrace(1,n);
    cout << res << endl;
    return 0;
}