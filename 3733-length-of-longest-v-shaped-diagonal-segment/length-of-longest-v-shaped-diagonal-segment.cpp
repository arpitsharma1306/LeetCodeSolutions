class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool check(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }

    bool sequence(int x_, int y_, int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] == 1) {
            return grid[x_][y_] == 2;
        } else if (grid[x][y] == 0) {
            return grid[x_][y_] == 2;
        } else if (grid[x][y] == 2) {
            return grid[x_][y_] == 0;
        }

        return false;
    }

    int rotateSolve(int x_dir, int y_dir, int x, int y,
                    vector<vector<int>>& grid) {
        int new_x_dir, new_y_dir;
        if (x_dir == -1 && y_dir == 1)
            new_x_dir = 1, new_y_dir = 1;
        else if (x_dir == 1 && y_dir == 1)
            new_x_dir = 1, new_y_dir = -1;
        else if (x_dir == 1 && y_dir == -1)
            new_x_dir = -1, new_y_dir = -1;
        else if (x_dir == -1 && y_dir == -1)
            new_x_dir = -1, new_y_dir = 1;

        int len = 0;
        int x_ = x + new_x_dir, y_ = y + new_y_dir;
        
        int par_x = x, par_y = y;
        while (check(x_, y_) && sequence(x_, y_, par_x, par_y, grid)) {
            len++;
            par_x = x_, par_y = y_;
            x_ = x_ + new_x_dir, y_ = y_ + new_y_dir;
        }

        return len;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        if(q.empty()) return 0;
        int maxlen = 1;

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto& dir : dirs) {
                int len = 1;
                int x_ = x + dir[0], y_ = y + dir[1];
                if (!check(x_, y_))
                    continue;
                int par_x = x, par_y = y;
                while (check(x_, y_) && sequence(x_, y_, par_x, par_y, grid)) {
                    len++;
                    int rotateLen =
                        rotateSolve(dir[0], dir[1], x_, y_, grid) + len;
                    maxlen = max(maxlen, rotateLen);
                    maxlen = max(maxlen, len);
                    par_x = x_, par_y = y_;
                    x_ = x_ + dir[0], y_ = y_ + dir[1];
                }
            }
        }

        return maxlen;
    }
};