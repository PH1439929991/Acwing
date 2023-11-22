#include<bits/stdc++.h>

using namespace std;
int N = 10001;
int n= 0;
int main(){
    int n = 0;
    cin >> n;
    while(n--){
        unordered_map<char,char> m; 
        string s1,s2;
        bool flag = false;
        cin >> s1 >> s2;
        for(int i = 0 ; i < s1.size() ; i++){
            if(m.find(s1[i])==m.end()){
                m[s1[i]] = s2[i]; 
            }
            else{
                if(m[s1[i]]!=s2[i]){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}