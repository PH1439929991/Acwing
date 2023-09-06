#include<bits/stdc++.h>

using namespace std;
int v[5] = {2,1,3,5,4};
int x2;
int y2;//每次变化最大的数
int ai1,aj1;//每次变化最大的下标

int main(){
    int num = 0 ;
    int v[5] = {2,1,3,5,4};
    int n = 5;
    sort(v,v+n);
    for(int i = 0 ; i < 2 ;i++){
        sort(v,v+n);
        int num = v[n-1] * v[n-2];
        v[n-1] = num;
        v[n-2] = 1;
    }
    for(int i = 0;i < n;i++){
        num+=v[i];
    }
    cout << num << endl;
    return 0;
}