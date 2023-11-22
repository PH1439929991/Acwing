#include<bits/stdc++.h>
using namespace std;
int main(){
  //vector<int> a;
  vector<bool> used(100,false);//如果走过则改为true
  //for(int i = 1 ; i <= 100 ;i++) a.push_back(i);
  int num = 100;
  int j = 1;
  int cur = 1;
  while(num>1){
    //如果当前此人已经退出
    if(used[j-1]){
      j++;
      if(j==101) j = 1;
    }
    else{
      //如果此人未退出
      if(cur%3==0){
        //并且口号是3 则退出
        num--;
        cur=1;
        used[j-1] = true;//表示已经走过
        cout << j << endl;
      }
      else{
        //此人的口号不是3 是1 2 
        cur++;
      }
      j++;
      if(j==101) j = 1;
    }
  }
  for(int i = 0 ; i < 100 ; i++){
    if(!used[i]) cout << i + 1 << endl;
  }
  return 0;
}