class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();

        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> reachedTime(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0}); // {time, row, col}

        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            int time = node[0], x = node[1], y = node[2];

            // Skip if we have already found a better way to this cell
            if (time >= reachedTime[x][y]) continue;

            // Update with the current shortest time
            reachedTime[x][y] = time;

            // If target is reached
            if (x == m - 1 && y == n - 1) return time;

            for (auto& dir : dirs) {
                int x_ = x + dir[0], y_ = y + dir[1];
                if (x_ >= 0 && y_ >= 0 && x_ < m && y_ < n) {
                    int nextTime = max(moveTime[x_][y_], time) + 1;
                    if (nextTime < reachedTime[x_][y_]) {
                        q.push({nextTime, x_, y_});
                    }
                }
            }
        }

        return -1; // If unreachable
    }
};
