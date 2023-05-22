#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "input the n" << endl;
    cin >> n;
    vector<int> candyVec(n,1);
    vector<int> ratings(n);
    cout << "Input the ratings" << endl;
    for(int i = 0 ; i < n;i++){
        cin >> ratings[i];
    } 
    //从前退后
    for(int i  = 1; i < ratings.size() ; i++){
        if(ratings[i] > ratings[i-1]){            
            candyVec[i] = candyVec[i-1] + 1;
        }
    }
    //从后往前
    for(int i = n - 2 ; i >= 0 ; i--){
        if(ratings[i] > ratings[i+1]){
            candyVec[i] = max(candyVec[i],candyVec[i+1] + 1);
        }
        cout << candyVec[i] << " " ;
    }
    //统计结果
    int result = 0;
    for(int i = 0; i < candyVec.size() ; i++) result += candyVec[i];
    cout << result << endl;
    return 0;
}