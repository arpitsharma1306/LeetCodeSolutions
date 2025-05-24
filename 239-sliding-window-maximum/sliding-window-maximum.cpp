class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int i=0;
        vector<int>res;
        while(i<k){
            mp[nums[i]]++;
            i++;
        }
        int maxi=mp.rbegin()->first;
        res.push_back(maxi);
        for(;i<n;i++){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            maxi=mp.rbegin()->first;
            res.push_back(maxi);
        }
        return res;
    }
};