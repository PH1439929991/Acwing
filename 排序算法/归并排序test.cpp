#include<bits/stdc++.h>

using namespace std;

void merge(int arr[],int left,int mid,int right){
    int temp[10];
    int t2 = mid + 1;
    int t1 = left;
    int num = 0;
    for(;t1 <= mid && t2 <= right;){
        if(arr[t1]>arr[t2]){
            temp[num++] = arr[t2++];
        }else{
            temp[num++] = arr[t1++];
        }
    }
    while(t1<=mid){
        temp[num++] = arr[t1++];
    }
    while(t2<=right){
        temp[num++] = arr[t2++];
    }

    for(int i = 0 ; i < num ; i++){
        arr[i+l] = temp[i];
    }
}

void mergesort(int arr[],int l,int r){
    if(l>=r) return;
    int mid = l + (r - l) / 2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main(){
    int n = 0;
    cin >> n;
    int arr[10] = {1,6,5,7,2,9,3,8,4,0};
    mergesort(arr,0,n-1);
    for(int i  = 0 ; i < 10 ; i++){
        cout << arr[i] << " ";
    }
}

