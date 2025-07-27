class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        int i=-1,j=0;
        while(j<n-1){
            if(j>0 && nums[j-1]<nums[j] && nums[j]>nums[j+1]){
                count++;
                j++;
                continue;
            }else if(j>0 && nums[j-1]>nums[j] && nums[j]<nums[j+1]){
                count++;
                j++;
                continue;
            }
            
            if(nums[j]==nums[j+1]){
                int i=j-1;
                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;
                }
                if(i<0){
                    j++;
                    continue;
                }else if(j==n-1){
                    continue;
                }
                if((nums[i]>nums[j] && nums[j]<nums[j+1]) || (nums[i]<nums[j] && nums[j]>nums[j+1])){
                    count++;
                }
            }
            j++;
        }

        return count;
    }
};