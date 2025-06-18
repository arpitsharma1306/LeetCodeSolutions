class Solution {
public:
    int MOD = 1e9+7; 
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        unordered_map<int,int>pairs;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!pairs.empty() && nums[i]%2==0 && pairs.count(nums[i]/2)){
                cnt = (cnt + pairs[nums[i]/2])%MOD;
            }
            if(!mp.empty() && mp.count(nums[i]*2)){
                pairs[nums[i]] = (pairs[nums[i]] + mp[nums[i]*2])%MOD;
            }
            mp[nums[i]]++;
        }

        return cnt;
    }
};