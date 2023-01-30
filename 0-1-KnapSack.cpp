#include<iostream>
#include<vector>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
    if(n == 0 || W == 0){
        return 0;
    }
    else if(wt[n - 1] <= W){
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W , wt, val, n - 1));
    }
    else if(wt[n - 1] > W){
        return knapSack(W, wt, val, n - 1);
    }
}

int main(){
    int values[] = {1,2,3};
    int weight[] = {4,5,1};
    cout<<knapSack(4, weight, values, 3);
    return 0;
}