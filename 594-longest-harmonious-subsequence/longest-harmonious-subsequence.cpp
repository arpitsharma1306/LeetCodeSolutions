class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i=0,j=0;
        int len=0;
        while(j<nums.size()){
            if(nums[j]-nums[i]<=1){
                len++;
                if(nums[j]-nums[i]==1){
                    ans = max(ans,len);
                }
                j++;
            }else{
                len--;
                i++;
            }
        }

        return ans;
    }
};