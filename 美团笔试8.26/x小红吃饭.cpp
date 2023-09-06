#include<bits/stdc++.h>
#include<set>
using namespace std;
const int K = 20001;
int p[K];//人的个数

int upnum(double x){ //向上取整
    if(x > (int)x) return x + 1;
    return x;
}
int main(){
    int n,m;
    int maxnum = 0;
    cin >> n >> m;
    while(n--){
        double k1,m;
        cin >> k1 >> m;
        unordered_set<int> s1;
        int l = 0;
        for(int i = 0 ; i < k1-1 ;i++){
            cin >> l;
            maxnum = max(l,maxnum);
            s1.insert(l);
        }
        double avg = (double)m / k1;
        int value = upnum(avg);
        for(int t : s1){
            p[t] += value;
        }
    }
    for(int i = 1 ; i <= maxnum ; i++){
        cout << p[i] << " ";
    }
    return 0;
}