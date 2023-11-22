#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    vector<vector<int>> rooms(y,vector<int>());
    int y1 = 0;
    while(y1 < x){
        int t1,t2;
        cin >> t1 >> t2;
        rooms[t1-1].push_back(t2);
        y1++;
    }
    int ans = 0;
    for(vector<int> t : rooms){
        int min1 = INT32_MAX;
        if(t.size()==0) continue;
        for(int i = 0 ; i < t.size() ; i++){
            min1 = min(min1,t[i]); 
        }
        ans += min1;
    }
    cout << ans << endl;
    return 0;
}