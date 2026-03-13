#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(auto it: nums){
        cin>>it;
    }

    int ones = 0, twos = 0;

    for(int num: nums)
    {
        ones = (ones^num) & ~twos;
        twos = (twos^num) & ~ones;
    }
    cout << ones;
}