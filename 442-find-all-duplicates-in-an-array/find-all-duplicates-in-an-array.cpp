class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }

        vector<int>ans;
        for(auto& it:mp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};