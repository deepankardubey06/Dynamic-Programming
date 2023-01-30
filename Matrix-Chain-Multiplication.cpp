#include<iostream>
#include<vector>
using namespace std;

int mcm(int arr[], int i, int j){
    if(i > j || i == j){
        return 0;
    }
    int mini = INT_MAX;
    for(int k = i; k < j; k++){
        int cost = mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(mini, cost);
    }
    return mini;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    cout<<mcm(arr, 1, 4);
    return 0;
}