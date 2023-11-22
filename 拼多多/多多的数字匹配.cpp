#include<bits/stdc++.h>

using namespace std;

int main(){
    //一串数组
    //1.他们之间差的绝对值大于等于一个特定值
    //2.他们没有出现在其他数字对中，即能匹配出多少个组
    long long n,m;
    cin >> n >> m;
    vector<int> a(n,0);
    long long res = 0;
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<bool> match(n,false);//标记数组
    for(int i = 0 ; i < n ; i++){
        if(match[i]) continue;
        for(int j = 0 ; j < i ; j++){
            if(abs(a[i] - a[j]) >= m && !match[j]){
                res++;
                match[j] = true;
                match[i] = true;
            }
        }
    }
    printf("%lld",res);
    return 0;
}