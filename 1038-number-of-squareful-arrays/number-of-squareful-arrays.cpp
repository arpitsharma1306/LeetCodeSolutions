class Solution {
public:
    // Using member variables to avoid passing them in recursion
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> graph;
    int result = 0;
    int n;

    // The isPerfectSquare function is fine, but we can simplify it
    // since we only use it in one place.
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        int root = sqrt(num);
        return root * root == num;
    }

    void dfs(int u, int count) {
        // Base case: we have formed a valid permutation of length n
        if (count == n) {
            result++;
            return;
        }

        // Explore neighbors of the current number 'u'
        for (int v : graph[u]) {
            if (freq[v] > 0) {
                freq[v]--;         // "Visit" the node
                dfs(v, count + 1);
                freq[v]++;         // Backtrack
            }
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;
        
        // Step 1: Count the frequency of each number.
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Build an adjacency list (graph) where an edge exists
        // between two numbers if their sum is a perfect square.
        for (auto const& [u, u_count] : freq) {
            for (auto const& [v, v_count] : freq) {
                if (isPerfectSquare(u + v)) {
                    graph[u].push_back(v);
                }
            }
        }

        // Step 3: Start a DFS from each unique number to find all valid paths.
        for (auto const& [start_node, count] : freq) {
            freq[start_node]--;      // Start the path with this node
            dfs(start_node, 1);
            freq[start_node]++;      // Backtrack for the next starting path
        }

        return result;
    }
};