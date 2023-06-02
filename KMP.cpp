#include<bits/stdc++.h>
#include<iostream>
#define Max 50
using namespace std;
void getNext(int *next,string str1){
    for(int i = 1 ; i < str1.size() ; i++){
        for(int l = 0,r = i;l < r ;l++,r--){
            if(str1[l] == str1[r]) next[i]++;
            else break;
        }
    }
}
int KMP(int *next,string str,string str1){
    if(str1.size()==0) return -1;
    for(int i = 0 ; i < str1.size() ;i++) cout << next[i] << " ";
    int j = -1;//因为next数组里记录的起始位置为-1
    for(int i = 0 ; i < str.size() ; i++){
        while(j > 0  && str[i]!=str1[j+1]){ //前后缀不相同了
            j = next[j];//向前回退
        }
        if(str[i]==str1[j+1]){
            j++;
        }
        if(j == str1.size() - 1){
            return i - str1.size() + 1;
        }
    }
    return -1;
}
int main(){
    string str,str1;//str是主段 str1是复段
    cout << "Input the Str" << endl;
    cin >> str;
    cout << "Input the Str1" << endl;
    cin >> str1;
    int next[str1.size()];
    memset(next,-1,sizeof(int)*str1.size());
    getNext(next,str1);
    cout << KMP(next,str,str1) <<endl;
    return 0;
}