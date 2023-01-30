#include<iostream>
#include<string.h>
using namespace std;

string rev(string s){
    string s1 = "";
    for(int i=s.length()-1; i>=0; i--){
        s1 += s[i];
    }
    return s1;
}

void rec(string s){
    if(s.length() == 1 || rev(s) == s){
        cout<<s<<" ";
        return;
    }
    for(int i=1; i<s.length(); i++){
        rec(s.substr(0, i));
        rec(s.substr(i, s.length()-i));
    }
}

int main(){
    rec("a");
    return 0;
}