class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        unordered_map<int,int>mp;
        mp[nums[0]]++;

        for(int j=1;j<n;j++){
            int countOfNumsj = mp[nums[j]-j];
            int totalNumsbeforej = j;
            int badPairs = totalNumsbeforej - countOfNumsj;
            result+=badPairs;

            mp[nums[j]-j]++;
        }

        return result;
    }
};