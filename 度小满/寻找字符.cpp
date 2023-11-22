#include<bits/stdc++.h>

using namespace std;

int main(){
    int res = 0;
    int k1 = 0;
    int n , k;
    cin >> n >> k;
    string s = "";
    cin >> s;
    int i = 0;
    while(k1 < k){
        i = i%n; 
        if(s[i]=='A') k1++;
        res++;
    }
    cout << res << endl;
    return 0;


}