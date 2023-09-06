#include<bits/stdc++.h>

using namespace std;

int upnum(double x){
    if(x > (int)x) return x + 1;
    else return x;
}

int main(){
    double x = (double)10 / 3;
    cout << upnum(x) << endl;
}