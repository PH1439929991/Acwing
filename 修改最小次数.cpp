#include<bits/stdc++.h>
using namespace std;

bool isok(vector<bool>& b){
    int j = 0;
    while(j<b.size()){
        if(b[j] == false) return true;
        j++;
    }
    return false;
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> a(n);
    vector<bool> b(n,false);
    int Max_num = 0;
    unordered_map<int,int> counts;
    for(int i = 0 ;i < n ;i++){
        cin >> a[i];
        Max_num = max(Max_num,a[i]);
        counts[a[i]]++;
    }
    for(int i = 0 ; i < n ;i++){
        if(a[i]==Max_num) b[i] = true;
    }
    int max_num = 0;
    int ans = 0;
    while(isok(b)){
        int max_num = 0;
        int v = 0;
        for(const auto& entry : counts){
            if(entry.second > max_num && entry.first != Max_num){
                v = entry.first;
                max_num = entry.second;
            }
        }
        for(int i = 0;i < a.size() ;i++){
            if(a[i] == v) b[i] = true;
        }
        counts[v] = 0;
        ans++;
    }
    cout << ans << endl;
    return 0;
}