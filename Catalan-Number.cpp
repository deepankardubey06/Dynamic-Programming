#include<iostream>
#include<vector>
using namespace std;
// using namespace boost::multiprecision;

void display(vector<int> &arr){
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

//TC :- O(n^2)
void findCatalan(int n){
    if(n < 2){
        // return 1;
    }
    vector<int> catalan(n+1, 0);
    catalan[0] = 1;
    catalan[1] = 1;
    for(int i=2 ; i<=n; i++){
        for(int j=i-1; j>=0; j--){
            catalan[i] += (catalan[j] * catalan[i - 1 - j]);
        }
    }
    display(catalan);
}

int main(){
    findCatalan(3);
    return 0;
}