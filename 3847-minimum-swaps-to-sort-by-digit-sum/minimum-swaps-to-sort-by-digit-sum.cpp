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

        // Build a min-heap based on (digit_sum, number)
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int num : nums) {
            pq.push({digit_sum(num), num});
        }

        // Sorted version of nums based on digit sum
        vector<int> sorted;
        while (!pq.empty()) {
            sorted.push_back(pq.top().second);
            pq.pop();
        }

        // Map each value in sorted array to its indices using a queue
        unordered_map<int, queue<int>> valueIndices;
        for (int i = 0; i < n; ++i) {
            valueIndices[sorted[i]].push(i);
        }

        // Create a position mapping from original array to sorted one
        vector<int> targetPos(n);
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            targetPos[i] = valueIndices[val].front();
            valueIndices[val].pop();
        }

        // Count minimum swaps by detecting cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || targetPos[i] == i) continue;

            int j = i, cycleSize = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = targetPos[j];
                ++cycleSize;
            }

            swaps += (cycleSize - 1);
        }

        return swaps;
    }
};
