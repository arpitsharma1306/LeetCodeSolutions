class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        int prev = 0;
        int largest = 1;
        int len = 1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                len++;
            }
            else{
                ans = max(ans,min(prev,len));
                prev=len;
                largest = max(largest,len);
                len=1;
            }
        }
        ans = max(ans,min(prev,len));
        largest = max(largest,len);
        ans = max(ans,largest/2);
        return ans;
    }
};