class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int countPermutations(vector<int>& nums) {
        int n=nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        if(nums[0]!=mini) return 0;
        int cnt = 0;
        for(auto it:nums){
            if(it==mini) cnt++;
            if(cnt>1) return 0;
        }

        ll ans=1;
        for(int i=1;i<n;i++){
            ans = (ans*i) % MOD;
        }

        return ans;
    }
};