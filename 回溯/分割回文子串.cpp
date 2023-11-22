#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> res;
vector<string> path;
bool isPalindrome(string s,int startindex,int end){//判断是否为回文子串
    if(startindex>end) return false;
    for(int i = startindex,j = end; i < j ; i++,j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}

void backtrace(string &s,int start){
    if(start>=s.size()){
        res.push_back(path);
        return;
    }
    for(int i = start ; i < s.size() ; i++){
        //substr(start,num) 从start下标开始  剪切从start后num个
        if(isPalindrome(s,start,i)){
            //如果是回文子串
            path.push_back(s.substr(start,i - start + 1));
        }
        else continue;
        backtrace(s,i+1);
        path.pop_back();
    }
}

int main(){
    res.clear();
    string s;
    cin >> s;
    backtrace(s,0);
    for(vector<string> s1 : res){
        for(string s2 : s1){
            cout << s2 << " ";
        }
        cout << endl;
    }
    return 0;
}