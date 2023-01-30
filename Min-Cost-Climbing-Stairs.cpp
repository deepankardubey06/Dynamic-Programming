#include<iostream>
#include<vector>
using namespace std;

int dp[1000];

int dfs(vector<int> &cost, int index)
{
    if(index >= cost.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    dp[index] = min(cost[index] + dfs(cost, index + 1), cost[index] + dfs(cost, index + 2));
    return dp[index];
}

int dfs2(vector<int> &cost, int index)
{
    if (index == 0 || index == 1){
        return cost[index];
    }
    if(dp[index] != -1){
        return dp[index];
    }
    dp[index] = cost[index] + min(dfs2(cost, index - 1), dfs2(cost, index - 2));
    return dp[index];
}

int minCostClimbingStairs(vector<int> &cost){
    for(int i=0; i<1000; i++){
        dp[i] = -1;
    }
    return min(dfs(cost, 0), dfs(cost, 1));
}

int main(){
    vector<int> cost = {10, 15, 20, 0};
    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1, 0};
    // cout<<minCostClimbingStairs(cost);
    for (int i = 0; i < 1000; i++)
    {
        dp[i] = -1;
    }
    cout<<dfs2(cost, cost.size() - 1);
    return 0;
}