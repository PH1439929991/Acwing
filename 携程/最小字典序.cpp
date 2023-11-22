#include<bits/stdc++.h>

using namespace std;
int N = 10001;
int n= 0;
bool is(vector<int> v,vector<int> v0){
    for(int i = 0 ; i < v.size() i++){
        if(v[i]==v0[i]) return false;
    }
    return true;
}

void next(vector<int>& nums,int numsize){
    int i = numsize - 2;
    for(int i >= 0 && nums[i] >= nums[i+1]) i--;
    if(i >= 0){
        int j = numsize - 1;
        while(j >= 0 && nums[i] == nums[j]) j--;
        swap(nums+i,nums+j);
    }
    reverse(nums,i + 1, numsize - 1);
}
int main(){
    cin >> n;
    vector<int> v(n,0);
    for(int i = 0 ;i < n ;i++) cin >> v[i];
    next(v,v.size());
    for(int i = 0 ; i< v.size() ;i++) cout << v[i] << " ";
    // while(1){

    // }
    // return 0;
}