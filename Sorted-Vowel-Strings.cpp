#include<iostream>
#include<vector>
using namespace std;

int count = 0;

void dfs(vector<char> &vc, int n, string s,int index){
    if(s.length() == n){
        count++;
        // cout<<s<<endl;
        return;
    }
    for(int i=index; i<vc.size(); i++){
        dfs(vc, n, s + vc[i], i);
    }
}

int main(){
    vector<char> vc = {'a', 'e', 'i', 'o', 'u'};
    dfs(vc, 50, "", 0);
    cout<<count;
    return 0;
}