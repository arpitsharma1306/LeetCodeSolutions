class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        std::list<int> v(nums.begin(), nums.end());
        int count = 0;

        while (!std::is_sorted(v.begin(), v.end())) {
            auto it1 = v.begin();
            auto it2 = std::next(it1);

            auto minIt1 = it1;
            auto minIt2 = it2;
            int minSum = *it1 + *it2;

            // Find adjacent pair with minimum sum
            while (it2 != v.end()) {
                int sum = *it1 + *it2;
                if (sum < minSum) {
                    minIt1 = it1;
                    minIt2 = it2;
                    minSum = sum;
                }
                ++it1;
                ++it2;
            }

            // Compute the sum *before* modifying the list
            int sum = *minIt1 + *minIt2;

            // Erase in correct order: minIt2 first, then minIt1
            // Because erasing minIt1 would invalidate minIt2
            v.erase(minIt2);
            auto insertPos = v.erase(minIt1); // erase minIt1 and get insert position
            v.insert(insertPos, sum);

            ++count;
        }

        return count;
    }
};
