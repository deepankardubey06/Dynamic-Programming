#include<iostream>
#include<vector>

using namespace std;

int givetime(int r, int c, vector<vector<int>> &T){
    if(r < 0 || r>=T.size()){
        return 0;
    }
    return T[r][c];
}

int rec(int r, int c, vector<vector<int>> &a, vector<vector<int>> &T){
    if(r < 0 || r >= a.size()){
        return 10000;
    }
    if(c == a[0].size() - 1){
        return a[r][c];
    }
    int top = givetime(r, c+1, T) + rec(r-1, c+1, a, T);
    int same = rec(r, c+1, a, T);
    int down = givetime(r, c+1, T) + rec(r+1, c+1, a, T);
    return a[r][c] + min(top, same ,down);
}

int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
{
    for(int i=0; i<a.size(); i++){
        a[i][0] += e[i];
        a[i][a[i].size()-1] += x[i];
    }
    int mini = INT_MAX;
    for(int i=0; i<a.size(); i++){
        mini = min(mini, rec(i,0,a,T));
    }
    return mini;
}

int main(){
    
    return 0;
}