#include<iostream>
#include<vector>
using namespace std;

bool subset(vector<int> &arr, int index, int sum){
    if (sum == 0)
    {
        return true;
    }
    if(sum < 0 || (index >= arr.size())){
        return false;
    }
    return (subset(arr, index + 1, sum - arr[index]) || subset(arr, index + 1, sum ));
}



bool isSubsetSum(vector<int> arr, int sum){
    //Create a 2d array
    bool dp[arr.size() + 1][sum + 1];

    //Initialize it's value
    for(int j=0; j<sum+1; j++){
        dp[0][j] = false;
    }

    for(int i=0; i<arr.size()+1; i++){
        dp[i][0] = true;
    }

    //Building a DP Array
    for(int i=1; i<arr.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (dp[i-1][j] || dp[i-1][j - arr[i-1]]);
            }
        }
    }
    return dp[arr.size()][sum];
}

int main(){
    vector<int> arr = {2,2,3};
    // cout<< subset(arr, 0, 5);
    // cout<<(0 || 1);
    cout<< isSubsetSum(arr, 5);
    return 0;
}