class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 3;

        priority_queue<long long> pq1; // max-heap for smallest m elements
        priority_queue<long long, vector<long long>, greater<long long>> pq2; // min-heap for largest m elements

        vector<long long> minSum(n, 0);
        vector<long long> maxSum(n, 0);

        long long leftSum = 0;
        for (int i = 0; i < m; ++i) {
            pq1.push(nums[i]);
            leftSum += nums[i];
        }
        minSum[m - 1] = leftSum;

        // From m to 2m - 1: keep m smallest from left
        for (int i = m; i < 2 * m; ++i) {
            pq1.push(nums[i]);
            leftSum += nums[i];
            leftSum -= pq1.top();
            pq1.pop();
            minSum[i] = leftSum;
        }

        long long rightSum = 0;
        for (int i = n - 1; i >= 2 * m; --i) {
            pq2.push(nums[i]);
            rightSum += nums[i];
        }
        maxSum[2 * m] = rightSum;

        // From 2m - 1 to m: keep m largest from right
        for (int i = 2 * m - 1; i >= m; --i) {
            pq2.push(nums[i]);
            rightSum += nums[i];
            rightSum -= pq2.top();
            pq2.pop();
            maxSum[i] = rightSum;
        }

        // Compute minimum difference
        long long result = LLONG_MAX;
        for (int i = m - 1; i < 2 * m; ++i) {
            result = min(result, minSum[i] - maxSum[i + 1]);
        }

        return result;
    }
};
