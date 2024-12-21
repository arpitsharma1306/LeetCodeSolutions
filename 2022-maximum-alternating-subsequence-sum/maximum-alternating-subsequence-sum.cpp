class Solution {
public:
    int n;
    long long t[100001][2]; // 0 for odd 1 for even
    typedef long long ll;
    ll solve(vector<int>&nums,int idx,bool isEven){
        if(idx>=n) return 0;

        if(t[idx][isEven]!=-1){
            return t[idx][isEven];
        }

        ll skip = solve(nums,idx+1,isEven);

        int val = nums[idx];
        if(!isEven) val = -val;

        ll take = solve(nums,idx+1,!isEven) + val;

        return t[idx][isEven] = max(skip,take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,true);
    }
};