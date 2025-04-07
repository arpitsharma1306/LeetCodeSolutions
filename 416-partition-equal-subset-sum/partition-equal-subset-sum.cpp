class Solution {
public:
    int n;
    vector<vector<int>>t;
    bool solve(vector<int>& nums,int idx,int curr,int totalsum){
        if(idx>=n){
            if(totalsum-curr==curr){
                return true;
            }
            return false;
        }

        if(t[idx][curr]!=-1){
            return t[idx][curr];
        }

        bool taken = solve(nums,idx+1,curr+nums[idx],totalsum);
        bool skip =solve(nums,idx+1,curr,totalsum);

        return t[idx][curr] = taken | skip ;
    }

    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        t.resize(n,vector<int>(sum,-1));
        return solve(nums,0,0,sum);
    }
};