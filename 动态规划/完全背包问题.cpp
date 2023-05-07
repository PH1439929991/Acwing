#include<bits/stdc++.h>

using namespace std;
const int N = 1005;
int dp[N][N] = {0};
int v[N],w[N];
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n; i++) cin >> v[i] >> w[i];   
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1 ; j <= m ; j++){
    //         dp[i][j] = dp[i-1][j];
    //         if(j >= v[i]){
    //                 for(int k = 0 ; k*v[i]<=j ; k++ ){
    //                 dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
    //             }
    //        }
    //     }
    // }
    //我们可以在优化
    //f[i][j] = max(f[i-1][j],f[i-1][j-1*v]+1*w,f[i-1][j-2*v]+2*w........) ->1
    //f[i][j-v] = max(f[i-1][j-v],f[i-1][j-2*v]+w,f[i-1][j-3*v]+2*w......) ->2
    //2+w  ->  f[i][j-v]+w -> (f[i-1][j-1*v]+1*w,f[i-1][j-2*v]+2*w........)
    //f[i][j] = f[i-1][j]
    //他就能优化成f[i][j] = max(f[i][j],f[i][j-v]+w)
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dp[i][j] = dp[i-1][j];
            if(v[i]<=j){
                dp[i][j] = max(dp[i][j],dp[i][j-v[i]]+w[i]);
            }
        }
    }
    
    

    cout << dp[n][m];
    return 0;
}