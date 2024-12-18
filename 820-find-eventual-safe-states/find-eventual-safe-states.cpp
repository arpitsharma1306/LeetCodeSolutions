class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> vis(n, 0);
        vector<int> indeg(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto& x : graph[i]) {
                indeg[i]++;
                adj[x].push_back(i);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int& x : adj[node]) {
                indeg[x]--;
                if (indeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};