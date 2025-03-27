#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        int maxFreq = 0, maxElement = nums[0];

        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                maxElement = num;
            }
        }

        int leftCount = 0, rightCount = maxFreq;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == maxElement) {
                leftCount++;
                rightCount--;
            }

            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
