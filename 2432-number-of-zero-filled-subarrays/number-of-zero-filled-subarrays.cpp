class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long cnt = 0;
        int len = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                len++;
                cnt += len;
            }else{
                len=0;
            }
        }

        return cnt;
    }
};