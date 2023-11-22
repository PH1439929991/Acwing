#include <bits/stdc++.h>
#include <vector>
using namespace std;
int INF = 1e9;
int main() {
    long long n,m;
    cin >> n >> m;
    int minRes = 0;
    int maxRes = 0;
    vector<vector<long>> p(n,vector<long>(4));
    for(int i = 0 ; i < n ; i++){
        cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
        minRes+=p[i][1];
        maxRes+=p[i][3];
    }
    vector<vector<long>> dp(n+1,vector<long>(m+1,INF));
    long res = INF;
    dp[0][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= m ;j++){
            if(j >= p[i-1][0]){
                dp[i][j] = min(dp[i][j],dp[i-1][j-p[i-1][0]] + p[i-1][1]);
            }
            if(j >= p[i-1][2]){
                dp[i][j] = min(dp[i][j],dp[i-1][j-p[i-1][2]] + p[i-1][3]);
            }
            if(dp[i][j]>=minRes&&dp[i][j] <= maxRes && i==n){
                res = min(res,dp[i][j]);
            }          
        }
    }
    if(res == INF) printf("%lld",-1);
    else printf("%lld",res);
    return 0;
}