class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;

        // DP table: dp[i][j] represents the minimum turns to print the substring s[i..j]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the DP table
        for (int len = 1; len <= n; len++) { // Length of substring
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1; // Endpoint of the substring

                dp[i][j] = dp[i + 1][j] + 1; // Initial assumption: one more turn than dp[i+1][j]
                
                // Check for matching characters within the substring
                for (int k = i + 1; k <= j; k++) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + (k + 1 <= j ? dp[k + 1][j] : 0));
                    }
                }
            }
        }

        return dp[0][n - 1]; // Minimum turns to print the entire string
    }
};
