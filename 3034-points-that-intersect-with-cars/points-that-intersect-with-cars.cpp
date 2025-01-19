class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> parking(101, 0); // Only need up to 100 indices
        for (const auto& num : nums) {
            parking[num[0]]++;
            if (num[1] + 1 <= 100) {
                parking[num[1] + 1]--;
            }
        }

        int count = 0, active = 0;
        for (int i = 1; i <= 100; ++i) {
            active += parking[i];
            if (active > 0) {
                count++;
            }
        }

        return count;
    }
};
