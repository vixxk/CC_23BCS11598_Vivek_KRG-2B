int diffBits(vector<int> arr) {
    const int MOD = 1e9 + 7;
    long long ans = 0;
    int n = arr.size();

    for (int i = 0; i < 32; i++) {
        long long ones = 0, zeros = 0;

        for (int j = 0; j < n; j++) {
            if ((arr[j] & (1 << i)) != 0)
                ones++;
            else
                zeros++;
        }

        ans = (ans + ones * zeros * 2) % MOD;
    }

    return ans;
}
