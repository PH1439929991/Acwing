#include<bits/stdc++.h>
#define N 101
using namespace std;
int n,m;
int v[N];
int main(){
    cin >> n >> m;
    int dp[n+1][m+1];
    for(int i = 0 ;i <= n ; i++) for(int j =0 ;j <= m;j++) dp[i][j] = INT32_MAX;
    for(int i = 0 ;i <= n ; i++) dp[i][0] = 0;
    //代表什么都不取的情况 
    for(int i = 1; i <= n ; i++) cin >> v[i];
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <= m ; j++){
           for(int t = 0 ; t * v[i] <= j ; t++){
                dp[i][j] = min(dp[i][j],dp[i-1][j - t * v[i]] + t);
           }
           cout << dp[i][m] << endl;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}