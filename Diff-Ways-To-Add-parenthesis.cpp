#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool pureString(string &s, int i, int j){
    for(int k=0; k<=j; k++){
        if(s[k] == '*' || s[k] == '+' || s[k] == '-'){
            return false;
        }
    }
    return true;
}

int stoi1(string &s, int i, int j)
{
    int num = 0;
    for (int k = i; k <= j; k++)
    {
        num = num * 10 + (s[k] - '0');
    }
    return num;
}

vector<int> rec(string &s, int i, int j)
{
    vector<int> ans;
    for (int k = i; k <= j; k++)
    {
        if(s[k] == '+' || s[k] == '*' || s[k] == '-'){
            vector<int> v1 = rec(s, i, k - 1);
            vector<int> v2 = rec(s, k + 1, j);
            for (int m = 0; m < v1.size(); m++)
            {
                for (int n = 0; n < v2.size(); n++)
                {
                    if (s[k] == '-')
                    {
                        ans.push_back(v1[m] - v2[n]);
                    }
                    else if (s[k] == '*')
                    {
                        ans.push_back(v1[m] * v2[n]);
                    }
                    else
                    {
                        ans.push_back(v1[m] + v2[n]);
                    }
                }
            }
        }
    }
    if(ans.empty()){
        ans.push_back(stoi1(s,i,j));
    }
    return ans;
}

int main(){
    string s = "2-1-1";
    // s = "11*33";
    vector<int> ans = rec(s, 0, s.length()-1);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}