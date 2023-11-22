#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int n;
void dfs(int x,int y,int z,int now){
    if(x<0||y<0||z<0||now==n){
        return;
    }
    if(x+y>z&&x+z>y&&y+z>x){
        ans++;
    }
    now++;
    dfs(x-now,y,z,now);
    dfs(x,y-now,z,now);
    dfs(x,y,z-now,now);
}
int main(){
    int x,y,z;
    cin >> n >> x >> y >> z;
    dfs(x,y,z,0);
    cout << ans << endl;
    return ans;
}

