class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;

        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num); // Extend the subsequence
            } else {
                *it = num; // Replace the element to maintain the smallest
                           // possible values
            }
        }

        return dp.size();
    }
};