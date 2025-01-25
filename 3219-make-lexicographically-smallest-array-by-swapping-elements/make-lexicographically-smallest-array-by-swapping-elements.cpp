class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vec; 

        // Pair each element with its index and sort by values
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(begin(vec), end(vec));

        int l = 0;
        while (l < n) {
            int r = l + 1;

            // Identify the range where the absolute difference between adjacent values is within the limit
            while (r < n && abs(vec[r].first - vec[r - 1].first) <= limit) {
                r++;
            }

            // Collect indices of the current range and sort them
            vector<int> idxs;
            for (int i = l; i < r; i++) {
                idxs.push_back(vec[i].second);
            }
            sort(begin(idxs), end(idxs));

            // Assign sorted values to the sorted indices
            for (int i = 0; i < idxs.size(); i++) {
                nums[idxs[i]] = vec[l + i].first;
            }

            // Move to the next range
            l = r;
        }

        return nums;
    }
};
