class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> reachedTime(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        reachedTime[0][0] = 0;
        q.push({0, 0, 0}); // {time, x, y}

        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            int time = node[0], x = node[1], y = node[2];

            // Already found a better path to (x, y)
            if (time > reachedTime[x][y]) continue;

            if (x == m - 1 && y == n - 1) return time;

            for (auto& dir : dirs) {
                int x_ = x + dir[0], y_ = y + dir[1];
                if (x_ >= 0 && y_ >= 0 && x_ < m && y_ < n) {
                    int extra = ((x_ + y_) % 2 == 0) ? 2 : 1;
                    int nextTime = max(moveTime[x_][y_], time) + extra;
                    if (nextTime < reachedTime[x_][y_]) {
                        reachedTime[x_][y_] = nextTime;
                        q.push({nextTime, x_, y_});
                    }
                }
            }
        }

        return -1; // If unreachable
    }
};
