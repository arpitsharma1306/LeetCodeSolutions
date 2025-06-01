class Solution {
public:
    int n;
    unordered_map<string,bool> dp;
    bool solve(vector<int>& nums, long long target,int i,long long prod1,long long prod2){
        if(i>=n && prod1==target && prod2==target){
            return true;
        }
        if(i>=n) return false;
        if(prod1>target || prod2>target) return false;

        string key = to_string(i)+"_"+to_string(prod1);
        if(dp.count(key)) return dp[key];
        
        bool group1 = solve(nums,target,i+1,prod1*nums[i],prod2);
        bool group2 = solve(nums,target,i+1,prod1,prod2*nums[i]);

        return dp[key] = group1 | group2;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n=nums.size();
        dp.clear();
        return solve(nums,target,0,1,1);
    }
};