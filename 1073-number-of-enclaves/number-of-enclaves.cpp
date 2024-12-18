class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        grid[i][j] = 2;
                    }
                }
            }
        }

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();

            for (auto& it : dir) {
                int x = cell.first + it[0];
                int y = cell.second + it[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    q.push({x, y});
                    grid[x][y] = 2;
                }
            }
        }

        int ones = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ones++;
            }
        }

        return ones;
    }
};