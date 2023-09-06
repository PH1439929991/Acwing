// 给一个长度为n的数组a，请计算出有多少个四元组(i,j,k,l)满足ai+aj=ak@al(i<j<k<l)?(@表示按位异或)
// 答案可能太大，请对10^9+7取模后再输出。

// 输入描述
// 第一行一个正整数n。
// 第二行n个正整数ai。
// 1<=n<=10^4
// 1<=ai<=100
// 输出描述
// 一个整数，表示答案对10^9+7取模。
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    ll mod = 1e9 + 7, ans = 0;
    vector<vector<ll>> sum(n, vector<ll>(201, 0));
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1];
        for (int j = 0; j < i; ++j) {
            int s = arr[i] + arr[j];
            sum[i][s] += 1;
        }
    }
    for (int k = 2; k < n; ++k) {
        for (int l = k + 1; l < n; ++l) {
            int o = arr[k] ^ arr[l];
            ans = (ans + sum[k - 1][o]) % mod;
        }
    }
    cout << ans;
}