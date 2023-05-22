#include<bits/stdc++.h>

using namespace std;
//力扣题目链接：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/

bool cmp(int a,int b){
    return abs(a)>abs(b);
}

int main(){
    int K,n,result = 0;
    vector<int> nums;
    cin >> K >> n;
    cout << " -- " << endl;
    for(int i = 0 ; i < n ;i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    sort(nums.begin(),nums.end(),cmp);//从大到校排序  按照绝对值
    for(int i = 0 ; i < n;i++){
        if(nums[i] < 0 && K > 0){
            K--;
            nums[i] = nums[i]*-1;
        }
    }
    //有个地方很关键
    //如果遍历结束 如果K还大于0，那么反复转变数值最小的元素，将K用完
    if(K%2==1) nums[nums.size() - 1] *= -1;
    for(int a : nums) result += a;
    cout << result << endl;
    return 0;
}