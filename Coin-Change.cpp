#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<vector<int>> s;

void display(set<vector<int>> &s)
{
    for(auto i: s){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

//Backtracking Based Approach
void dfs(vector<int> &arr, int n, int val, int &count, int index){
    if (val == n){
        count++;
        return;
    }
    if(val > n || index >= arr.size()){
        return;
    }
    dfs(arr, n, val + arr[index], count, index);
    dfs(arr, n, val, count, index + 1);
}

int coinChange(vector<int> &coins, int amount){
    vector<vector<int>> table(coins.size() + 1, vector<int>(amount + 1));
    for (int i = 0; i < amount + 1; i++)
    {
        table[0][i] = INT_MAX - 1;
    }
    for (int i = 0; i < coins.size() + 1; i++)
    {
        table[i][0] = 0;
    }
    for (int i = 1; i < coins.size() + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] > j)
            {
                // Exclude
                table[i][j] = table[i - 1][j];
            }
            else
            {
                //Include
                table[i][j] = min(1 + table[i][j - coins[i - 1]], table[i - 1][j]);
            }
        }
    }
    return table[coins.size()][amount] > 1e4 || table[coins.size()][amount] < -1e4 ? -1 : table[coins.size()][amount];
}

int main(){
    vector<int> arr = {1, 2, 3};
    arr = {2, 5, 3, 6};
    arr = {1, 2, 5};
    arr = {2};
    arr = {5};
    vector<int> v; 
    int count = 0;
    cout<<coinChange(arr, 6);
    // cout<<1e4;
    // dfs(arr, 10, 0, count, 0);
    // display(s);
    // cout<<count;
    return 0;
}