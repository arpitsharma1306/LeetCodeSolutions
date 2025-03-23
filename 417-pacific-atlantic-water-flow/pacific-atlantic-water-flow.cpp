class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();

        // Matrices to track reachable cells for Pacific and Atlantic oceans
        vector<vector<bool>> pacificReachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticReachable(m, vector<bool>(n, false));

        // Queues for BFS
        queue<pair<int, int>> pacificQueue, atlanticQueue;

        // Initialize queues with border cells
        for (int i = 0; i < m; i++) {
            pacificQueue.push({i, 0}); // Pacific border (left)
            atlanticQueue.push({i, n - 1}); // Atlantic border (right)
            pacificReachable[i][0] = true;
            atlanticReachable[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pacificQueue.push({0, j}); // Pacific border (top)
            atlanticQueue.push({m - 1, j}); // Atlantic border (bottom)
            pacificReachable[0][j] = true;
            atlanticReachable[m - 1][j] = true;
        }

        // Perform BFS for Pacific Ocean
        bfs(heights, pacificQueue, pacificReachable);

        // Perform BFS for Atlantic Ocean
        bfs(heights, atlanticQueue, atlanticReachable);

        // Collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& reachable) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int x = r + dir[0];
                int y = c + dir[1];

                // Check if the new cell is within bounds and can be reached
                if (x >= 0 && y >= 0 && x < m && y < n && !reachable[x][y] && heights[x][y] >= heights[r][c]) {
                    reachable[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
};