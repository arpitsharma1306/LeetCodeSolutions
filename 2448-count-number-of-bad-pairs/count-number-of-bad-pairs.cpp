class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        unordered_map<int,int>mp;
        long long goodPairs=0;
        for(int i=0;i<n;i++){
            int num=nums[i]-i;
            goodPairs+=mp[num];
            mp[num]++;
        }

        return (n*(n-1))/2 - goodPairs;

    }
};