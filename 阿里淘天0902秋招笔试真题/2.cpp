#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100];
    int m1 = INT_MAX;
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
        m1 = min(m1,a[i]);
    }
    int res = 0;
    sort(a,a+n);
    for(int i = 1; i < n;i++){
        while(a[i]<=a[i-1]){
            res++;
            a[i]++;
        }
    }
    cout << res << endl;
    return 0;
}