#include<bits/stdc++.h>

using namespace std;

void mergearray(int a[],int first,int mid,int last,int temp[]){
    int k = 0;
    int k1 = mid,k2 = last;
    int i = first,j = mid+1;
    while(i<=mid && j <=last){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i<=k1){
        temp[k++] = a[i++];
    }
    while(j<=k2){
        temp[k++] = a[j++];
    }

    for(int i = 0 ; i < k;i++){
        a[first+i] = temp[i];
    }
}
void mergesort(int a[],int first,int end,int temp[]){
    if(first < end){
        int mid = (first+end)/2;
        mergesort(a,first,mid,temp);
        mergesort(a,mid+1,end,temp);
        mergearray(a,first,mid,end,temp);
    }
}


int main(){
    int temp[1000];
    int a[1000];
    cout << "Input you number nums" << endl;
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> a[i]; 
    }
    mergesort(a,0,n-1,temp);
    for(int i = 0 ; i < n;i++){
        cout << a[i] << " ";
    }
    return 0;
}