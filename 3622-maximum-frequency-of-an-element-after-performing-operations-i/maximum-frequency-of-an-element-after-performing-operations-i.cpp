class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = *max_element(nums.begin(),nums.end()) + k + 1;
        vector<int>f(n,0);
        vector<int>pre(n,0);
        for(int i=0;i<nums.size();i++) f[nums[i]]++;
        pre[0]=f[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + f[i];

        int ans = 0;
        for(int t=0;t<n;t++){
            if(f[t]==0 && numOperations==0) continue;
            int left = max(0,t-k), right = min(n-1,t+k);
            int total = pre[right] - (left>0?pre[left-1]:0);
            int adjust = total-f[t];
            int len = f[t]+min(numOperations,adjust);
            ans = max(ans,len);
        }

        return ans;
    }
};