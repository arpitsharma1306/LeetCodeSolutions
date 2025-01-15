class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>count(32,0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    count[i]++;
                }
            }
        }

        int ans = 0;
        // Reconstruct the single number from bits that are not multiples of 3
        for (int i = 0; i < 32; ++i) {
            if (count[i] % 3 != 0) {
                ans |= 1 << i;
            }
        }

        return ans;
    }
};