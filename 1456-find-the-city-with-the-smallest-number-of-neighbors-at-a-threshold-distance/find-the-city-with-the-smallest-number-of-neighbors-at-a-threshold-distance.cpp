class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int k = distanceThreshold;
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < n; i++) {
            pq.push({0, i});
            result[i][i] = 0;
            while (!pq.empty()) {
                int d = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for (auto& it : adj[node]) {
                    int adjnode = it.first;
                    int w = it.second;
                    if (d + w < result[i][adjnode]) {
                        result[i][adjnode] = d + w;
                        pq.push({d + w, adjnode});
                    }
                }
            }
        }

        int mini = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int city = 0;
            for (int j = 0; j < n; j++) {
                if (abs(result[i][i] - result[i][j]) <= k)
                    city++;
            }
            if (city <= mini) {
                mini = city;
                ans = i;
            }
        }

        return ans;
    }
};