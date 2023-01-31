#include<iostream>
#include<vector>
using namespace std;

//Recursive approach without memoization
int rec(int i, vector<int> &arr, int k, int n){
    if(i == n){
        return 0;
    }
    int len = 0;
    int maxi = INT_MIN;
    int res = INT_MIN;
    for(int t = i; t < min((i + k),n); t++){
        len += 1;
        maxi = max(maxi, arr[t]);
        int sum = (len * maxi) + rec(t + 1, arr, k, n);
        res = max(res, sum);
    }
    return res;   
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    return rec(0, arr, k, arr.size());
}

int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout<< maxSumAfterPartitioning(arr, 3);
    return 0;
}