#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int count = 1;  // 初始值为1，因为包括自身
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            cout << count << endl;
            count += dfs(neighbor);
        }
    }
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;
    graph.resize(N);
    visited.assign(N, false);
    cin.ignore();
    for (int i = 0; i < N; ++i) {
        string str = "";
        getline(cin,str);
        stringstream ss(str);
        int a;
        while (ss >> a)
        {
            graph[i].push_back(a-1);
        }            
    }
    cout << 2 << endl;  
    int affected_services = dfs(K - 1);
    cout << affected_services << endl;
    return 0;
}

