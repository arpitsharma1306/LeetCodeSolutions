class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st; // To track distinct elements in the current window
        int i = 0, j = 0;
        long long maxSum = 0, currentSum = 0;

        while (j < n) {
            // Expand the window by adding nums[j]
            while (st.find(nums[j]) != st.end() || (j - i + 1 > k)) {
                // Remove elements to ensure all elements are distinct and within window size k
                st.erase(nums[i]);
                currentSum -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            currentSum += nums[j];

            // Check if the window has exactly k elements
            if (j - i + 1 == k) {
                maxSum = max(maxSum, currentSum);
            }
            j++;
        }

        return maxSum;
    }
};
