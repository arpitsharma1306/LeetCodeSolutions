class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        // Prefix sums to calculate cumulative values for rows
        vector<long long> PreL(n + 1, 0); // Prefix sum for the second row (bottom row)
        vector<long long> PreR(n + 1, 0); // Suffix sum for the first row (top row)

        // Compute prefix sum for the second row
        PreL[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            PreL[i] = PreL[i - 1] + grid[1][i];
        }

        // Compute suffix sum for the first row
        PreR[n - 1] = grid[0][n - 1];
        for (int i = n - 2; i >= 0; i--) {
            PreR[i] = PreR[i + 1] + grid[0][i];
        }

        // Find the optimal column to split the robot paths
        int l = 0, r = n - 1;
        while (l < r) {
            if (PreL[l] <= PreR[r]) {
                l++;
            } else {
                r--;
            }
        }

        // Modify the grid based on the split column
        for (int i = 0; i <= l; i++) {
            grid[0][i] = 0; // Zero out cells in the first row before or at the split
        }
        for (int i = l; i < n; i++) {
            grid[1][i] = 0; // Zero out cells in the second row after or at the split
        }

        // Calculate the remaining sum for both rows
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += grid[0][i];
            sum2 += grid[1][i];
        }

        // Return the maximum of the two sums
        return max(sum1, sum2);
    }
};
