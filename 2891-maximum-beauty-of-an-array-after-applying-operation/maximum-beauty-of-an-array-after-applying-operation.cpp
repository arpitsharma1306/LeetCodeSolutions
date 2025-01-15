class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        int result=0;
        int i=0,j=0;
        int count=0;
        while(j<n){
            if(nums[i]+k>=nums[j]-k){
                count++;
                result=max(result,count);
                j++;
            }else{
                i++;
                count--;
            }
        }

        return result;
    }
};