#include<bits/stdc++.h>

using namespace std;
//力扣题目链接：https://leetcode-cn.com/problems/gas-station

// 情况一：如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的

// 情况二：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。

// 情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能这个负数填平，能把这个负数填平的节点就是出发节点。
int main(){
    vector<int> gas;
    vector<int> cost;
    int n=0;
    scanf("%d",&n);
    for(int i = 0 ;i < n;i++){
        int t = 0;
        cin >> t;
        gas.push_back(t);
    } 
    for(int i = 0 ;i < n;i++) {
        int t = 0;
        cin >> t;
        cost.push_back(t);
    }
    int sum;
    //贪心算法 
    //若从i 到 j 的时候，恰好当前的车厢的油 tank < 0 ,这么说在i和j之间的站点都不能到达j
    for(int i = 0 ; i < n; i++){
        sum += gas[i] - cost[i];
    }
    if(sum < 0){
        //总油量小于总的消耗 ，无解
        return -1;
    } 
    //记录油箱中的油量
    int tank;
    //记录起点
    int start = 0;
    for(int i = 0 ; i < n;i++){
        tank += gas[i] - cost[i];
        if(tank <0){
            tank = 0;
            start = i + 1;
        }
    }
    start = start == n?0:start;
    cout << start << endl; 
    return 0;
}