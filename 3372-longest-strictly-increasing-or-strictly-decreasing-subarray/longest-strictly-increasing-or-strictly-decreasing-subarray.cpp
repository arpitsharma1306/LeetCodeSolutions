class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int result=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) count++;
            else count=1;

            result=max(result,count);
        }
        count=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) count++;
            else count=1;

            result=max(result,count);
        }

        return result;
    }
};