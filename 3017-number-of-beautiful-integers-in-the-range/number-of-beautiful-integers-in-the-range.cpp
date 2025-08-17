class Solution {
public:
    int k;
    // dp[idx][rem][even][odd][tight][started]
    // idx <= 10 for 32-bit int; even, odd <= 10; rem < k (we size rem to 101 to be safe).
    int dp[11][101][11][11][2][2];
    string s;

    int solve(int idx, bool tight, int rem, int even, int odd, bool started) {
        if (idx == (int)s.size()) {
            // valid only if number started, divisible by k, and even==odd
            return (started && rem == 0 && even == odd);
        }

        int &memo = dp[idx][rem][even][odd][tight][started];
        if (memo != -1) return memo;

        int res = 0;
        char limit = tight ? s[idx] : '9';
        for (char c = '0'; c <= limit; ++c) {
            int d = c - '0';
            bool nt = tight && (c == limit);

            if (!started && d == 0) {
                // still skipping leading zeros; don't change rem/even/odd
                res += solve(idx + 1, nt, 0, 0, 0, false);
            } else {
                int nrem  = (rem * 10 + d) % k;
                int neven = even + (d % 2 == 0);
                int nodd  = odd  + (d % 2);
                res += solve(idx + 1, nt, nrem, neven, nodd, true);
            }
        }
        return memo = res;
    }

    int countUpTo(const string &num) {
        s = num;
        memset(dp, -1, sizeof(dp));
        return solve(0, true, 0, 0, 0, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k1) {
        k = k1;
        // guard: low-1 can be negative; to_string handles it, but we only count positives via `started`.
        int end   = countUpTo(to_string(high));
        int start = countUpTo(to_string(low - 1));
        return end - start;
    }
};
