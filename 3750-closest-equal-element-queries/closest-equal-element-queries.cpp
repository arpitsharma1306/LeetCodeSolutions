class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Preprocess: map each number to its indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> answer;

        for (int query : queries) {
            int num = nums[query];
            vector<int>& indices = mp[num];

            // If the number appears only once, push -1
            if (indices.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            // Find the position of the query index in the indices vector
            auto it = lower_bound(indices.begin(), indices.end(), query);
            int idx = it - indices.begin();

            // Calculate left and right distances
            int left_dist, right_dist;

            if (idx == 0) {
                left_dist = (indices[0] - indices.back() + n) % n; // Circular distance
                right_dist = indices[1] - indices[0];
            } else if (idx == indices.size() - 1) {
                left_dist = indices[idx] - indices[idx - 1];
                right_dist = (indices[0] - indices[idx] + n) % n; // Circular distance
            } else {
                left_dist = indices[idx] - indices[idx - 1];
                right_dist = indices[idx + 1] - indices[idx];
            }

            // Push the minimum distance
            answer.push_back(min(left_dist, right_dist));
        }

        return answer;
    }
};