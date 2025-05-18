#include <vector>
#include <string>
#include <deque>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        if (m == 0) return -1;
        int n = matrix[0].size();
        if (n == 0) return -1;

        // Early check for blocked start or end
        if (matrix[0][0] == '#' || matrix[m-1][n-1] == '#') return -1;

        vector<vector<pair<int, int>>> freq(26);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = matrix[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    freq[ch - 'A'].emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<tuple<int, int, int>> q;

        q.emplace_front(0, 0, 0);
        dist[0][0] = 0;

        while (!q.empty()) {
            auto [x, y, cost] = q.front();
            q.pop_front();

            // Early exit if destination is reached
            if (x == m-1 && y == n-1) return cost;

            // Skip if a better path was already found
            if (cost > dist[x][y]) continue;

            // Teleportation handling
            char ch = matrix[x][y];
            if (ch >= 'A' && ch <= 'Z') {
                for (auto& [nx, ny] : freq[ch - 'A']) {
                    if (dist[nx][ny] > cost) {
                        dist[nx][ny] = cost;
                        q.emplace_front(nx, ny, cost);
                    }
                }
                freq[ch - 'A'].clear(); // Prevent reuse
            }

            // Explore neighbors
            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] != '#') {
                    if (dist[nx][ny] > cost + 1) {
                        dist[nx][ny] = cost + 1;
                        q.emplace_back(nx, ny, cost + 1);
                    }
                }
            }
        }

        return -1; // Unreachable if exit occurs correctly
    }
};