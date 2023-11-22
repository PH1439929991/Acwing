#include<bits/stdc++.h>
using namespace std;

// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

int main(){
    int n;
    cin >> n;
    int arr[n];
    int res = 0;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    //写个暴力的版本
    for(int i = 0 ; i < n ; i++){
        //向左搜索最后一个大于当前i的高度的下标
        int l = i;
        int curHeight = arr[i];
        while(l>0 && arr[l-1] >= curHeight){
            l--;
        }       
        //向右搜索最后一个大于等于当前curheight的索引
        int r = i;
        while(r < n - 1 && arr[r+1] >= curHeight){
            r++;
        }
        cout << r << " " << l << endl;
        int width = r - l + 1;
        res = max(res,width * curHeight);
    }
    cout << res << endl;
    return 0;
}

int largestRectangleArea(vector<int>& heights) {
    //单调栈问题
    stack<int> stk;
    int ans = 0;
    heights.push_back(-1);//加-1做边界
    for(int i = 0 ; i < heights.size() ; i++){
        while(!stk.empty() && heights[i] < heights[stk.top()]){
            //栈不为空，并且呢？接下来的高度都比我当前小
            int idx = stk.top();stk.pop();
            int left = stk.empty() ? -1: stk.top();
            ans = max(ans,(i - left - 1)*heights[idx]);
        }
        stk.push(i);
    }
        return ans;
}