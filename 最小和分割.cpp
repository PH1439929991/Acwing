#include<bits/stdc++.h>

using namespace std;

int splitNum(int num) {
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num = num/10;
        }
        sort(v.begin(),v.end());
        string s1 = "",s2 = "";
        int flag = 1;
        for(int i : v){
            if(flag==1){
                s1 += i + '0';
                flag=-flag;
            }else{
                s2 += i + '0';
                flag=-flag;
            }
        }
        return stoi(s1) + stoi(s2);
    }

int main(){
    int num = 0;
    cin >> num;
    cout << splitNum(num) << endl;
    return 0;
}