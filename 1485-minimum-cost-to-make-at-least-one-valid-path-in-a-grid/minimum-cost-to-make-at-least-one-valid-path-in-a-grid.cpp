class Solution {
public:
    int m, n;
    std::vector<std::vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::vector<int> dir_map = {0, 0, 1, 2, 3}; // Maps 1->0, 2->1, 3->2, 4->3

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int minCost(std::vector<std::vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        std::vector<std::vector<int>> costs(m, std::vector<int>(n, INT_MAX));
        costs[0][0] = 0;
        std::deque<std::vector<int>> dq;
        dq.push_front({0, 0, 0}); // {cost, x, y}

        while (!dq.empty()) {
            auto node = dq.front();
            dq.pop_front();
            int cost = node[0], x = node[1], y = node[2];

            if (x == m - 1 && y == n - 1) {
                return cost;
            }

            for (int i = 0; i < 4; ++i) {
                int new_x = x + dirs[i][0], new_y = y + dirs[i][1];
                if (isValid(new_x, new_y)) {
                    int path_cost = (dir_map[grid[x][y]] == i) ? 0 : 1;
                    if (cost + path_cost < costs[new_x][new_y]) {
                        costs[new_x][new_y] = cost + path_cost;
                        if (path_cost == 0) {
                            dq.push_front({costs[new_x][new_y], new_x, new_y});
                        } else {
                            dq.push_back({costs[new_x][new_y], new_x, new_y});
                        }
                    }
                }
            }
        }

        return -1;
    }
};