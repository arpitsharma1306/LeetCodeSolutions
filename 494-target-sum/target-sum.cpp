class Solution {
public:
    int n;
    int S;
    int solve(vector<int>&nums,int target, int idx,int currSum,vector<vector<int>>&t){
        if(idx>=n){
            if(currSum==target) return 1;
            else return 0;
        }
        
        if(t[idx][currSum+S]!=-1){
            return t[idx][currSum+S];
        }
        int plus = solve(nums,target,idx+1,currSum+nums[idx],t);
        int minus = solve(nums,target,idx+1,currSum-nums[idx],t);

        return t[idx][currSum+S]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        S = accumulate(begin(nums),end(nums),0); // sum of the vector
        vector<vector<int>>t(n+1,vector<int>(2*S+1,-1));
        return solve(nums,target,0,0,t);
    }
};