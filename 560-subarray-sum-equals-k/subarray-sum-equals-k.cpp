class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int val = nums[i];
            if(val==k) res++;
            for(int j=i+1;j<n;j++){
                val += nums[j];
                if(val==k) res++;
            }
        }

        return res;
    }
};