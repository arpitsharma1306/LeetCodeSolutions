class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(vector<int>&nums,int idx,int parent){
        if(idx>=n) return 0;

        if(parent!=-1 && t[idx][parent]!=-1){
            return t[idx][parent];
        }

        int skip = solve(nums,idx+1,parent);
        int taken=0;
        if(parent==-1 || nums[idx]>nums[parent]){
            taken = solve(nums,idx+1,idx)+1;
        }

        if(parent!=-1) t[idx][parent]=max(skip,taken);

        return max(skip,taken);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};