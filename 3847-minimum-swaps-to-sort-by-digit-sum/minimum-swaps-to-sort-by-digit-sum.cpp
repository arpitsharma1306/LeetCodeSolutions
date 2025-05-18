class Solution {
public:
    using P = pair<int, int>;

    int digit_sum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Create and sort pairs (digit_sum, num)
        vector<P> temp;
        temp.reserve(n); // Pre-allocate memory
        for (int num : nums) {
            temp.emplace_back(digit_sum(num), num);
        }
        sort(temp.begin(), temp.end());

        // Extract sorted numbers
        vector<int> sorted;
        sorted.reserve(n);
        for (auto& p : temp) {
            sorted.push_back(p.second);
        }

        // Map each value to its indices in the sorted array
        unordered_map<int, vector<int>> val_to_indices;
        for (int i = 0; i < n; ++i) {
            val_to_indices[sorted[i]].push_back(i);
        }

        // Assign target positions using pointers
        unordered_map<int, int> val_to_ptr;
        vector<int> targetPos(n);
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            targetPos[i] = val_to_indices[val][val_to_ptr[val]++];
        }

        // Calculate minimum swaps using cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || targetPos[i] == i) continue;
            int cycleSize = 0;
            for (int j = i; !visited[j]; j = targetPos[j]) {
                visited[j] = true;
                ++cycleSize;
            }
            swaps += (cycleSize - 1);
        }

        return swaps;
    }
};