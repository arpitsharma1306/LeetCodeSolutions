class Solution {
public:
    unordered_map<int, vector<int>> adj; // Adjacency list to represent the graph

    // Perform BFS to find the shortest path from node 0 to node n-1
    int bfs(int n) {
        queue<int> q;                    // Queue for BFS traversal
        q.push(0);                       // Start BFS from node 0
        vector<bool> visited(n, false);  // Keep track of visited nodes
        visited[0] = true;               // Mark the starting node as visited
        int level = 0;                   // Tracks the current level (distance)

        // BFS loop
        while (!q.empty()) {
            int sz = q.size();           // Number of nodes at the current level
            while (sz--) {
                int node = q.front();
                q.pop();

                if (node == n - 1)       // If we reach the destination node
                    return level;

                // Explore all neighbors of the current node
                for (int child : adj[node]) {
                    if (!visited[child]) {
                        q.push(child);
                        visited[child] = true; // Mark as visited
                    }
                }
            }
            level++;                     // Increment the distance level
        }

        return -1; // Return -1 if no path exists
    }

    // Main function to process queries and calculate shortest distances
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Pre-build the initial adjacency list for a default path 0 -> 1 -> ... -> n-1
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> result; // To store results for each query
        for (auto& query : queries) {
            int u = query[0]; // Source node of the new edge
            int v = query[1]; // Destination node of the new edge

            // Add the new edge (u -> v) to the graph
            adj[u].push_back(v);

            // Perform BFS to find the shortest distance after this update
            int d = bfs(n);
            result.push_back(d);
        }

        return result; // Return results for all queries
    }
};
