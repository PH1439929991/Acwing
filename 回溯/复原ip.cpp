#include<bits/stdc++.h>
using namespace std;
vector<string> res;
//判断是否合法Ip

bool isvalid(const string& s,int start,int end){
    if(start > end){
        return false;
    }
    if(s[start] == '0' && start!=end){
        return false;
    }
    int num = 0;
    for(int i = start ; i <= end ; i++){
        if(s[i] > '9' || s[i] < '0'){
            return false;
        }
        num = num * 10 + (s[i] - '0');
        if(num>255) return false;
    }
    return true;
}

void backtrace(string &s,int start,int pos){
    if(pos == 3){
        if(isvalid(s,start,s.size() - 1)){
            res.push_back(s);
            return;
        }
    }
    for(int i = start ; i < s.size() ; i++){
        if(isvalid(s,start,i)){
            s.insert(s.begin() + i + 1,'.');
            pos++;
            backtrace(s,i+2,pos);
            pos--;
            s.erase(s.begin()+i+1);
        }else break;
    }
}

int main(){
    string s = "";
    cin >> s;
    res.clear();
    backtrace(s,0,0);
    for(string s : res){
        cout << s << endl;
    }
    return 0;
}