#include<bits/stdc++.h>
using namespace std;

const int N = 100001;

int main(){
    int n = 0;
    vector<int> res;
    cin >> n;
    while(n--){
        int x,y;
        cin >> x >> y;
        vector<vector<int>> a(x,vector<int>(y,0));
        for(int i = 0 ; i < x ; i++){
            for(int j = 0 ; j < y ;j++){
                cin >> a[i][j];
            }
        }
        int n = x;
        int m = y;
        vector<vector<int>> c(x,vector<int>(y,0));
        for(int i = 0 ; i < x ; i++){
            for(int j = 0 ; j < y ; j++){
                int row_max = INT16_MIN;
                int col_max = INT16_MIN;
                for(int k = 0 ; k < x;k++){
                    row_max = max(row_max,a[k][j]);
                }
                for(int k = 0 ; k < x;k++){
                    col_max = max(col_max,a[i][k]);
                }
                c[i][j] = min(row_max,col_max);
            }
        }
        int res = 0;
        for(vector<int> row : c){
            for(int num : row){
                if(num!=0) res++;
            }
        }
        if(res = 0) cout << -1 << endl;
        else cout << res << endl;
    }
}