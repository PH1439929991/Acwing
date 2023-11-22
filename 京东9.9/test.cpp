#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
int n,k;
int maxScore(vector<int> numbers,int k){
    priority_queue<int> q(numbers.begin(),numbers.end());

    int score = 0;
    while(k > 0){
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        if(num1 - num2 <= k){
            score += num1 * num2;
        }
        q.push(num1 - num2);
        k--;
    }

    return score;
}

int main() {
    cin >> n >> k;
    vector<int> numbers(n,0);
    for(int i = 0 ; i < n ; i++) cin >> numbers[i];
    int ans = maxScore(numbers,k);
    cout << ans << endl;
    return 0;
}