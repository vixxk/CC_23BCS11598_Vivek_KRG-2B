#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a, b);
        long long high = (long long)n * min(a, b);

        long long lcm = (long long)a * b / gcd(a, b);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long magicalCount =
                mid / a + mid / b - mid / lcm;

            if (magicalCount >= n)
                high = mid;
            else
                low = mid + 1;
        }

        return low % MOD;
    }
};
