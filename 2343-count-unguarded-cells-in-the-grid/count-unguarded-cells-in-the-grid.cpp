class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark walls (2) and guards (-1) on the grid
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = -1;
        }

        // Mark guarded cells from each guard
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (auto& dir : dirs) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                while (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    if (grid[new_x][new_y] == 2 || grid[new_x][new_y] == -1) {
                        // Stop if a wall or another guard is encountered
                        break;
                    }
                    if (grid[new_x][new_y] == 0) {
                        // Mark as guarded (1)
                        grid[new_x][new_y] = 1;
                    }
                    new_x += dir[0];
                    new_y += dir[1];
                }
            }
        }

        // Count unguarded cells (value = 0)
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
