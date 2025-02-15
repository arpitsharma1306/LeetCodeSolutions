class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int MOD=sum%k;
            if(mp.find(MOD)!=mp.end()){
                int idx=mp[MOD];
                if(i-idx>=2) return true;
            }else{
                mp[MOD]=i;
            }
        }

        return false;
    }
};