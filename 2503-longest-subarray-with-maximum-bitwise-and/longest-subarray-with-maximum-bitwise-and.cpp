class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int size=1;
        int maxi=nums[0];
        int curr_size=1;
        for(int i=1;i<n;i++){
            if(nums[i]==maxi && nums[i]==nums[i-1]){
                curr_size++;
                size=max(size,curr_size);
                continue;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                curr_size=1;
                size=1;
                continue;
            }
            if(nums[i]==maxi){
                curr_size=1;
            }
        }

        return size;
    }
};