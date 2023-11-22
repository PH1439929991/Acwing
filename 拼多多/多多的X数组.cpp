#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    long long  n;
    cin >> n;
    vector<vector<long long>> s(n,vector<long long>(3,0));
    for(int i = 0 ; i < n ; i++){
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
    
    // for(long long i = 0 ; i < n;i ++){
    //     int num = (1+(s[i][0]-1))*(s[i][0]-1) / 2;
    //     if(s[i][2] - s[i][1] > num){
    //         cout << "YES" << endl;
    //     }
    //     else cout << "NO" << endl;
    // }
    return 0;
}