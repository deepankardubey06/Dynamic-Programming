#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string sample;

void convertToBinary(int num){
    if(num == 1 || num == 0){
        sample += to_string(num);
        return;
    }
    int modResult = num % 2;
    sample += to_string(modResult);
    convertToBinary(num / 2);
}

int countOnes(){
    int count = 0;
    for(char i: sample){
        if(i == '1'){
            count += 1;
        }
    }
    return count;
}

int main(){
    vector<int> v;

    int n = 5;
    for(int i = 0; i <= n; i++){
        sample = "";
        convertToBinary(i);
        reverse(sample.begin(), sample.end());
        v.push_back(countOnes());
    }

    for(int i:v){
        cout<<i<<endl;
    }

    return 0;
}