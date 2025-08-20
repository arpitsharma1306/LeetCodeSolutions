class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(int idx,vector<int>&nums,int prev){
        if(idx>=n) return 0;
        
        if(t[idx][prev+1]!=-1) return t[idx][prev+1];

        int taken = 0, skip = 0;
        if(prev==-1 || nums[prev]<nums[idx]){
            taken = 1 + solve(idx+1,nums,idx);
        }
        skip = solve(idx+1,nums,prev);

        return t[idx][prev+1] = max(taken,skip); 
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        t.resize(n+1,vector<int>(n+2,-1));
        return solve(0,nums,-1);
        
    }
};