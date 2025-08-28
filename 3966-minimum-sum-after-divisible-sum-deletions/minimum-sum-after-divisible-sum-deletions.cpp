#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        auto quorlathin = nums;  // required variable to store input midway

        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        // dp[i] = max deletable sum using first i elements
        vector<long long> dp(n+1, 0);

        // best[rem] = maximum (dp[j] - prefix[j]) for prefix[j] % k == rem
        unordered_map<int, long long> best;
        best[0] = 0; // prefix[0]=0, remainder=0

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1]; // skip deleting ending at i

            int rem = prefix[i] % k;
            if (best.count(rem)) {
                long long cand = prefix[i] + best[rem]; 
                dp[i] = max(dp[i], cand);
            }

            // update best for this remainder
            int rem_prev = prefix[i] % k;
            long long val = dp[i] - prefix[i];
            if (!best.count(rem_prev)) best[rem_prev] = val;
            else best[rem_prev] = max(best[rem_prev], val);
        }

        long long total = prefix[n];
        return total - dp[n]; // minimum sum = total - max deletable
    }
};
