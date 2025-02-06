class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;

        sort(begin(nums),end(nums));
        int min1,min2,min3,min4;
        min1=nums[n-1]-nums[3];
        min2=nums[n-4]-nums[0];
        min3=nums[n-2]-nums[2];
        min4=nums[n-3]-nums[1];

        return min({min1,min2,min3,min4});
    }
};