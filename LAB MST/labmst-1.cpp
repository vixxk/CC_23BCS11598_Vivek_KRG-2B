#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    if(!(cin >> n)) return 0;
    vector<int> tokens(n);
    for(int i = 0; i < n; ++i) cin >> tokens[i];

    int power; cin >> power;

    sort(tokens.begin(), tokens.end());

    int l = 0, r = n - 1;
    int score = 0, maxScore = 0;

    while(l <= r)
    {
        if(power >= tokens[l]){
            power -= tokens[l++];
            ++score;
            maxScore = max(maxScore, score);
        }
         else if(score > 0){
            power += tokens[r--];
            --score;
        }
         else break;
    }

    cout << maxScore;
    return 0;
}