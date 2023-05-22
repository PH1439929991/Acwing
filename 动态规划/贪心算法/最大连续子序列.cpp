#include<bits/stdc++.h>

using namespace std;

int main(){
    int counts = 0;//窗口和
    int result = INT32_MIN;//32位最小的数字
    vector<int> nums;
    int n;
    for(int i = 0; i < 8;i++){
        cin >> n;
        nums.push_back(n); 
    }

    for(int i = 0 ; i < nums.size(); i++){
        counts+=nums[i];
        if(result<counts) result = counts;
        if(counts <= 0) counts = 0;
    }
    cout << result << endl;
    return 0; 
}
