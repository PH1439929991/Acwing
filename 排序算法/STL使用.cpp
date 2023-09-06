#include<bits/stdc++.h>

using namespace std;

struct node{
    string key;
    int value;
};
struct cmp{
   bool operator()(node &a, node &b){
       return a.value<b.value; 
   }
};
int main(){
    priority_queue<node,vector<node>,cmp> h; 
    node n1;
    n1.key = "192.168.1.9";
    n1.value = 2;
    node n2;
    n2.key = "192.168.1.3";
    n2.value = 3;
    h.push(n1);
    h.push(n2);
    while(!h.empty()){
        cout << h.top().value << endl;
        h.pop();
    }
    return 0;


    
}