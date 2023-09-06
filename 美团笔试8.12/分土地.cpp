#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
#define N 1500
int dp[N][N];
int values[N][N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m ;j++){
            cin >> values[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + values[i][j]; 
        }
    }
    int res = INT32_MAX;
    //一刀切
    //现在横着切
    for(int i = 1 ; i <= n ; i++){
        int diff = abs(2*dp[i][m]-dp[n][m]);
        res = min(res,diff); 
    }
    //竖着切
    for(int i = 1 ; i <= m ; i++){
        int diff = abs(2*dp[n][i] - dp[n][m]);
        res = min(res,diff); 
    }
    cout << res << endl;
    return 0;
}