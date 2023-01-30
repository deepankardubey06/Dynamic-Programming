#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSubsequence(string s, string t){
    vector<int> order;
    vector<int> newvec;
    for(int i=0; i<s.length(); i++){
        if(t.find(s[i]) == -1){
            return false;
        }
        order.push_back(t.find(s[i]));
        t[t.find(s[i])] = 'Z';
    }
    newvec = order;
    sort(newvec.begin(), newvec.end());
    if(newvec == order){
        return true;
    }
    return false;
}

bool isSubsequence2(string s, string t){
    int i = t.length() - 1;
    int j = s.length() - 1;
    while(i > -1){
        if(t[i] == s[j]){
            j--;
        }
        i--;
    }
    return i == j;
}

int main(){
    string t = "baab";
    string s = "ab";
    cout<<isSubsequence2(s, t);
    // t[1] = 'z';
    // cout<<t;
    return 0;
}