class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        long long sum=0;
        long long maxSum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }

        if(mp.size()>=m) maxSum=sum;

        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            mp[nums[i-k]]--;
            mp[nums[i]]++;

            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }

            if(mp.size()>=m) maxSum=max(maxSum,sum);
        }

        return maxSum;
    }
};