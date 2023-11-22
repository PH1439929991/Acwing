#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    //n为物品数量 m为背包能承受的最大质量
    int v[n+1],w[n+1];//v为物品的重量 w为物品的价值
    for(int i = 1 ; i <= n ; i++) cin >> v[i] >> w[i];
    int dp[n+1][m+1] = {0};
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(v[i]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}