class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        for(int i=n-1;i>=2;i--){
            if(nums[i]<(nums[i-1]+nums[i-2])){
                return (nums[i]+nums[i-1]+nums[i-2]);
            }
            else continue;
        }

        return 0;
    }
};