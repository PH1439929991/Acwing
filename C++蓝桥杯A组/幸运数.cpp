#include<iostream>

using namespace std;
int res = 0;
void f(int x,int l,int r){
    if(l==r && l!=0) res++;//left不能为0
    if(x==4) return;
    for(int i = 0; i <= 9 ;i++){
        if( l==0 && i==0) continue;
        for(int j = 0 ; j <= 9 ;j++){
            f(x+1,l+i,r+j);
        }
    } 
}
//<-0->扩展数字模板

int main(){
    //幸运数 2314 === (2+3) == (1+4)
    f(0,0,0);
    cout << res;
    return 0;
}