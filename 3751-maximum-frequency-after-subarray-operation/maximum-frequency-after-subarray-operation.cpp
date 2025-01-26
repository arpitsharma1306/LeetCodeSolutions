class Solution {
public:
    int calculate(vector<int>&nums, int value,int k){
        int curr_cnt=0;
        int max_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k) curr_cnt--;
            if(nums[i]==value) curr_cnt++;

            max_cnt=max(max_cnt,curr_cnt);
            if(curr_cnt<0) curr_cnt=0;
        }

        return max_cnt;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int max_frequency=0;

        for(auto& [value,_]:mp){
            max_frequency = max(max_frequency,calculate(nums,value,k));
        }

        return max_frequency+mp[k];
    }
};