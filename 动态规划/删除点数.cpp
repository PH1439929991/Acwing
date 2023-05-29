#include<iostream>
#include"algorithm"
using namespace std;

//leectode 删除点数获取最高的点数  题号740
int res(int values[],int n){
    int first,second;
    first = values[0];
    second = max(values[0],values[1]);
    for(int i = 0 ; i <= n;i++){
        int temp = second;
        second = max(first+values[i],second);
        first = temp;
    } 
    return max(first,second);
}

int main(){
    int n = 0;
    cout << "Input the numbers of data" << endl;
    cin >> n;
    int nums[n];
    int Max;//输入的数字中最大的数
    for(int i = 0;i < n;i++){
        cin >> nums[i];
        if(nums[i]>Max) Max = nums[i];
    }
    sort(nums,nums+n);
    int Values[Max+1] = {0};//开创数组
    for(int i = 0 ; i < n ;i++){
            Values[nums[i]] += nums[i];
    }
    cout << res(Values,Max) << endl;
    return 0;
}