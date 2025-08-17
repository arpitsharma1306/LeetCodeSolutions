class Solution {
public:
    int k;
    // DP State: [index][even_count][odd_count][remainder][tight_constraint]
    int dp[11][11][11][21][2];
    string s; // Use a class member for the string to avoid passing it repeatedly

    int solve(int idx, int even, int odd, int rem, bool tight, bool is_started) {
        // Base case: we have processed all digits
        if (idx == s.length()) {
            // A beautiful integer must have at least one digit (is_started),
            // have equal counts of even/odd digits, and be divisible by k.
            return is_started && even > 0 && even == odd && rem == 0;
        }

        // If this state is already computed, return the result
        if (dp[idx][even][odd][rem][tight] != -1) {
            return dp[idx][even][odd][rem][tight];
        }

        int res = 0;
        // Determine the upper limit for the current digit
        int limit = tight ? (s[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; ++digit) {
            // If we haven't started the number and the current digit is 0,
            // it's a leading zero. We continue to the next position without
            // updating counts or remainder.
            if (!is_started && digit == 0) {
                res += solve(idx + 1, even, odd, rem, tight && (digit == limit), false);
            } else {
                // Update counts and remainder for the new digit
                int new_even = even + (digit % 2 == 0);
                int new_odd = odd + (digit % 2 != 0);
                int new_rem = (rem * 10 + digit) % k;
                
                // The new tight constraint is true only if the original was tight
                // AND we are placing the highest possible digit.
                bool new_tight = tight && (digit == limit);

                res += solve(idx + 1, new_even, new_odd, new_rem, new_tight, true);
            }
        }

        return dp[idx][even][odd][rem][tight] = res;
    }

    int countBeautiful(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        // Initial call: index 0, 0 even, 0 odd, 0 remainder, tight constraint is true, not started
        return solve(0, 0, 0, 0, true, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k1) {
        k = k1;
        // The logic is to find count(high) - count(low - 1)
        int count_high = countBeautiful(high);
        int count_low = countBeautiful(low - 1);
        return count_high - count_low;
    }
};