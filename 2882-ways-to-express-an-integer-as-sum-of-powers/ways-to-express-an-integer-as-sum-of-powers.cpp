
class Solution {
public:
    static const int mod = 1000000007;

    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; ; i++) {
            long long val = 1;
            for (int k = 0; k < x; k++) val *= i;
            if (val > n) break;
            powers.push_back((int)val);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            for (int sum = n; sum >= p; sum--) {
                dp[sum] = (dp[sum] + dp[sum - p]) % mod;
            }
        }

        return dp[n];
    }
};