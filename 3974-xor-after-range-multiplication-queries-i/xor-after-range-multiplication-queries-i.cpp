class Solution {
public:
    const int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(auto &q:queries){
            int l=q[0], r=q[1], k=q[2];
            long long v=q[3];
            for(int i=l;i<=r;i+=k){
                nums[i] = (nums[i]*v)%mod;
            }
        }

        return  accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};