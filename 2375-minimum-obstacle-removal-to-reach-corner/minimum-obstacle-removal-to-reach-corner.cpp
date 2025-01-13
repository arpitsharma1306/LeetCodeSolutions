class Solution {
public:
    // Define a type alias for the priority queue elements
    using P = pair<int, pair<int, int>>;

    // Define the four possible movement directions: right, down, left, up
    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the result matrix with maximum integer values
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Min-heap priority queue to store {current_weight, {row, col}}
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from the top-left corner with 0 obstacles removed
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            pq.pop();
            int i = pos.first;
            int j = pos.second;

            // If we have reached the bottom-right corner, return the result
            if (i == m - 1 && j == n - 1) {
                return d;
            }

            // Explore all possible directions
            for (const auto& dir : dirs) {
                int x = i + dir.first;
                int y = j + dir.second;

                // Check if the new position is within grid boundaries
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newDist = d + grid[x][y];
                    // If a shorter path to (x, y) is found
                    if (newDist < result[x][y]) {
                        result[x][y] = newDist;
                        pq.push({newDist, {x, y}});
                    }
                }
            }
        }

        // If the bottom-right corner is unreachable, return -1
        return -1;
    }
};