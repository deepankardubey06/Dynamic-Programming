#include<iostream>
#include<vector>
using namespace std;

int numTeams(vector<int> &rating)
{
    vector<int> gtm(rating.size());
    vector<int> ltm(rating.size());

    for (int i = rating.size() - 1; i >= 0; i--)
    {
        int count1 = 0;
        int count2 = 0;
        for (int j = i + 1; j < rating.size(); j++)
        {
            if (rating[j] > rating[i])
            {
                count1++;
            }
        }
        for (int j = i + 1; j < rating.size(); j++)
        {
            if (rating[j] < rating[i])
            {
                count2++;
            }
        }

        gtm[i] = count1;
        ltm[i] = count2;
    }

    int final_res = 0;

    for (int i = 0; i < rating.size() - 1; i++)
    {
        for (int j = i + 1; j < rating.size(); j++)
        {
            if (rating[j] > rating[i])
            {
                final_res += gtm[j];
            }
            if (rating[j] < rating[i])
            {
                final_res += ltm[j];
            }
        }
    }

    return final_res;
}

int main(){
    return 0;
}