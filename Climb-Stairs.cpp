#include<iostream>
#include<vector>
using namespace std;

int dp[1000];

int climbStair(int n){
    if(n <= 1){
        return 1;
    }
    if(dp[n]){
        return dp[n];
    }
    dp[n] = climbStair(n - 1) + climbStair(n - 2);
    return dp[n];
}

int main(){
    for(int i=0; i<1000; i++){ dp[i] = 0; }
    cout<<climbStair(5);
    return 0;
}