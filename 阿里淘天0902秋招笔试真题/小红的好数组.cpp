// 小红定义一个数组是“好数组”，当且仅当满足以下三个条件:
// 1.对于l<=i<=n，有1<=ai<=m
// 2.对于1<=i<=n，保证ai是i的倍数。
// 3.a1+a2+...+an是n的倍数。
// 现在给你n和m，请你求出满足条件的“好数组”数量。由于答案可能过大，请对10^9+7取模。

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

int n, m;
ll mod = 1e9 + 7;
ll memo[1005][1005];

ll helper(int i, int sum) {
    if (i > n) return sum == 0;
    if (memo[i][sum] != -1) return memo[i][sum];
    ll ans = 0;
    // 当前位置的选择
    for (int a = i; a <= m; a += i) {
        ans = (ans + helper(i + 1, (sum + a) % n)) % mod;
    }
    return memo[i][sum] = ans;
}

int main () {
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    ll ans = helper(1, 0);
    cout << ans;
}