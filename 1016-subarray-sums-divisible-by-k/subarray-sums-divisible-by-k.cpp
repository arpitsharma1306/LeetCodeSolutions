class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        for(int& num:nums){
            prefix+=num;
            int mod=prefix%k;
            if(mod<0){
                mod += k;
            }
            if(mp.find(mod)!=mp.end()){
                count+=mp[mod];
            }
            mp[mod]++;
        }

        return count;
    }
};