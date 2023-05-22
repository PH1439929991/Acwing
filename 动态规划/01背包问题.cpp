// 有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
// 第 i 件物品的体积是 v[i]
// ，价值是 w[i]
// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
// 输出最大价值。

// 第一行两个整数，N，V ，用空格隔开，分别表示物品数量和背包容积。
// 接下来有 N 行，每行两个整数 vi,wi ，用空格隔开，分别表示第 i件物品的体积和价值。

#include<iostream>

using namespace std;
const int N = 100;
int dp[N][N] = {0};

int n,m;
int v[N],W[N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i] >> W[i];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m; j++){
            if(j>=v[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+W[i]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}