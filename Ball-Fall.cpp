//Leetcode 1706
#include<iostream>
#include<vector>
using namespace std;

int rec(int row, int col, vector<vector<int>> &grid)
{
    if (row == grid.size())
    {
        return col;
    }
    if (grid[row][col] == 1)
    {
        int next_col = col + 1;
        if (next_col < grid[0].size())
        {
            if (grid[row][next_col] == 1)
            {
                return rec(row + 1, next_col, grid);
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int prev_col = col - 1;
        if (prev_col >= 0)
        {
            if (grid[row][prev_col] == -1)
            {
                return rec(row + 1, prev_col, grid);
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

vector<int> findBall(vector<vector<int>> &grid)
{
    vector<int> res(grid[0].size());
    for (int i = 0; i < grid[0].size(); i++)
    {
        res[i] = rec(0, i, grid);
    }
    return res;
}

int main(){
    return 0;
}