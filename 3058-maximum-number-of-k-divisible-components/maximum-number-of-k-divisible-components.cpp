class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& val, int k, int& count,
            int curr, int parent) {
        long long sum = val[curr];
        for (auto node : adj[curr]) {
            if (node != parent) {
                sum += dfs(adj, val, k, count, node, curr);
            }
        }
        sum %= k;
        if (sum == 0)
            count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        int count = 0;
        dfs(adj, values, k, count, 0, -1);
        return count;
    }
};