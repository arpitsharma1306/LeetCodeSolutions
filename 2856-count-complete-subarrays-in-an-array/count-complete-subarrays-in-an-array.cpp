class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int>st;
        for(int& num:nums){
            st.insert(num);
        }
        int k=st.size();
        st.clear();
        int i=0, j=0;
        unordered_map<int,int>mp;

        for(;j<n;j++){
            mp[nums[j]]++;
            while(mp.size()==k){
                ans+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }

        return ans;
    }
};