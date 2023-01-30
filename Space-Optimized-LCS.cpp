#include<iostream>
#include<vector>
using namespace std;

int tabulation(string s1, string s2){
    vector<vector<int>> table(2, vector<int>(s2.length() + 1));

    for (int i = 1; i <= s1.length() ; i++){
        for (int j = 1; j <= s2.length() ; j++){
            if (s1[i - 1] == s2[j - 1]){
                table[1][j] = 1 + table[0][j - 1];
            }
            else{
                table[1][j] = max(table[0][j], table[1][j - 1]);
            }
        }
        if(i < s1.length()){ swap(table[0], table[1]); }
    }

    return table[1][s2.length()];
}

int main(){
    tabulation("AGX", "ABX");
    return 0;
}