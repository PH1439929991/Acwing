#include<bits/stdc++.h>
const int N = 205;
using namespace std;

int p[N],size[N];
int find(int x){
    if(p[x]!=x) x=p[x];
    return p[x];
}
int main(){
    int n , m;
    cin >> n;
    cin >> m;
    for(int i = 0 ; i < n ; i++) p[i] = i;
    while(m--){
        int x1,x2;
        cin >> x1 >> x2;
        p[find(x1)] = find(x2);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(p[i]==i) ans++;
    }
    cout << ans << endl;
    return 0;
}