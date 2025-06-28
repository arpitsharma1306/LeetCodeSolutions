class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        sort(rbegin(temp),rend(temp));
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[temp[i]]++;
        }
        
        temp.clear();

        for(int i=0;i<nums.size() && temp.size()<k;i++){
            if(mp.count(nums[i])){
                temp.push_back(nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
            }
        }

        return temp;
    }
};