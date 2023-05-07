#include<bits/stdc++.h>
using namespace std;

int res = 0;
//小明做一道题10分 ，做满100退出 总共30道题
//最终小明得70

//分析
//最后7道题 是肯定做对的 对吧？ 
//23 做错
//我们的自由发挥就是前22个
//2 的 22次方
void dfs(int k,int depth){
    if(depth == 31 ) return; //23返回
    if(k == 70)res++;
     if(k == 90){
         dfs(0,depth+1);
     }
    //两种可能
    dfs(k+10,depth+1);
    dfs(0,depth+1);
}
int main(){
    dfs(0,0);
    cout << res;
    return 0;
}