#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int nCr(int n, int r){
    if (r > n)
    {
        return 0;
    }
    vector<int> dp(r + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            dp[j] = (dp[j] + dp[j - 1]) % 1000000007;
        }
    }
    return dp[r];
}

int main(){
    cout<< nCr(15,3);
    return 0;
}