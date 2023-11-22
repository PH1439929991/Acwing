#include<bits/stdc++.h>

using namespace std;


string f(vector<int> &arr){
    int n = arr.size();
    bool is = true;
    for(int i = 0 ; i < n - 1 ;i++){
        if(arr[i] > arr[i+1]){
            is = false;
            break;
        }
    }

    if(is){
        return "YES";
    }

    for(int i = 0 ; i < n ; i++){
        int nextindex = (i+2)%n;
        if(arr[i]>arr[nextindex]){
            swap(arr[i],arr[nextindex]);
        }
        is = true;
        for(int i = 0 ; i < n - 1 ;i++){
            if(arr[i] > arr[i+1]){
                is = false;
                break;
            }
        }
        if(is){
            return "YES";
        }
    }

    return "NO";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0 ; i < n ;i++){
            cin >> arr[i];
        }

        string result = f(arr);
        cout << result << endl;
    }
    return 0;
}