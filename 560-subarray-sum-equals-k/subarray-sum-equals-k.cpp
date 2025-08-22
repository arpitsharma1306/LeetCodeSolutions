class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        mp[sum] = 1;
        int cnt = 0;
        for(int& num:nums){
            sum+=num;
            if(mp[sum-k]>0)
                cnt+=mp[sum-k];
                
            mp[sum]++;
        }

        return cnt;


    }
};