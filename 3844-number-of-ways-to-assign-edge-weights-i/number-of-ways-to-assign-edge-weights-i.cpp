#define mod 1000000007
class Solution {
public:
    int maxh;
    void dfs(unordered_map<int, vector<int>>& adj, int h, int node,
             int parent) {
        maxh = max(maxh, h);
        for (auto& child : adj[node]) {
            if (child != parent)
                dfs(adj, h + 1, child, node);
        }
    }
    long long int power(long long int m, long long int n) {
        long long int ans = 1;
        while (n > 0) {
            if (n % 2) {
                ans = ans * m;
                ans = ans % mod;
            }
            m = m * m;
            m = m % mod;
            n /= 2;
        }
        return ans % mod;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        maxh = 0;
        dfs(adj, 0, 1, -1);

        return power(2, maxh - 1) % mod;
    }
};