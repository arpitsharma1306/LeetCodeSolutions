class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flated;
        bool even = true;
        for (int i = n - 1; i >= 0; i--) {
            if (even) {
                for (int j = 0; j < n; j++) {
                    flated.push_back(board[i][j]);
                }
                even = false;
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flated.push_back(board[i][j]);
                }
                even = true;
            }
        }

        int size = flated.size();
        queue<int> q;
        int cnt = 0;
        vector<bool> vis(size, false);
        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                if (node == size - 1) return cnt;
                for (int j = 1; j <= 6; j++) {
                    int next = node + j;
                    if (next < size) {
                        int dest = (flated[next] != -1) ? flated[next] - 1 : next;
                        if (!vis[dest]) {
                            q.push(dest);
                            vis[dest] = true;
                        }
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};
