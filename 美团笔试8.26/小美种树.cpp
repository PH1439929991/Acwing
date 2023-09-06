#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int num = 0;
    int time = 0;
    while(num<k){
        if(time % 3 == 0) num+=(n+m);
        else num+=n;
        time++;
    }
    cout << time << endl;
    printf("%lld",time);
    return 0;
}