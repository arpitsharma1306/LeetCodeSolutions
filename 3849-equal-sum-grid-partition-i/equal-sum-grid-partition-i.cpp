class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;

        // Calculate total sum of the grid
        for (int row = 0; row < m; row++) {
            totalSum += accumulate(grid[row].begin(), grid[row].end(), 0LL);
        }

        // Try horizontal cut (row-wise)
        long long rowSum = 0;
        for (int row = 0; row < m - 1; row++) { // Cut only between rows
            rowSum += accumulate(grid[row].begin(), grid[row].end(), 0LL);
            if (rowSum * 2 == totalSum) return true;
        }

        // Try vertical cut (column-wise)
        vector<long long> colSum(n, 0);
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < m; row++) {
                colSum[col] += grid[row][col];
            }
        }

        long long sum = 0;
        for (int col = 0; col < n - 1; col++) { // Cut only between columns
            sum += colSum[col];
            if (sum * 2 == totalSum) return true;
        }

        return false;
    }
};
