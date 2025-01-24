class Solution {
public:
    int n;
    int t[5001][2]; // Memoization table, [i][0] for "can buy", [i][1] for "can sell"

    // Solve function to calculate maximum profit
    int solve(vector<int>& prices, int i, bool canBuy) {
        if (i >= n) return 0; // Base case: No more transactions possible

        if (t[i][canBuy] != -1) return t[i][canBuy]; // Return memoized result

        if (canBuy) {
            // Option 1: Buy at current index
            int buy = -prices[i] + solve(prices, i + 1, false);
            // Option 2: Skip buying
            int skip = solve(prices, i + 1, true);
            return t[i][canBuy] = max(buy, skip); // Take the better option
        } else {
            // Option 1: Sell at current index
            int sell = prices[i] + solve(prices, i + 2, true); // Move 2 days ahead due to cooldown
            // Option 2: Skip selling
            int skip = solve(prices, i + 1, false);
            return t[i][canBuy] = max(sell, skip); // Take the better option
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t)); // Initialize memoization table
        return solve(prices, 0, true); // Start from day 0, and we can buy initially
    }
};
