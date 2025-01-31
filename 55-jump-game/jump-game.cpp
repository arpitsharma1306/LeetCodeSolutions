class Solution {
public:
    vector<int>t;
    bool solve(vector<int>&nums,int n,int idx){
        if(idx>=n-1) return true;
        if(t[idx]!=-1) return t[idx];
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,n,idx+i)==true){
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        t.resize(n+1,-1);
        return solve(nums,n,0);
    }
};