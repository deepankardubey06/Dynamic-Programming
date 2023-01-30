#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool ispalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int rec(string &s, int i, int j, vector<vector<int>> &dp){
    if(i >= j || ispalindrome(s, i, j)){
        return 0;
    }
    int mini = INT_MAX;
    for(int k=i+1; k<=j; k++){
        int temp = 1 + rec(s, i, k-1, dp) + rec(s, k, j, dp);
        mini = min(temp, mini);
    }
    return mini;
}

int main(){
    string s = "bbab";
    vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));
    cout << rec(s, 0, s.length()-1, dp);
    return 0;
}