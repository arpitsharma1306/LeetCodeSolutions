class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<long,int> mp[n];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long diff = (long)nums[i] - nums[j];
                mp[i][diff] += mp[j][diff] + 1;
                result += mp[j][diff];
            }
        }

        return result;


    }
};