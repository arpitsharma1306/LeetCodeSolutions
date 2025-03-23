class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=1;
        for(int i=0;i<n;i++){
            if(nums[i]<1) continue;
            if(j==nums[i]){
                j++;
            }else if(j>nums[i]){
                continue;
            }else{
                return j;
            }

        }

        if(nums[n-1]<=0) return 1;
        return nums[n-1]+1;
    }
};