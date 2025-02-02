class Solution {
public:
    int dfs(vector<int>& nums,int idx,int currxor){
        if(idx==nums.size()) return currxor;

        int include = dfs(nums,idx+1,currxor^nums[idx]);
        int exclude = dfs(nums,idx+1,currxor);

        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums,0,0);
    }
};