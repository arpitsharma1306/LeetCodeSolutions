class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q_sz = queries.size();

        // Sort queries based on the start index
        sort(queries.begin(), queries.end());

        // Difference array to track changes
        vector<int> diff(n + 1, 0);

        // Priority queue to manage queries (max-heap based on end index)
        priority_queue<int> pq;

        int sum = 0; // Tracks the current sum of the difference array
        int cnt = 0; // Counts the number of queries used
        int j = 0;   // Pointer to iterate through queries

        for (int i = 0; i < n; i++) {
            // Add all queries that start at or before the current index
            while (j < q_sz && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }

            // Process the difference array
            sum += diff[i];

            // While the current sum is less than nums[i], try to use queries
            while (sum < nums[i]) {
                if (pq.empty()) {
                    // No more queries to use
                    return -1;
                }

                int end = pq.top();
                pq.pop();

                if (end >= i) {
                    // Use this query
                    diff[i]++;
                    if (end + 1 < n) {
                        diff[end + 1]--;
                    }
                    sum++;
                    cnt++;
                }
            }
        }

        // Return the number of unused queries
        return q_sz - cnt;
    }
};