#include<iostream>
#include<vector>
using namespace std;

int rec(vector<vector<int>> &triangle, int r, int c){
    if(r >= triangle.size()-1 || c >= triangle[triangle.size()-1].size() - 1){
        return triangle[r][c];
    }
    int choice1 = rec(triangle, r + 1, c);
    int choice2 = rec(triangle, r + 1, c + 1);
    return triangle[r][c] + min(choice1, choice2);
}

int main(){
    vector<vector<int>> triangle = { {2}, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
    cout<< rec(triangle, 0 , 0);
    return 0;
}