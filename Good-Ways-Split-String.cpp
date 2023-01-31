#include<iostream>
#include<map>
using namespace std;

int numSplits(string s)
{
    map<char, int> mp1;
    map<char, int> mp2;
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        mp1[s[i]] += 1;
    }

    for (int k = 0; k < s.length() - 1; k++)
    {
        mp2[s[k]] += 1;
        mp1[s[k]] -= 1;
        if (mp1[s[k]] == 0)
        {
            mp1.erase(s[k]);
        }
        if (mp1.size() == mp2.size())
        {
            count += 1;
        }
    }

    return count;
}

int main(){
    return 0;
}