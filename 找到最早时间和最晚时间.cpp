#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
vector<int> early_time(6,9);
vector<int> last_time(6,0);
bool isRightTime(vector<int> path){
    int s1 = path[0] * 10 + path[1];
    int s2 = path[2] * 10 + path[3];
    int s3 = path[4] * 10 + path[5];
    if(s1 < 24 && s2 < 60 && s3 < 60) return true;
    else return false;
}
void backTrace(vector<int> nums,vector<int>& path,vector<bool>& used){
    if(path.size() == nums.size()){
        if(isRightTime(path)){
            for(int i = 0 ; i < path.size() ; i++){
                if(path[i] > early_time[i]) break;
                if(i == 5)early_time = path;
            }
            for(int i = 0 ; i < path.size() ; i++){
                if(path[i] > last_time[i]){
                    last_time = path;
                    return;
                }
            }
        }
        return;
    }
    for(int i = 0 ; i < nums.size() ; i++){
        if(!used[i]){
            used[i] = true;
            path.push_back(nums[i]);
            backTrace(nums,path,used);
            path.pop_back();
            used[i] = false;
        }
    }
}
int main() {
    vector<int> nums(6);
    for(int i = 0 ; i < 6 ;i++) cin >> nums[i];
    vector<int> path;
    vector<bool> used(6,false);
    backTrace(nums,path,used);
    string s1 = "";
    for(int i = 0 ; i < 6 ; i++){
        if(i>0&&i%2==0) s1+= ":"; 
        s1+=to_string(early_time[i]);
    }
    string s2 = "";
    for(int i = 0 ; i < 6 ; i++){
        if(i>0&&i%2==0) s2+= ":"; 
        s2+=to_string(last_time[i]);
    }
    cout << s1 << " " << s2 <<endl;
}