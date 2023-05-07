#include<iostream>

using namespace std;
int n[11] = {0};
void quick_sort(int n[],int l,int r){
    if( l >= r) return;
    int L = l-1;
    int R = r+1;
    int mid = n[(l+r)/2];
    while(L<R){
        do L++;while(mid>n[L]);
        do R--;while(mid<n[R]);
        if(L<R) swap(n[L],n[R]);
    }
    quick_sort(n,l,R);
    quick_sort(n,R+1,r);
}
int main(){
    for(int i = 0 ; i < 10 ;i++) cin >> n[i];
    quick_sort(n,0,9);
    for(int i = 0 ; i < 10;i++) cout << n[i] << " ";
    return 0;
}

