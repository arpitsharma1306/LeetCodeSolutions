class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int sum=nums[0]^nums[1];
        for(int i=2;i<n;i++){
            sum^=nums[i];
        }

        return sum;
    }
};