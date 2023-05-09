#include<bits/stdc++.h>

using namespace std;
const int N = 60;
int a[N];
int n;
//leetcode https://leetcode.cn/problems/jump-game-ii/submissions/ 
//45 跳跃问题2
int f(int n){
    if(n==0) return 0;
    int ans = 0;  //当前最少的跳跃次数
    int curDistance = 0;  //当前范围内的最远距离
    int nextDistance = 0; //下一次跳跃的最远距离
    for(int i = 0 ; i < n;i++){
        nextDistance = max(nextDistance,i+a[i]);
        if(i==curDistance){ //已经达到当前最远的跳跃距离
            if(curDistance!=n - 1){
                ans++;
                curDistance = nextDistance;
                if(curDistance >= n-1) break;
            }else break;
        }
    }
    return ans;
}

int main(){
    //输出最少的跳跃次数
    cin >> n;
    for(int i = 0 ;i < n;i++) cin>>a[i];
    cout << f(n);
    return 0;
}