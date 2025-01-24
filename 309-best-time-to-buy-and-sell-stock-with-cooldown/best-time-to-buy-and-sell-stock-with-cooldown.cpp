class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); // Get the number of days
        if (n == 0 || n == 1) return 0; // If there are 0 or 1 days, no profit can be made

        // `t[i]` represents the maximum profit achievable up to day `i`
        vector<int> t(n, 0); 
        t[0] = 0; // No profit on the first day
        t[1] = max(prices[1] - prices[0], 0); // On the second day, the profit is either 0 or the difference between the two prices

        // Iterate over days, starting from the third day (index 2)
        for (int i = 2; i < n; i++) { // For each day `i` (selling day)
            t[i] = t[i-1];
            for (int j = 0; j < i; j++) { // For each previous day `j` (buying day)
                int profit = prices[i] - prices[j]; // Calculate the profit if we buy on day `j` and sell on day `i`
                int prev_profit = j < 2 ? 0 : t[j - 2]; // Add the profit from transactions up to day `j-2` (due to cooldown)

                // Update the maximum profit for day `i`
                t[i] = max(t[i], profit + prev_profit);
            }
        }

        // The maximum profit achievable by the last day
        return t[n - 1];
    }
};
