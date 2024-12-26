class Solution {
public:
    int n;
    map<string,int>mp;
    int solve(vector<int>&nums,int target, int idx,int currSum){
        if(idx>=n){
            if(currSum==target) return 1;
            else return 0;
        }
        string key = to_string(idx)+"_"+to_string(currSum);
        if(mp.count(key)){
            return mp[key];
        }
        int plus = solve(nums,target,idx+1,currSum+nums[idx]);
        int minus = solve(nums,target,idx+1,currSum-nums[idx]);

        return mp[key]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        return solve(nums,target,0,0);
    }
};