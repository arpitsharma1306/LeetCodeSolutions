class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long>>t(n+1,vector<long>(2,0)); //0:even 1:odd

        for(int i=1;i<n+1;i++){
            //even length then last element odd position par hoga so -
            t[i][0] = max(t[i-1][1]-nums[i-1],t[i-1][0]);
            //odd length then last element even position par hoga so +
            t[i][1] = max(t[i-1][0]+nums[i-1],t[i-1][1]);
        }

        return max(t[n][0],t[n][1]);
    }
};