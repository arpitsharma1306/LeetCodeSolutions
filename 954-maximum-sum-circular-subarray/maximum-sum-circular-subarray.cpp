class Solution {
public:
    int minSubarray(vector<int>& nums) {
        int curr_sum = 0;
        int mini = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            mini = min(mini, curr_sum);
            if (curr_sum > 0)
                curr_sum = 0;
        }
        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int array_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            array_sum += nums[i];
        }

        int curr_sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            maxi = max(maxi, curr_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }

        if(maxi>0) return max(maxi, (array_sum - minSubarray(nums)));
        else return maxi;
    }
};