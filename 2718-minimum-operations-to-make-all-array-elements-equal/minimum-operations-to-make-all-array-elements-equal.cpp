class Solution {
public:
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vector<long long>ans;
        vector<long long>prefix(n+1);
        prefix[0]=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(long long q:queries){
            int idx = lower_bound(nums.begin(),nums.end(),q)-nums.begin();
            long long oper = 0;
            
            oper += ((long long)(q*idx) - prefix[idx]);
            oper += ((prefix[n]-prefix[idx]) - (long long)(q*(n-idx)));
            ans.push_back(oper);
        }

        return ans;
    }
};