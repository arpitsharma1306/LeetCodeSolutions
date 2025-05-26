class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26, 0)); // count[node][color]
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count[i][colors[i] - 'a'] = 1;
            }
        }

        int maxColor = 0;
        int visited = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            for (int nei : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    count[nei][c] = max(count[nei][c], count[node][c] + (colors[nei] - 'a' == c));
                }
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }

            maxColor = max(maxColor, *max_element(count[node].begin(), count[node].end()));
        }

        return visited == n ? maxColor : -1; // if not all nodes visited → cycle exists
    }
};
