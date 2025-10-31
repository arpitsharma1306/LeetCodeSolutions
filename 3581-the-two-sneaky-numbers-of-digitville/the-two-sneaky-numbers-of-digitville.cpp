class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n-2,0);
        vector<int>ans;
        for(int &num:nums){
            if(vis[num]) ans.push_back(num);
            vis[num]=1;
        }

        return ans;
    }
};