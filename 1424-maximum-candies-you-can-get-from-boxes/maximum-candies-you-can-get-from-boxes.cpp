class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        int total = 0;

        queue<int> q;
        vector<bool> hasKey(n, false);
        vector<bool> visited(n, false);
        unordered_set<int> closedBoxes;

        for (int idx : initialBoxes) {
            if (status[idx] == 1) {
                q.push(idx);
                visited[idx] = true;
            } else {
                closedBoxes.insert(idx);
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            total += candies[box];

            // Acquire new keys and open boxes if needed
            for (int k : keys[box]) {
                hasKey[k] = true;
                if (closedBoxes.count(k)) {
                    q.push(k);
                    visited[k] = true;
                    closedBoxes.erase(k);
                }
            }

            // Open contained boxes
            for (int b : containedBoxes[box]) {
                if (visited[b]) continue;

                if (status[b] == 1 || hasKey[b]) {
                    q.push(b);
                    visited[b] = true;
                } else {
                    closedBoxes.insert(b);
                }
            }
        }

        return total;
    }
};
