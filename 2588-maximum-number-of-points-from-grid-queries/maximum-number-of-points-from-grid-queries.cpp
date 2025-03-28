#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int m, n;
    vector<int> parent;
    vector<int> size;

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (size[pu] < size[pv]) {
                swap(pu, pv);
            }
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size();
        n = grid[0].size();
        int k = queries.size();
        vector<int> answer(k, 0);

        // Flatten the grid and sort cells along with their coordinates
        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cells.emplace_back(grid[i][j], make_pair(i, j));
            }
        }
        sort(cells.begin(), cells.end());

        // Sort queries with their original indices
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Initialize DSU
        parent.resize(m * n);
        size.resize(m * n, 1);
        for (int i = 0; i < m * n; ++i) {
            parent[i] = i;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int total = 0;

        int cellIndex = 0;
        for (auto& query : sortedQueries) {
            int num = query.first;
            int idx = query.second;

            while (cellIndex < cells.size() && cells[cellIndex].first < num) {
                auto [val, pos] = cells[cellIndex];
                auto [x, y] = pos;
                int flatPos = x * n + y;
                visited[x][y] = true;

                // Check and unite with adjacent cells
                if (x > 0 && visited[x - 1][y]) {
                    unite(flatPos, (x - 1) * n + y);
                }
                if (x < m - 1 && visited[x + 1][y]) {
                    unite(flatPos, (x + 1) * n + y);
                }
                if (y > 0 && visited[x][y - 1]) {
                    unite(flatPos, x * n + (y - 1));
                }
                if (y < n - 1 && visited[x][y + 1]) {
                    unite(flatPos, x * n + (y + 1));
                }

                cellIndex++;
            }

            if (visited[0][0] && grid[0][0] < num) {
                answer[idx] = size[find(0)];
            } else {
                answer[idx] = 0;
            }
        }

        return answer;
    }
};