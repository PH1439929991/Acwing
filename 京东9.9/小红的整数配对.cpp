#include<bits/stdc++.h>
using namespace std;

const int N = 100001;

int main(){
    int n,k;
    int a[N];
    bool b[N];
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    int ans = 0;
    for(int i = 0 ; i < n - 1;){
        if(a[i]-a[i+1]<=k){
            ans+=a[i+1]*a[i];
            i+=2;
        }
        else i++;
    }
    cout << ans << endl;
    return 0;
}


