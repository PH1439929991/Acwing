// 给定一个数组[1,2,3,4,5,6]，以及滑动窗口的长度N
// ，这个滑动窗口从左往右移动，请按顺序输出每个窗口中的最大值

#include<bits/stdc++.h>

using namespace std;
deque<int> q1;

void pop1(int t){
    if(!q1.empty() && t == q1.back()) q1.pop_back();
}

void push1(int n){
    //单调递减
    while(!q1.empty()&& n > q1.front()){
        q1.pop_front();
    }
    q1.push_front(n);
}

int getMax(){
    if(!q1.empty()) return q1.back();
    return -1;
}

int main(){
    int n,k;
    vector<int> ans;
    vector<int> nums;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int t = 0;
        cin >> t;
        nums.push_back(t);
    }
    for(int i = 0 ; i < k ; i++){
        push1(nums[i]);
    }
    ans.push_back(getMax());
    for(int i = k ; i < n ; i++){
        pop1(nums[i-k]);
        push1(nums[i]);
        ans.push_back(getMax());
    }
    for(int a : ans){
        cout << a << " ";
    }
    return 0;
}


