#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int ans = 0;
bool isv(char G[N][N],int sx,int sy,int ex,int ey){
    set<char> s1;
    for (int i = sx ; i <= ex ; i++) {
        for (int j = sy; j <= ey ; j++) {
            if(s1.find(G[i][j]) != s1.end()) return false;
            else s1.insert(G[i][j]);
        }
    }
    return true;
};
int main() {
    char G[N][N];
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            for (int i1 = i; i1 < n ; i1++) {
                for (int j1 = j ; j < m ; j++) {
                    if(isv(G,i,j,i1,j1)) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}