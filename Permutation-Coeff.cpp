#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int fac(int n){
    if(n == 0){
        return 1;
    }
    dp[n] = n * fac(n-1);
    return dp[n];
}

int permCoeff(int n, int k){
    //Edge Case
    if(k > n){
        return 0;
    }
    //Fill the dp array with 0's
    for(int i=0; i<n+1; i++){
        dp.push_back(0);
    }
    //Call Factorial of n recursively
    fac(n);

    //Compute the value stored in dp array nd return it
    return dp[n]/dp[n-k];
}

int main(){
    cout<< permCoeff(10,0);
    return 0;
}