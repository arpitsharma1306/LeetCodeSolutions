class Solution {
public:
    bool solve(int num, int idx, vector<vector<int>>& queries, int m,
               int curr_idx, int sum, vector<vector<int>>& t) {
        if (sum == num)
            return true;
        if (sum > num || curr_idx >= m)
            return false;

        if (t[curr_idx][sum] != -1)
            return t[curr_idx][sum];

        int l = queries[curr_idx][0], r = queries[curr_idx][1],
            val = queries[curr_idx][2];

        bool taken = false, skip = false;

        if (l <= idx && r >= idx) {
            skip = solve(num, idx, queries, m, curr_idx + 1, sum, t);
            taken = solve(num, idx, queries, m, curr_idx + 1, sum + val, t);
        } else {
            skip = solve(num, idx, queries, m, curr_idx + 1, sum, t);
        }

        t[curr_idx][sum] = taken | skip;
        return t[curr_idx][sum];
    }

    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int m) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            vector<vector<int>> t(m + 1, vector<int>(num + 1, -1));
            bool zero_possible = solve(num, i, queries, m, 0, 0, t);
            if (zero_possible == false)
                return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size();
        int result = 0;
        bool allZero = all_of(nums.begin(), nums.end(), [](int x) {
        return x == 0;
        });
        if(allZero) return result;


        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, queries, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result==0? -1:result;
    }
};