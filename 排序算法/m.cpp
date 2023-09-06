#include<iostream>
using namespace std;
void Merge(int *array,int low,int mid,int high){//array[low,mid),array[mid,high)->array[low,high)
    int *temp=new int[high-low];
    int i=low;
    int j=mid;
    int count=0;
    while(i<mid&&j<high){
        if(array[i]<=array[j]){
            temp[count++]=array[i++];
        }
        else{
            temp[count++]=array[j++];
        }
    }
    while(i<mid) temp[count++]=array[i++];
    while(j<high)temp[count++]=array[j++];
    for(int i=0;i<high-low;i++){
        array[low+i]=temp[i];
    }
}
void MergeSort(int *array,int low,int high){//array[low,high)
    if(high-low<=1)return;
    int mid=(low+high)/2;
    MergeSort(array,low,mid);
    MergeSort(array,mid,high);
    Merge(array,low,mid,high);
}
int main(){
    int array[5]={1,5,3,4,9};
    MergeSort(array,0,5);
    for(auto a:array)cout<<a;
    return 0;
}