#include<iostream>
#include<vector>
using namespace std;

int rec(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int cut1 = INT_MIN, cut2 = INT_MIN, cut3 = INT_MIN;
    if(x <= n){
        cut1 = rec(n - x, x, y, z, dp);
    }
    if(y <= n){
        cut2 = rec(n - y, x, y, z, dp);
    }
    if(z <= n){
        cut3 = rec(n - z, x, y, z, dp);
    }
    return dp[n] = 1 + max(max(cut1, cut2), cut3);
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    return rec(n, x, y, z, dp);
}

int main(){
    cout<< maximizeTheCuts(5, 5, 3, 2);
    return 0;
}