class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); 
        int result = 0; // To store the total count of arithmetic slices

        // Array of unordered_maps, where mp[i] stores the count of arithmetic sequences
        // with a given difference ending at index i
        unordered_map<long, int> mp[n];

        // Iterate over all pairs of indices (i, j) with i > j
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Calculate the difference between nums[i] and nums[j]
                long diff = (long)nums[i] - nums[j];
                
                // Find the count of arithmetic subsequences with this difference ending at j
                auto it = mp[j].find(diff);
                int count_at_j = it == mp[j].end() ? 0 : it->second;

                // Add the count of sequences that extend the subsequences ending at j
                // Additionally, every pair (nums[j], nums[i]) can form a new sequence of length 2
                mp[i][diff] += count_at_j + 1;

                // Only add the count_at_j (sequences of length >= 3) to the result
                result += count_at_j;
            }
        }

        return result; // Return the total count of arithmetic slices
    }
};
