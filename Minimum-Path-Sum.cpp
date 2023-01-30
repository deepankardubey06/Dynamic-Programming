#include<iostream>
#include<vector>
using namespace std;

int rec(vector<vector<int>> &grid, int r, int c){
    if(r >= grid.size() || c >= grid[0].size()){
        return INT_MAX;
    }
    if(r == grid.size()-1 && c == grid[0].size()-1){
        return grid[grid.size()-1][grid[0].size()-1];
    }
    int bottom = rec(grid, r + 1, c);
    int right = rec(grid, r, c + 1);
    return grid[r][c] + min(bottom, right);
}

int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout<< rec(grid, 0, 0);
    return 0;
}