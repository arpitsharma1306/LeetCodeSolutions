class Solution {
public:
    int digit_sum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }

        return sum;
    }
    typedef pair<int, int> P;
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int& num : nums) {
            int digits = digit_sum(num);
            pq.push({digits, num});
        }
        vector<int> result;
        while (!pq.empty()) {
            int ele = pq.top().second;
            pq.pop();
            result.push_back(ele);
        }

        std::unordered_map<int, std::vector<int>> valueIndices;

        // Record all positions of each value in B
        for (int i = 0; i < n; ++i) {
            valueIndices[result[i]].push_back(i);
        }

        // Build the target positions from A to B
        std::vector<int> targetPos(n);
        std::unordered_map<int, int> usedCount;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            targetPos[i] = valueIndices[val][usedCount[val]++];
        }

        // Count cycles in targetPos
        std::vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || targetPos[i] == i)
                continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = targetPos[j];
                ++cycleSize;
            }

            if (cycleSize > 1)
                swaps += (cycleSize - 1);
        }

        return swaps;
    }
};