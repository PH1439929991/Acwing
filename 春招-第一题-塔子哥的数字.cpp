#include<bits/stdc++.h>
#include <string>
using namespace std;

long fun(long a,long b){
    if(b==0){
        string res = to_string(a) + '0'; 
        return stoi(res);
    } 
    string t = to_string(a);
    char c = '0' + b;
    for(int i = 0 ; i < t.size() ; i++){
        if(c>t[i]){
            t.insert(i+1,1,c);
            return stoi(t);
        }
    }
    return stoi(t + c);
}
int main(){
    long n = 0; 
    cin >> n;
    long a;
    long b;
    while(n--){
        cin >> a >> b;
        cout << fun(a,b) << endl;
    }
    return 0;
}