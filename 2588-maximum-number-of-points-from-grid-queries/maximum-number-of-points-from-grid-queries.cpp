class Solution {
public:
    int m, n;
    int bfs(vector<vector<int>>& grid, int num, vector<vector<bool>>& visited) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        int count = 0;
        
        if (grid[0][0] < num) {
            q.push({0, 0});
            visited[0][0] = true;
            count++;
        } else {
            return 0;
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int x_ = x + dir[0], y_ = y + dir[1];
                if (x_ >= 0 && y_ >= 0 && x_ < m && y_ < n && !visited[x_][y_] && grid[x_][y_] < num) {
                    q.push({x_, y_});
                    visited[x_][y_] = true;
                    count++;
                }
            }
        }
        return count;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<pair<int, int>> sorted(k);
        for (int i = 0; i < k; i++) {
            sorted[i] = {queries[i], i};
        }
        sort(begin(sorted), end(sorted));

        vector<int> answer(k);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int total = 0;

        for (int i = 0; i < k; i++) {
            int num = sorted[i].first;
            while (!pq.empty() && pq.top().first < num) {
                auto [val, pos] = pq.top();
                auto [x, y] = pos;
                pq.pop();
                total++;
                vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
                for (auto& dir : dirs) {
                    int x_ = x + dir[0], y_ = y + dir[1];
                    if (x_ >= 0 && y_ >= 0 && x_ < m && y_ < n && !visited[x_][y_]) {
                        visited[x_][y_] = true;
                        pq.push({grid[x_][y_], {x_, y_}});
                    }
                }
            }
            answer[sorted[i].second] = total;
        }
        return answer;
    }
};