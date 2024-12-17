class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int ori = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({sr, sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            for (auto& it : dir) {
                int x = cell.first + it[0];
                int y = cell.second + it[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                    image[x][y] == ori) {
                    image[x][y] = color;
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return image;
    }
};