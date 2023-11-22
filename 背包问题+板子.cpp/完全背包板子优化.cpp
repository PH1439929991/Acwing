#include<bits/stdc++.h>

using namespace std;

int main(){
    //零钱相加
    int n,m;
    cin >> n >> m;
    int v[n+1],w[n+1];
    for(int i = 1 ; i <= n ; i++) cin >> w[i] >> v[i];
    int dp[m+1] = {0};
    for(int i = 1; i <= n ; i++){
        for(int j = w[i] ; j <= m; j++){
            dp[j] = max(dp[j],dp[j -w[i]]+v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}